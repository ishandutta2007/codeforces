#include <bits/stdc++.h>
using namespace std;

struct Item {
  int left;
  int right;
  int ans;
  int full;
  Item(int x = -1) : left(x), right(x), ans(x), full(x) {}
};

Item operator+(const Item &l, const Item &r) {
  if (l.ans == -1) return r;
  if (r.ans == -1) return l;
  Item res(0);
  res.left = l.left + (l.full ? r.left : 0);
  res.right = r.right + (r.full ? l.right : 0);
  res.ans = max({l.ans, r.ans, l.right + r.left});
  res.full = (l.full & r.full);
  return res;
}

class SegTree {
 public:
  int n;
  vector<Item> tree;

  SegTree(int n) : n(n), tree(2 * n)  {}

  void Update(int p, int x) {
    p += n;
    tree[p] = Item(x);
    for (p /= 2; p > 0; p /= 2) {
      tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
  }

  int Query(int l, int r) {
    Item le(-1), ri(-1);
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
      if (l & 1) le = le + tree[l++];
      if (r & 1) ri = tree[--r] + ri;
    }
    return (le + ri).ans;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {
    cin >> H[i];
  }

  vector<int> Vs = H;
  sort(begin(Vs), end(Vs));
  Vs.resize(unique(begin(Vs), end(Vs)) - begin(Vs));

  int Q;
  cin >> Q;
  vector<array<int, 3>> Query(Q);
  vector<int> lo(Q, 0);
  vector<int> hi(Q, int(Vs.size()) - 1);
  for (int i = 0; i < Q; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> Query[i][j];
    }
    Query[i][0]--, Query[i][1]--;
  }

  vector<pair<int, int>> upds(N);
  for (int i = 0; i < N; i++) {
    upds[i] = pair(lower_bound(begin(Vs), end(Vs), H[i]) - begin(Vs), i);
  }
  sort(begin(upds), end(upds));

  SegTree T(N);
  vector<vector<int>> check(Vs.size());

  for (int rep = 0; (1 << rep) < (Vs.size() << 1); rep++) {
    for (int i = 0; i < N; i++) {
      T.Update(i, 1);
    }
    for (int i = 0; i < Q; i++) {
      check[(lo[i] + hi[i] + 1) / 2].push_back(i);
    }
    for (int md = 0, ptr = 0; md < int(Vs.size()); md++) {
      while (ptr < N && upds[ptr].first < md) {
        T.Update(upds[ptr++].second, 0);
      }
      for (auto id : check[md]) {
        if (T.Query(Query[id][0], Query[id][1] + 1) >= Query[id][2]) {
          lo[id] = md;
        } else {
          hi[id] = md - 1;
        }
      }
      check[md].clear();
    }
  }

  for (int i = 0; i < Q; i++) {
    assert(lo[i] == hi[i]);
    cout << Vs[lo[i]] << '\n';
  }
  return 0;
}