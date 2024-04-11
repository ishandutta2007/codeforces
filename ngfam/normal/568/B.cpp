#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

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
    return mult(mult(fact[n], invfact[k]), invfact[n - k]);
  }
};

Combi<5050> combi;

const int N = 4040;

int f[N][2];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;

  f[0][0] = 1;
  for(int i = 1; i <= n; ++i) {
    for(int j = 1; j <= i; ++j) {
      f[i][0] = add(f[i][0], mult(f[i - j][0], combi.comb(i - 1, j - 1)));
      f[i][1] = add(f[i][1], mult(f[i - j][1], combi.comb(i - 1, j - 1)));
    }
    f[i][1] = add(add(f[i - 1][0], f[i - 1][1]), f[i][1]);
  }

  cout << f[n][1] << endl;

  return 0;
}