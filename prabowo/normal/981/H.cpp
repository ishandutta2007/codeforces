#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

namespace FFT {

const int LN = 21;
const int N = 1 << LN;

const int PRIMITIVE_ROOT = 3;

int root[N];

void init_fft() {
  const int UNITY = power(PRIMITIVE_ROOT, (MOD-1) >> LN);
  root[0] = 1;
  for (int i = 1; i < N; ++i) {
    root[i] = 1LL * UNITY * root[i-1] % MOD;
  }
}

// n is the length of polynom
void fft(int n, vector<int> &a, bool invert) {
  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j & bit; bit >>= 1) j ^= bit;
    j ^= bit;
    if (i < j) swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = (invert ? root[N - N/len] : root[N/len]);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len>>1; ++j) {
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
    for (int i = 0; i < n; ++i) a[i] = 1LL * a[i] * inv % MOD;
  }
}

} // namespace FFT

vector<int> add(vector<int> a, vector<int> b) {
  if (a.size() < b.size()) swap(a, b);
  for (int i = 0; i < b.size(); ++i) a[i] = (a[i] + b[i]) % MOD;
  return a;
}

vector<int> multiply(vector<int> a, vector<int> b) {
  int sz = a.size() + b.size();
  int len = (sz == 2 ? 1 : 1 << (32 - __builtin_clz(sz - 2)));
  a.resize(len); b.resize(len);
  FFT::fft(len, a, false); FFT::fft(len, b, false);
  a.resize(len);
  for (int i = 0; i < len; ++i) a[i] = 1LL * a[i] * b[i] % MOD; 
  FFT::fft(len, a, true);
  a.resize(sz);
  return a;
}

int n, k;
vector<int> edges[N];

int perm[N];

// Poly degree x^a y^b, b  1
using BiPoly = pair<vector<int>, vector<int>>;
BiPoly evaluate(const vector<BiPoly> &polys) {
  auto greaterSize = [&](const BiPoly &u, const BiPoly &v) {
    return u.first.size() > v.first.size();
  };
  priority_queue<BiPoly, vector<BiPoly>, decltype(greaterSize)> pq(greaterSize);

  for (const BiPoly &poly : polys) pq.push(poly);

  while (pq.size() > 1) {
    BiPoly u = pq.top(); pq.pop();
    BiPoly v = pq.top(); pq.pop();
    pq.emplace(multiply(u.first, v.first), add(multiply(u.first, v.second), multiply(u.second, v.first)));
  }
  return pq.top();
}

int ans;

int sz[N];
int dfs(int u, int p) {
  sz[u] = 1;

  int sum = 0;
  vector<BiPoly> polys;
  for (int v : edges[u]) {
    if (v == p) continue;

    int res = dfs(v, u);

    ans = (1LL * res * sum + ans) % MOD;
    sum = (sum + res) % MOD;
    sz[u] += sz[v];

    polys.push_back({{1, sz[v]}, {res}});
  }

  if (polys.size() == 0) return 1;

  vector<int> poly0, poly1;
  tie(poly0, poly1) = evaluate(polys);
  poly1.push_back(0);
  for (int i = (int) poly1.size() - 1; i > 0; --i) poly1[i] = (poly1[i] + 1LL * poly1[i - 1] * (n - sz[u])) % MOD;

  for (int i = 0; i < poly0.size(); ++i) {
    if (i > k) break;
    sum = (1LL * perm[i] * poly0[i] + sum) % MOD;
    ans = (1LL * perm[i] * poly1[i] + ans) % MOD;
  }

  return sum;
}

int main() {
  FFT::init_fft();

  scanf("%d %d", &n, &k);
  if (k == 1) return 0 * printf("%lld\n", 1LL * n * (n - 1) / 2 % MOD);
  perm[0] = 1;
  for (int i = 1; i <= k; ++i) perm[i] = 1LL * perm[i - 1] * (k - i + 1) % MOD;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0, 0);
  printf("%d\n", ans);
  return 0;
}