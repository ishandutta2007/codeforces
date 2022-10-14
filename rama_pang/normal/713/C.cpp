#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

template<typename data_t>
struct Line {
  data_t a, b;
  Line() : a(0), b(inf) {}
  Line(data_t a, data_t b) : a(a), b(b) {}
  data_t get(data_t x) {
    return a * x + b;
  }
  void add(Line x) {
    a += x.a;
    b += x.b;
  }
};

class LiChao {
 private:
  using data_t = long long;
  
  struct Node {
    Line<data_t> line = Line<data_t>();
    Line<data_t> lazy = Line<data_t>(0, 0);

    Node *lc = nullptr;
    Node *rc = nullptr;

    void apply(data_t l, data_t r, Line<data_t> v) {
      line.add(v);
      lazy.add(v);
    }
  };

  data_t sz;
  Node *root = nullptr;

  void PushLazy(Node* &n, data_t tl, data_t tr) {
    if (n == nullptr) return;
    if (n->lc == nullptr) n->lc = new Node();
    if (n->rc == nullptr) n->rc = new Node();
    data_t mid = (tl + tr) / 2;
    n->lc->apply(tl, mid, n->lazy);
    n->rc->apply(mid + 1, tr, n->lazy);
    n->lazy = Line<data_t>(0, 0);
  }

  void PushLine(Node* &n, data_t tl, data_t tr) {
    if (n == nullptr) return;
    data_t mid = (tl + tr) / 2;
    InsertLineKnowingly(n->lc, tl, mid, n->line);
    InsertLineKnowingly(n->rc, mid + 1, tr, n->line);
    n->line = Line<data_t>();
  }

  void InsertLineKnowingly(Node* &n, data_t tl, data_t tr, Line<data_t> x) {
    if (n == nullptr) n = new Node();
    if (n->line.get(tl) > x.get(tl)) swap(n->line, x);
    if (n->line.get(tr) <= x.get(tr)) return;
    if (tl == tr) return;
    data_t mid = (tl + tr) / 2;
    PushLazy(n, tl, tr);
    if (n->line.get(mid) <= x.get(mid)) {
      InsertLineKnowingly(n->rc, mid + 1, tr, x);
    } else {
      swap(n->line, x);
      InsertLineKnowingly(n->lc, tl, mid, x);
    }
  }

  void InsertLine(Node* &n, data_t tl, data_t tr, data_t l, data_t r, Line<data_t> x) {
    if (tr < l || r < tl || tl > tr || l > r) return;
    if (n == nullptr) n = new Node();
    if (l <= tl && tr <= r) return InsertLineKnowingly(n, tl, tr, x);
    data_t mid = (tl + tr) / 2;
    PushLazy(n, tl, tr);
    InsertLine(n->lc, tl, mid, l, r, x);
    InsertLine(n->rc, mid + 1, tr, l, r, x);
  }

  void AddLine(Node* &n, data_t tl, data_t tr, data_t l, data_t r, Line<data_t> x) {
    if (tr < l || r < tl || tl > tr || l > r) return;
    if (n == nullptr) n = new Node();
    if (l <= tl && tr <= r) return n->apply(tl, tr, x);
    data_t mid = (tl + tr) / 2;
    PushLazy(n, tl, tr);
    PushLine(n, tl, tr);
    AddLine(n->lc, tl, mid, l, r, x);
    AddLine(n->rc, mid + 1, tr, l, r, x);
  }

  data_t Query(Node* &n, data_t tl, data_t tr, data_t x) {
    if (n == nullptr) return inf;
    if (tl == tr) return n->line.get(x);
    data_t res = n->line.get(x);
    data_t mid = (tl + tr) / 2;
    PushLazy(n, tl, tr);
    if (x <= mid) {
      res = min(res, Query(n->lc, tl, mid, x));
    } else {
      res = min(res, Query(n->rc, mid + 1, tr, x));
    }
    return res;
  }

 public:
  LiChao() {}
  LiChao(data_t sz) : sz(sz) {}
  
  void InsertLine(data_t l, data_t r, Line<data_t> x) {
    return InsertLine(root, 0, sz - 1, l, r, x);
  }
  void AddLine(data_t l, data_t r, Line<data_t> x) {
    return AddLine(root, 0, sz - 1, l, r, x);
  }
  data_t Query(data_t x) {
    return min(inf, Query(root, 0, sz - 1, x));
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  const int sz = 2e9 + 1000;

  LiChao lichao(sz);
  lichao.InsertLine(0, sz - 1, Line<long long>(0, 0));

  // dp(n, x) = cost if 1...n nondecreasing, last element = x
  // dp(n, x) = for y <= x, min dp(n - 1, y) + abs(a[n] - x)

  auto FindMinimum = [&]() {
    int lo = 0, hi = sz - 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (lichao.Query(mid) < lichao.Query(mid + 1)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  };

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;

    a -= i;
    a += sz / 2;

    int x_min = FindMinimum();
    long long y_min = lichao.Query(x_min);
    lichao.InsertLine(x_min, sz - 1, Line<long long>(0, y_min));

    lichao.AddLine(0, a, Line<long long>(-1, a));
    lichao.AddLine(a, sz - 1, Line<long long>(1, -a));
  }

  cout << lichao.Query(FindMinimum()) << "\n";
  return 0;
}