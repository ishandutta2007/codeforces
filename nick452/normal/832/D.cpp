#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

const int kMaxn = 100000;
const int kMaxNumQueries = 100000;

struct LCAQuery {
  LCAQuery() = default;
  LCAQuery(int a, int b) : a(a), b(b) {}
  int a;
  int b;
  int lca;
};
struct Query {
  int a;
  int b;
  int c;
};
struct Node {
  int id;
  vector<int> edges;
  int link;
  int depth;
  vector<LCAQuery*> lca_queries;
  bool is_explored;

  int GetLink();
};

int n;
Node nodes[kMaxn];
int num_queries;
Query queries[kMaxNumQueries];
LCAQuery lca_queries[kMaxNumQueries * 3];

int Node::GetLink() {
  if (link == id) {
    return id;
  }
  link = nodes[link].GetLink();
  return link;
}

void AddEdge(int a, int b) {
  nodes[a].edges.push_back(b);
  nodes[b].edges.push_back(a);
}

void DepthFirstSearch(int node_id) {
  nodes[node_id].is_explored = true;
  for (LCAQuery* lca_query : nodes[node_id].lca_queries) {
    int other_node_id = (lca_query->a == node_id ? lca_query->b : lca_query->a);
    if (nodes[other_node_id].is_explored) {
      lca_query->lca = nodes[other_node_id].GetLink();
    }
  }
  for (int subnode_id : nodes[node_id].edges) {
    if (nodes[subnode_id].is_explored) {
      continue;
    }
    nodes[subnode_id].depth = nodes[node_id].depth + 1;
    DepthFirstSearch(subnode_id);
    nodes[subnode_id].link = node_id;
  }
}

int main() {
  cin.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> num_queries;
  for (int i = 1; i < n; ++i) {
    int p;
    cin >> p;
    AddEdge(i, p - 1);
  }
  for (int i = 0; i < num_queries; ++i) {
    cin >> queries[i].a >> queries[i].b >> queries[i].c;
    --queries[i].a;
    --queries[i].b;
    --queries[i].c;
    lca_queries[i * 3] = LCAQuery(queries[i].a, queries[i].b);
    lca_queries[i * 3 + 1] = LCAQuery(queries[i].b, queries[i].c);
    lca_queries[i * 3 + 2] = LCAQuery(queries[i].c, queries[i].a);
  }
  for (int i = 0; i < num_queries * 3; ++i) {
    nodes[lca_queries[i].a].lca_queries.push_back(&lca_queries[i]);
    nodes[lca_queries[i].b].lca_queries.push_back(&lca_queries[i]);
  }
  for (int i = 0; i < n; ++i) {
    nodes[i].id = i;
    nodes[i].link = i;
    nodes[i].is_explored = false;
  }
  nodes[0].depth = 0;
  DepthFirstSearch(0);
  for (int i = 0; i < num_queries; ++i) {
    int distance_a_b = nodes[queries[i].a].depth + nodes[queries[i].b].depth - 2 * nodes[lca_queries[i * 3].lca].depth;
    int distance_b_c = nodes[queries[i].b].depth + nodes[queries[i].c].depth - 2 * nodes[lca_queries[i * 3 + 1].lca].depth;
    int distance_c_a = nodes[queries[i].c].depth + nodes[queries[i].a].depth - 2 * nodes[lca_queries[i * 3 + 2].lca].depth;
    int sum = (distance_a_b + distance_b_c + distance_c_a) / 2;
    printf("%d\n", sum - min(min(distance_a_b, distance_b_c), distance_c_a) + 1);
  }
  return 0;
}