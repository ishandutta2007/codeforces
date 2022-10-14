#include <bits/stdc++.h>
using namespace std;

class SplitMerge {
 public:
  struct Node {
    int val = 0;
    int lc = 0, rc = 0;
  };
  
  vector<Node> d;
  queue<int> free_nodes;

  int NewNode() {
    int res = free_nodes.front();
    free_nodes.pop();
    return res;
  }

  void Erase(int n) {
    d[n] = Node();
    free_nodes.emplace(n);
  }

  int Build(int tl, int tr, int p) {
    int n = NewNode();
    d[n].val = 1;
    if (tr - tl == 1) {
      return n;
    }
    int md = (tl + tr) / 2;
    if (p < md) {
      d[n].lc = Build(tl, md, p);
    } else {
      d[n].rc = Build(md, tr, p);
    }
    return n;
  }

  int Merge(int t1, int t2) {
    if (t1 == 0 || t2 == 0) {
      return t1 ^ t2;
    }
    d[t1].lc = Merge(d[t1].lc, d[t2].lc);
    d[t1].rc = Merge(d[t1].rc, d[t2].rc);
    d[t1].val += d[t2].val;
    Erase(t2);
    return t1;
  }

  void Split(int t1, int &t2, int k) {
    t2 = NewNode();
    int left = d[d[t1].lc].val;
    if (k > left) {
      Split(d[t1].rc, d[t2].rc, k - left);
    } else {
      swap(d[t1].rc, d[t2].rc);
    }
    if (k < left) {
      Split(d[t1].lc, d[t2].lc, k);
    }
    d[t2].val = d[t1].val - k;
    d[t1].val = k;
  }

  int Query(int n, int tl, int tr, int k) {
    if (tr - tl == 1) return tl;
    int md = (tl + tr) / 2;
    if (d[d[n].lc].val < k) {
      return Query(d[n].rc, md, tr, k - d[d[n].lc].val);
    } else {
      return Query(d[n].lc, tl, md, k);
    }
  }

  SplitMerge(int sz) {
    d.resize(sz);
    for (int i = 1; i < sz; i++) {
      free_nodes.emplace(i);
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, Q;
  cin >> N >> Q;
  string S;
  cin >> S;

  vector<int> order(N);
  iota(begin(order), end(order), 0);
  sort(begin(order), end(order), [&](int i, int j) { return S[i] < S[j]; });
  vector<int> mapping(N);
  for (int i = 0; i < N; i++) {
    mapping[order[i]] = i;
  }
  sort(begin(S), end(S));

  SplitMerge seg(N * 20);

  set<int> sorted;
  vector<int> roots(N);
  vector<int> type(N); // 0 increasing, 1 decreasing
  vector<int> until(N);
  for (int i = 0; i < N; i++) {
    sorted.emplace(i);
    roots[i] = seg.Build(0, N, mapping[i]);
    type[i] = 0;
    until[i] = i;
  }

  auto Split = [&](int x, int k) {
    if (k >= until[x] || k < x) {
      return;
    }
    if (type[x] == 0) { // increasing
      seg.Split(roots[x], roots[k + 1], k + 1 - x);
    } else { // decreasing
      roots[k + 1] = roots[x];
      seg.Split(roots[k + 1], roots[x], until[x] - k);
    }
    until[k + 1] = until[x];
    until[x] = k;
    sorted.emplace(k + 1);
    type[k + 1] = type[x];
  };

  auto Merge = [&](int a, int b) {
    if (a == b) {
      return;
    }
    sorted.erase(b);
    roots[a] = seg.Merge(roots[a], roots[b]);
    until[a] = until[b];
  };

  auto Query = [&](int p) {
    int inter = *prev(sorted.upper_bound(p));
    if (type[inter] == 0) {
      return seg.Query(roots[inter], 0, N, p - inter + 1);
    } else {
      return seg.Query(roots[inter], 0, N, until[inter] - p + 1);
    }
  };

  while (Q--) {
    int l, r, t;
    cin >> l >> r >> t;
    l--, r--, t ^= 1;
    Split(*prev(sorted.upper_bound(l)), l - 1);
    Split(*prev(sorted.upper_bound(r)), r);
    auto ll = sorted.lower_bound(l);
    auto rr = sorted.upper_bound(r);
    if (ll != rr) {
      static vector<int> tobe;
      tobe.clear();
      for (auto i = next(ll); i != rr; i++) {
        tobe.emplace_back(*i);
      }
      for (auto i : tobe) {
        Merge(l, i);
      }
    }
    type[l] = t;
  }

  for (int i = 0; i < N; i++) {
    cout << S[Query(i)];
  }
  cout << "\n";
  return 0;
}