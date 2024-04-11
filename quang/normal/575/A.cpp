#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

struct matrix {
  int a[2][2];

  matrix() {
    memset(a, 0, sizeof a);
  }
};

int n, m, p;
long long k;
int s[N];
vector<pair<long long, int> > b;
matrix root;
matrix t[N * 4];
map<long long, int> M;

inline int add(int u, int v) {
  u += v;
  if (u >= p) {
    u -= p;
  }
  return u;
}

matrix qmul(const matrix &u, const matrix &v) {
  matrix res;
  for (int i = 0; i < 2; i++ ){
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        res.a[i][j] = ((long long)u.a[i][k] * v.a[k][j] + res.a[i][j]) % p;
      }
    }
  }
  return res;
}

matrix qpow(matrix u, long long v) {
  matrix res = root;
  while (v) {
    if (v & 1) {
      res = qmul(res, u);
    }
    u = qmul(u, u);
    v >>= 1;
  }
  return res;
}

void build(int node, int l, int r) {
  if (l == r) {
    t[node].a[0][1] = 1;
    if (l == 0) {
      t[node].a[0][0] = s[0];
      t[node].a[1][0] = s[n - 1];
    } else {
      t[node].a[0][0] = s[l];
      t[node].a[1][0] = s[l - 1];
    }
    return;
  }
  int m = (l + r) >> 1;
  build(node + node, l, m);
  build(node + node + 1, m + 1, r);
  t[node] = qmul(t[node + node], t[node + node + 1]);
}

matrix get(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return root;
  }
  if (x <= l && r <= y) {
    return t[node];
  }
  int m = (l + r) >> 1;
  matrix p1 = get(node + node, l, m, x, y);
  matrix p2 = get(node + node + 1, m + 1, r, x, y);
  return qmul(p1, p2);
}

matrix getval(long long l, long long r) {
  if (l > r) {
    return root;
  }
  if (M.find(l - 1) != M.end()) {
    matrix res;
    res.a[0][1] = 1;
    res.a[0][0] = s[l % n];
    res.a[1][0] = M[l - 1];
    return qmul(res, getval(l + 1, r));
  }
  long long bl = l / n;
  long long br = r / n;
  if (bl == br) {
    return get(1, 0, n - 1, l % n, r % n);
  }
  matrix res = get(1, 0, n - 1, l % n, n - 1);
  long long cnt = br - bl - 1;
  res = qmul(res, qpow(t[1], cnt));
  res = qmul(res, get(1, 0, n - 1, 0, r % n));
  return res;
}

int main() {
  #ifdef Doflamingo
  freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  root.a[0][0] = root.a[1][1] = 1;
  scanf("%I64d %d", &k, &p);
  if (p == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (k <= 1) {
    cout << k << endl;
    return 0;
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
    s[i] %= p;
  }
  build(1, 0, n - 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    long long j;
    int v;
    scanf("%I64d %d", &j, &v);
    v %= p;
    if (j >= k) {
      continue;
    }
    b.push_back(make_pair(j, v));
    M[j] = v;
  }
  sort(b.begin(), b.end());
  matrix B;
  B.a[0][0] = 1, B.a[0][1] = 0;
  long long cur = 1;
  for (int i = 0; i < b.size(); i++) {
    int a1, a2;
    matrix C = getval(cur, b[i].first - 1);
    B = qmul(B, C);
    matrix D;
    D.a[0][1] = 1;
    D.a[0][0] = b[i].second;
    if (i && b[i - 1].first + 1 == b[i].first) {
      D.a[1][0] = b[i - 1].second;
    } else {
      D.a[1][0] = s[(b[i].first - 1) % n];
    }
    B = qmul(B, D);
    cur = b[i].first + 1;
  }
  matrix X = getval(cur, k - 1);
  B = qmul(B, X);
  cout << B.a[0][0] << endl;
  return 0;
}