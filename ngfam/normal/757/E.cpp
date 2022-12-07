#include<bits/stdc++.h>

using namespace std;

const int maxn = 1000005;
const int mod = 1e9 + 7;

int p[maxn];
vector<pair<int, int>> factorize[maxn];

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
    for(int i = N - 1; i > 0; --i) {
      invfact[i - 1] = mult(invfact[i], i);
    }
  }

  int comb(int n, int k) {
    return mult(mult(fact[n], invfact[k]), invfact[n - k]);
  }
};

Combi<maxn+maxn> combin;

int euler(int n, int k) {
  return combin.comb(n + k - 1, k - 1);
}

int f[12][12];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  for(int i = 2; i < maxn; ++i) {
    if(p[i] == 0) {
      for(int j = i; j < maxn; j += i) p[j] = i;
    }
    int temp = i;
    factorize[i].emplace_back(p[i], 0);

    while(temp > 1) {
      if(p[temp] != factorize[i].back().first) factorize[i].emplace_back(p[temp], 1);
      else factorize[i].back().second++;
      temp /= p[temp];
    }
  }


  int q; cin >> q;
  while(q--) {
    int n, r; cin >> r >> n;

    if(r == 0) {
      cout << binpow(2, factorize[n].size()) << "\n";
      continue;
    }

    int sz = factorize[n].size();
    for(int i = 0; i <= sz; ++i) {
      for(int j = 0; j <= sz; ++j) {
        f[i][j] = 0;
      }
    }

    f[0][0] = 1;
    for(int i = 0; i < sz; ++i) {
      int all = euler(factorize[n][i].second, r);
      int not_all = euler(factorize[n][i].second - 1, r + 1);
      for(int j = 0; j <= i; ++j) {

        f[i + 1][j] = add(f[i + 1][j], mult(f[i][j], all));
        f[i + 1][j + 1] = add(f[i + 1][j + 1], mult(f[i][j], not_all));
      }
    }

    int ans = 0;
    for(int j = 0; j <= sz; ++j) ans = add(ans, mult(binpow(2, j), f[sz][j]));
    cout << ans << "\n";
  }

  return 0;
}