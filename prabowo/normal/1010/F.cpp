#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int N = 100005;

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {

const int LN = 23;
const int N = 1 << LN;
const int PRIMITIVE_ROOT = 3;

int root[N];


void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, MOD-1 >> LN);
  root[0] = 1;
  for (int i=1; i<N; i++) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

// n is the length of polynom
void fft(int n, vector<int> &a, bool invert) {
  for (int i=1, j=0; i<n; ++i) {
    int bit = n >> 1;
    for (; j>=bit; bit>>=1) j -= bit;
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len=2; len<=n; len<<=1) {
    int wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i=0; i<n; i+=len) {
      int w = 1;
      for (int j=0; j<len>>1; j++) {
        int u = a[i+j];
        int v = 1LL * a[i+j + len/2] * w % MOD;

        a[i+j] = (u + v) % MOD;
        a[i+j + len/2] = (u - v + MOD) % MOD;

        w = 1LL * w * wlen % MOD;
      }
    }
  }

  if (invert) {
    int inv = power(n, MOD-2);
    for (int i=0; i<n; i++) a[i] = 1LL * a[i] * inv % MOD;
  }
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int len = (a.size() + b.size() == 2 ? 1 : 1 << (32 - __builtin_clz(a.size() + b.size() - 2)));
  a.resize(len); b.resize(len);
  fft(len, a, false); fft(len, b, false);
  a.resize(len);
  for (int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % MOD; 
  fft(len, a, true);
  while (a.back() == 0) a.pop_back();
  return a;
}

vector<int> add(vector<int> a, vector<int> b) {
  if (a.size() < b.size()) swap(a, b);
  for (int i = 0; i < b.size(); ++i) a[i] = (a[i] + b[i]) % MOD;
  return a;
}

}

// dp[u] := g.f. where x^k coeff is number of solution with = k fruits at u

// If no child:
// dp[u] = 1 / (1 - x)

// If one child:
// dp[u] = 1 / (1 - x) * (dp[c] + 1), c is child

// If two children:
// dp[u] = 1 / (1 - x) * (dp[c1] + 1) * (dp[c2] + 1)

// Let y = 1 / (1 - x)
// If we represent dp[u] as y, its degree = subtree size

// To efficiently perform all multiplication,
// dp can be represented as ((((P1 + 1) P2 + 1) P3 + 1) ... ) Pk
// where Pi are polynom of y.
// dp can be rewritten as P1 P2 ... Pk + P2 P3 ... Pk + ... + Pk

// [x^n] 1/(1 - x)^k = C(n + k - 1, k - 1)

int n;
long long x;

vector<int> edges[N];

int sz[N], heavy[N], par[N];
void dfsInit(int u, int p) {
  sz[u] = 1, heavy[u] = -1, par[u] = p;
  for (int v: edges[u]) {
    if (v == p) continue;
    dfsInit(v, u);
    sz[u] += sz[v];
    if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) {
      heavy[u] = v;
    }
  }
}

pair<vector<int>, vector<int>> evaluate(vector<vector<int>> polynoms) {
  if (polynoms.size() == 1) return {polynoms[0], polynoms[0]};

  int sum = 0;
  for (int i = 0; i < polynoms.size(); ++i) sum += polynoms[i].size();

  int mid = 0, summid = 0;
  while (summid * 2 < sum) summid += polynoms[mid++].size();
  if (mid == polynoms.size()) --mid;

  pair<vector<int>, vector<int>> res1 = evaluate(vector<vector<int>>(polynoms.begin(), polynoms.begin() + mid));
  pair<vector<int>, vector<int>> res2 = evaluate(vector<vector<int>>(polynoms.begin() + mid, polynoms.end()));

  // for (int u: FFT::add(FFT::multiply(res1.first, res2.second), res2.first)) cerr << u << " "; cerr << endl;

  return {FFT::add(FFT::multiply(res1.first, res2.second), res2.first), FFT::multiply(res1.second, res2.second)};
}

vector<int> dfs(int u) {
  vector<int> heavyPath = {u};
  while (heavy[heavyPath.back()] != -1) {
    heavyPath.push_back(heavy[heavyPath.back()]);
  }

  vector<vector<int>> polynoms;
  while (heavyPath.size() > 0) {
    int u = heavyPath.back();
    heavyPath.pop_back();

    vector<int> polynom = {1};
    for (int v: edges[u]) {
      if (par[u] == v || v == heavy[u]) continue;
      polynom = dfs(v); ++polynom[0];
    }

    polynom.push_back(0);
    for (int i = (int) polynom.size() - 1; i > 0; --i) {
      polynom[i] = polynom[i - 1];
    }
    polynom[0] = 0;
    polynoms.push_back(polynom);
  }

  // cerr << "dfs " << u << endl;
  // for (vector<int> poly: polynoms) {
  //   for (int u: poly) cerr << u << " "; cerr << endl;
  // }

  return evaluate(polynoms).first;
}

void solve() {
  vector<int> poly = dfs(0);
  x %= MOD;

  int ans = (x == 0 ? poly[0] : 0), cur = 1;
  for (int i = 1; i < poly.size(); ++i) {
    ans = (1LL * cur * poly[i] + ans) % MOD;
    cur = 1LL * cur * (x + i) % MOD * power(i, MOD - 2) % MOD;
  }

  printf("%d\n", ans);
}

void init() {
  FFT::init_fft();
  dfsInit(0, -1);
}

void read() {
  scanf("%d %lld", &n, &x);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }
}

int main() {
  read();
  init();
  solve();
  return 0;
}