#include <iostream>
#include <vector>
#include <string.h>
#include <limits>

using namespace std;

const int kMaxN = 410000;

struct DirectedEdge {
  int target;
  int64_t length;
};

struct Node {
  int id;
  vector<DirectedEdge> edges;
  bool in_the_loop = true;
  int64_t max_depth = -1;
  int64_t second_max_depth = -1;
};

struct LoopNode {
  int64_t distance_to_first_node = 0;
  int64_t max_depth;
};

struct State {
  int64_t max_offset1;
  int64_t max_offset2;
  int64_t max_sum;
  State Merge(const State& other) {
    State combined;
    combined.max_offset1 = max(max_offset1, other.max_offset1);
    combined.max_offset2 = max(max_offset2, other.max_offset2);
    combined.max_sum = max(max(max_sum, other.max_sum), max_offset1 + other.max_offset2);
    return combined;
  }
};

struct SegmentTreeNode {
  int start;
  int end;
  int64_t max_offset1;
  int64_t max_offset2;
  int64_t max_sum;
  SegmentTreeNode* left_child;
  SegmentTreeNode* right_child;

  SegmentTreeNode(int s, int t);
  State GetState(int s, int t);
};


int n;
Node nodes[kMaxN];
int64_t current_result;
int loop_length;
LoopNode loops[kMaxN];
SegmentTreeNode* root;

SegmentTreeNode::SegmentTreeNode(int s, int t) {
  start = s;
  end = t;
  if (start == end) {
    max_offset1 = loops[s].max_depth - loops[s].distance_to_first_node;
    max_offset2 = loops[s].max_depth + loops[s].distance_to_first_node;
    max_sum = 0;
    left_child = nullptr;
    right_child = nullptr;
  } else {
    int middle = (start + end) / 2;
    left_child = new SegmentTreeNode(start, middle);
    right_child = new SegmentTreeNode(middle + 1, end);
    max_offset1 = max(left_child->max_offset1, right_child->max_offset1);
    max_offset2 = max(left_child->max_offset2, right_child->max_offset2);
    max_sum = max(max(left_child->max_sum, right_child->max_sum), left_child->max_offset1 + right_child->max_offset2);
  }
}

State SegmentTreeNode::GetState(int s, int t) {
  if (s <= start && t >= end) {
    return {max_offset1, max_offset2, max_sum};
  }
  int middle = (start + end) / 2;
  if (middle >= t) {
    return left_child->GetState(s, t);
  } else if (middle < s) {
    return right_child->GetState(s, t);
  } else {
    return left_child->GetState(s, t).Merge(right_child->GetState(s, t));
  }
}


void AddOneEdge(int u, int v, int l) {
  nodes[u].edges.push_back({v, l});
  nodes[v].edges.push_back({u, l});
}

void TrimToCircle() {
  vector<int> degree(n);
  vector<int> queue;
  for (int i = 0; i < n; ++i) {
    degree[i] = nodes[i].edges.size();
    if (degree[i] == 1) {
      queue.push_back(i);
    }
  }
  for (int close = 0; close < queue.size(); ++close) {
    int id = queue[close];
    nodes[id].in_the_loop = false;
    for (const auto& edge : nodes[id].edges) {
      --degree[edge.target];
      if (degree[edge.target] == 1) {
        queue.push_back(edge.target);
      }
    }
  }
}

void DepthFirstSearch(int id) {
  nodes[id].max_depth = 0;
  nodes[id].second_max_depth = 0;
  for (const auto& edge : nodes[id].edges) {
    if (!nodes[edge.target].in_the_loop && nodes[edge.target].max_depth < 0) {
      DepthFirstSearch(edge.target);
      int64_t depth = nodes[edge.target].max_depth + edge.length;
      if (depth > nodes[id].max_depth) {
        nodes[id].second_max_depth = nodes[id].max_depth;
        nodes[id].max_depth = depth;
      } else {
        nodes[id].second_max_depth = max(nodes[id].second_max_depth, depth);
      }
    }
  }
  current_result = max(current_result, nodes[id].max_depth + nodes[id].second_max_depth);
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    nodes[i].id = i;
  }
  for (int i = 0; i < n; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    --u;
    --v;
    AddOneEdge(u, v, l);
  }
  TrimToCircle();
  current_result = 0;
  for (int i = 0; i < n; ++i) {
    if (nodes[i].in_the_loop && nodes[i].max_depth < 0) {
      DepthFirstSearch(i);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (nodes[i].in_the_loop) {
      loop_length = 0;
      int current_id = i;
      int previous_id = -1;
      int64_t accumulated_distance = 0;
      while (1) {
        loops[loop_length].distance_to_first_node = accumulated_distance;
        loops[loop_length].max_depth = nodes[current_id].max_depth;
        ++loop_length;
        const DirectedEdge* next_edge = nullptr;
        for (const auto& edge : nodes[current_id].edges) {
          if (nodes[edge.target].in_the_loop && edge.target != previous_id) {
            next_edge = &edge;
            break;
          }
        }
        if (next_edge->target == i) {
          accumulated_distance += next_edge->length;
          break;

        }
        previous_id = current_id;
        current_id = next_edge->target;
        accumulated_distance += next_edge->length;
      }
      for (int i = 0; i < loop_length; ++i) {
        loops[loop_length + i] = loops[i];
        loops[loop_length + i].distance_to_first_node += accumulated_distance;
      }
      break;
    }
  }
  root = new SegmentTreeNode(0, loop_length + loop_length - 1);
  int64_t results = numeric_limits<int64_t>::max();
  for (int i = 0; i < loop_length; ++i) {
    State state = root->GetState(i, i + loop_length - 1);
    results = min(results, max(current_result, state.max_sum));
  }
  cout << results << endl;
  return 0;
}