#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;

int N, M, P;
pair<int, int> A[MAXN];
pair<int, int> D[MAXN];
pair<pair<int, int>, int> Mon[MAXN];

template<int SZ>
struct SegmentTree {
  lint tree[4 * SZ];
  lint lazy[4 * SZ];

  void build() {
    fill(tree, tree + 4 * SZ, 0);
    fill(lazy, lazy + 4 * SZ, 0);
  }

  void push(int n) {
    for (int i = 0; i < 2; i++) {
      tree[n * 2 + i] += lazy[n];
      lazy[n * 2 + i] += lazy[n];
    }
    lazy[n] = 0;
  }

  void pull(int n) {
    tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
  }

  void update(int n, int tl, int tr, int l, int r, lint x) {
    if (tr < l || r < tl || tl > tr || l > r) {
      return;
    }
    if (l <= tl && tr <= r) {
      tree[n] += x;
      lazy[n] += x;
      return;
    }
    int mid = (tl + tr) / 2;
    push(n);
    update(n * 2, tl, mid, l, r, x);
    update(n * 2 + 1, mid + 1, tr, l, r, x);
    pull(n);
  }

  lint query(int n, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || tl > tr || l > r) {
      return -1e15;
    }
    if (l <= tl && tr <= r) {
      return tree[n];
    }
    int mid = (tl + tr) / 2;
    push(n);
    return max(query(n * 2, tl, mid, l, r), query(n * 2 + 1, mid + 1, tr, l, r));
  }

};

SegmentTree<MAXN> seg;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M >> P;
  for (int i = 0; i < N; i++) {
    cin >> A[i].first >> A[i].second;
  }
  for (int i = 0; i < M; i++) {
    cin >> D[i].first >> D[i].second;
  }
  for (int i = 0; i < P; i++) {
    cin >> Mon[i].first.first >> Mon[i].first.second >> Mon[i].second;
  }

  sort(Mon, Mon + P);
  sort(A, A + N);
  sort(D, D + M);

  seg.build();

  map<int, int> pos;
  vector<int> coord;
  for (int i = 0; i < P; i++) {
    coord.emplace_back(Mon[i].first.second);
  }
  sort(begin(coord), end(coord));
  coord.resize(unique(begin(coord), end(coord)) - begin(coord));
  for (int i = (int) coord.size() - 1; i >= 0; i--) {
    pos[coord[i]] = i + 1;
  }

  int ptr = 0;
  
  vector<lint> init(coord.size() + 2, -1e15);

  for (int i = 0; i < M; i++) {
    int p = lower_bound(begin(coord), end(coord), D[i].first) - begin(coord);
    init[p] = max(init[p], (lint) - D[i].second);
  }

  seg.build();

  int sz = coord.size();
  for (int i = 0; i <= sz; i++) {
    seg.update(1, 0, sz, i, i, init[i]);
  }

  // for (int i = 1; i <= sz; i++) {
  //   cout << seg.query(1, 1, sz, i, i) << " \n"[i == sz];
  // }

  lint ans = -1e15;

  for (int i = 0; i < N; i++) {
    while (ptr < P && Mon[ptr].first.first < A[i].first) {
      seg.update(1, 0, sz, pos[Mon[ptr].first.second], sz, Mon[ptr].second);
      ptr++;
    }
    ans = max(ans, - A[i].second + seg.query(1, 0, sz, 0, sz));
  }

  cout << ans << "\n";
  return 0;
}