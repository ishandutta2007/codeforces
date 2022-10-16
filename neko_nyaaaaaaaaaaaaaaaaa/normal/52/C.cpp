#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000000000;

vector<int> parse_line() {
  int temp;
  vector<int> res;
  string line; getline(cin, line);
  istringstream input{line};
  while (input >> temp) {
    res.push_back(temp);
  }
  return res;
}

void build_tree(vector<int> &v, vector<long long> &seg_tree, int left, int right, int index) {
  if (left == right) {
    seg_tree[index] = v[left];
    return;
  }
  int mid = (left + right) / 2;
  build_tree(v, seg_tree, left, mid, 2 * index + 1);
  build_tree(v, seg_tree, mid + 1, right, 2 * index + 2);
  seg_tree[index] = min(seg_tree[2 * index + 1], seg_tree[2 * index + 2]); 
}

void push(vector<long long> &seg_tree, vector<long long> &lazy, int left, int right, int index) {
  if (lazy[index] != 0) {
    seg_tree[index] += lazy[index]; // update the current node
    if (left != right) { // propagate to the 2 children nodes
      lazy[2 * index + 1] += lazy[index];
      lazy[2 * index + 2] += lazy[index];
    }
    // pending update resolved --> clear pending update
    lazy[index] = 0;
  }
}

void update(vector<long long> &seg_tree, vector<long long> &lazy, int left, int right, int index, int a, int b, int val) {
  // there is pending update ---> resolve pending updates
  push(seg_tree, lazy, left, right, index);
  
  // completely outside a, b
  if (right < a || left > b)  {
    return;
  }
  
  // [left, right] complete inside [a, b]
  if (a <= left && right <= b) { // [left, right] complete inside [a, b]
    // lazy update ---> update on lazy tree ("pending" update)
    lazy[index] += val;
    push(seg_tree, lazy, left, right, index);
    return;
  }
  
  // overlaps
  int mid = (left + right) / 2;
  update(seg_tree, lazy, left, mid, 2 * index + 1, a, b, val);
  update(seg_tree, lazy, mid + 1, right, 2 * index + 2, a, b, val);
  seg_tree[index] = min(seg_tree[2 * index + 1], seg_tree[2 * index + 2]);
}

/*
  Query: [a, b]
  - [left right] completely outside [a, b] --> return INF
  - [left right] completely inside [a, b] --> return node 
  - min(recur, recur)
  10^6 + 10^6 x 200000, INF ~ 10^12
*/

long long find_min(vector<long long> &seg_tree, vector<long long> &lazy, int left, int right, int index, int a, int b) {
  // there is pending update ---> resolve pending updates
  push(seg_tree, lazy, left, right, index);
  
  // [left right] completely outside [a, b] --> return INF
  if (right < a || left > b)  {
    return INF;
  }
  
  // [left right] completely inside [a, b]
  if (a <= left && right <= b) { // [left, right] complete inside [a, b]
    return seg_tree[index];
  }
  
  // overlaps
  int mid = (left + right) / 2;
  return min(
    find_min(seg_tree, lazy, left, mid, 2 * index + 1, a, b), 
    find_min(seg_tree, lazy, mid + 1, right, 2 * index + 2, a, b)
  );
}

vector<pair<int, int>> break_cirl_seg(int a_size, int i, int j) {
  vector<pair<int, int>> res(0);
  if (i > j) {
    res.push_back(pair<int, int>(i, a_size - 1));
    res.push_back(pair<int, int>(0, j));
  } else {
    res.push_back(pair<int, int>(i, j));
  }
  return res;
}

void print_tree(vector<int> &seg_tree, int left, int right, int index) {
  cout << left << ' ' << right << ": " << seg_tree[index] << endl;
  if (left == right) return;
  int mid = (left + right) / 2;
  print_tree(seg_tree, left, mid, 2 * index + 1);
  print_tree(seg_tree, mid + 1, right, 2 * index + 2);
}

#define endl '\n';

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	int n, m, h, tree_size; long long min_val;
  int argc, i, j, v; 
  
  // init trees
  cin >> n;
  h = (int)ceil(log2(n));
  tree_size = 2 * (1 << h) - 1;
	vector<int> seq(n);
  vector<long long> seg_tree(tree_size, 0), lazy(tree_size, 0);
  
  // read the sequence
  for (auto &i : seq) cin >> i;
  
  // build the segment tree
  build_tree(seq, seg_tree, 0, n - 1, 0);
  
  // answer queries
  vector<int> line;
  cin >> m;
  cin.ignore();
  while (m--) {
    line = parse_line();
    i = line[0], j = line[1], v = (line.size() == 3)? line[2] : -1; 
    if (line.size() == 2) { // find the min val of the circular segment
      vector<pair<int, int>> seg = break_cirl_seg(n, i, j);
      min_val = INF;
      for (auto &rg : seg) {
        min_val = min(min_val, find_min(seg_tree, lazy, 0, n-1, 0, rg.first, rg.second));
      }
      cout << min_val << endl;
    } else { // increment the circular segment by v
      vector<pair<int, int>> seg = break_cirl_seg(n, i, j);
      for (auto &rg : seg) {
        // cout << "update: " <<  rg.first << " " << rg.second << endl; 
        update(seg_tree, lazy, 0, n-1, 0, rg.first, rg.second, v);
      }
      // cout << endl;
      // cout << "--" << endl;
      // print_tree(seg_tree, 0, n-1, 0);
      // cout << endl;
      // print_tree(lazy, 0, n-1, 0);
      // cout << "--" << endl;
    }
  }
  return 0;
}