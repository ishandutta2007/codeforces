#include<bits/stdc++.h>

using namespace std;

const int MAXN = 205;
const int mod = 998244353;

int add(int x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int sub(int x, int y) {
  x -= y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
  return x;
}

int mult(int x, int y) {
  return 1LL * x * y % mod;
}

int binpow(int x, int y) {
  int ret = 1;
  for(; y > 0; x = mult(x, x), y >>= 1) {
    if(y & 1) ret = mult(ret, x);
  }
  return ret;
}

int inverse_modulo(int x) {
  return binpow(x, mod - 2);
}

template<int N>
struct Combi{
  vector<int> fact, invfact;

  Combi() {
    fact.resize(N); invfact.resize(N);
    fact[0] = 1;
    for(int i = 1; i < N; ++i) fact[i] = mult(fact[i - 1], i);
    invfact[N - 1] = inverse_modulo(fact[N - 1]);
    for(int i = N - 1; i >= 0; --i) {
      invfact[i - 1] = mult(invfact[i], i);
    }
  }

  int comb(int n, int k) {
    if(k > n / 2) k = n - k;
    if(n > N) {
      int ret = invfact[k];
      for(int i = n; i > n - k; --i) ret = mult(ret, i);
      return ret;
    }
    return mult(mult(fact[n], invfact[k]), invfact[n - k]);
  }
};

int n;
int f[MAXN][MAXN];
pair<int, int> seg[MAXN];

Combi<MAXN> Comb;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  vector<int> points;

  int all = 1;

  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> seg[i].first >> seg[i].second;
    points.emplace_back(seg[i].first);
    points.emplace_back(seg[i].second + 1);
    all = mult(all, seg[i].second - seg[i].first + 1);
  }

  reverse(seg, seg + n);

  all = inverse_modulo(all);

  sort(points.begin(), points.end());
  points.erase(unique(points.begin(), points.end()), points.end());

  f[0][0] = 1;

  for(int i = 0; i + 1 < points.size(); ++i) {
    for(int j = 0; j <= n; ++j) {
      if(!f[i][j]) continue;

      f[i + 1][j] = add(f[i + 1][j], f[i][j]);
      for(int k = j + 1; k <= n; ++k) {
        int able = 1;
        for(int w = j; w < k; ++w) {
          if(seg[w].first > points[i] || seg[w].second < points[i + 1] - 1) {
            able = 0;
          }
        }
        int take = k - j, len = points[i + 1] - points[i];
        if(able) f[i + 1][k] = add(f[i + 1][k], mult(f[i][j], Comb.comb(len + take - 1, len - 1)));
      }
    }
  }


  cout << mult(f[points.size() - 1][n], all) << endl;

  return 0;
}

/// 2 thang = 3 gap