#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

namespace FFT {
  typedef complex<double> cd;
  const double PI = acos(-1);

  void fft(vector<cd> &a, bool inv = false) {
    int n = a.size();
    for (int i = 0, j = 0; i < n; i++) {
      if (j > i) swap(a[i], a[j]);
      int k = n;
      while (j & (k >>= 1)) j &= ~k;
      j |= k;
    }
    double pi = inv ? -PI : PI;
    for (int step = 1; step < n; step <<= 1) {
      double alpha = pi / step;
      REP(k, step) {
        cd omegak = exp(cd(0, alpha * k));
        for (int ek = k; ek < n; ek += step << 1) {
          int ok = ek + step;
          cd t = omegak * a[ok];
          a[ok] = a[ek] - t;
          a[ek] += t;
        }
      }
    }
    if (inv) REP(i, n) a[i] /= n;
  }

  vector<ll> operator*(const vector<ll> &v1, const vector<ll> &v2) {
    int s1 = v1.size(), s2 = v2.size(), s = 2;
    while (s < s1 + s2) s <<= 1;
    vector<cd> a(s, 0), b(s, 0);
    REP(i, s1) a[i] = v1[i];
    REP(i, s2) b[i] = v2[i];
    fft(a);
    fft(b);
    REP(i, s) a[i] *= b[i];
    fft(a, true);
    vector<ll> ans(s1 + s2 - 1);
    REP(i, s1 + s2 - 1) ans[i] = ll(round(a[i].real()));
    return ans;
  }
}
using namespace FFT;

const int maxn = 212345;

int n, x, y, q;
int a[maxn], f[1123456];

int main() {
  scanf("%d%d%d", &n, &x, &y);
  REP(i, n + 1) scanf("%d", a + i);
  scanf("%d", &q);
  vector<ll> u(maxn), v(maxn);
  REP(i, n + 1) {
    u[a[i]] = 1;
    v[int(2e5) - a[i]] = 1;
  }
  auto p = u * v;
  reset(f, -1);
  FOR(i, 1, x) if (p[int(2e5) + i]) f[(i + y) * 2] = (i + y) * 2;
  FOR(i, 1, 1e6) for (int j = i; j <= 1e6; j += i) chkmax(f[j], f[i]);
  FOR(i, 1, q) {
    int l;
    scanf("%d", &l);
    printf("%d ", f[l]);
  }
}