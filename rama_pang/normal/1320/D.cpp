#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
string S;

constexpr int MOD = 998244353;
constexpr int KEY = 37;

int power(int n, int x) {
  if (x == 0) {
    return 1;
  }
  int res = power(n, x / 2);
  res = 1ll * res * res % MOD;
  if (x & 1) {
    res = 1ll * res * n % MOD;
  }
  return res;
}

struct Data {
  lint hashOne = 0; // hashing positions of 1s
  int front = 0;
  int back = 0;
  int sz = 0;

  Data() {}

  Data(int h, int f, int b, int s) {
    hashOne = h;
    front = f;
    back = b;
    sz = s;
  }

  void rmf() { // remove front
    hashOne--;
    hashOne = (1ll * hashOne * power(KEY, MOD - 2) % MOD);
    hashOne += MOD; hashOne %= MOD;

    front = 0;
    sz--;
  }

  void rmb() { // remove back
    hashOne = (1ll * hashOne - power(KEY, sz - 1)) % MOD;
    hashOne += MOD; hashOne %= MOD;

    back = 0;
    sz--;
  }

  Data operator + (const Data &o) const {
    if (o.sz == 0) {
      return *this;
    } else if (sz == 0) {
      return o;
    }
    
    Data a = *this;
    Data b = o;
    Data res;

    if (a.back == 1 && b.front == 1) {
      a.rmb();
      b.rmf();
    }

    if (a.sz == 0 && b.sz == 0) {
      return Data(0, 0, 0, 0);
    }
    if (a.sz == 0) {
      return b;
    }
    if (b.sz == 0) {
      return a;
    }
    
    res.hashOne = (1ll * a.hashOne + (1ll * b.hashOne * power(KEY, a.sz) % MOD)) % MOD;
    res.front = a.front;
    res.back = b.back;
    res.sz = a.sz + b.sz;

    return res;
  }

  bool operator==(const Data &o) {
    return hashOne == o.hashOne && front == o.front && back == o.back && sz == o.sz;
  }
};

const Data ZERO = Data(0, 0, 0, 1);
const Data ONE = Data(1, 1, 1, 1);
const Data EMPTY = Data(0, 0, 0, 0);

template<int SZ>
struct SegmentTree {
  Data tree[4 * SZ];

  void build(int n, int tl, int tr) {
    if (tl == tr) {
      if (S[tl] == '1') {
        tree[n] = ONE;
      } else {
        tree[n] = ZERO;
      }
      return;
    }
    int mid = (tl + tr) / 2;
    build(n * 2, tl, mid);
    build(n * 2 + 1, mid + 1, tr);
    tree[n] = tree[n * 2] + tree[n * 2 + 1];
  }

  void init() {
    build(1, 0, (int) S.size() - 1);
  }

  Data query(int n, int tl, int tr, int l, int r) {
    if (tr < l || r < tl || tl > tr || l > r) {
      return EMPTY;
    }
    if (l <= tl && tr <= r) {
      return tree[n];
    }
    int mid = (tl + tr) / 2;
    return query(n * 2, tl, mid, l, r) + query(n * 2 + 1, mid + 1, tr, l, r);
  }

};

SegmentTree<200005> seg;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> S;
  
  seg.init();

  int Q;
  cin >> Q;

  for (int qi = 0; qi < Q; qi++) {
    int a, b, len;
    cin >> a >> b >> len;
    a--, b--;

    Data A = seg.query(1, 0, (int) S.size() - 1, a, a + len - 1);
    Data B = seg.query(1, 0, (int) S.size() - 1, b, b + len - 1);

    // cout << A.front << " " << A.back << " " << A.hashOne << "\n";
    // cout << B.front << " " << B.back << " " << B.hashOne << "\n";

    if (A == B) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

  return 0;
}