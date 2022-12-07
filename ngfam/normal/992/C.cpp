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

int binpow(int x, long long y) {
  int ret = 1;
  for(; y > 0; x = mult(x, x), y >>= 1) {
    if(y & 1) ret = mult(ret, x);
  }
  return ret;
}

int inverse_modulo(int x) {
  return binpow(x, mod - 2);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  long long n, k;

  cin >> n >> k;

  if(n == 0) {
    cout << 0 << endl;
    exit(0);
  }

  int ans = mult(n % mod, binpow(2, k + 1));
  int all = binpow(2, k + 1);
  all = sub(all, 2);
  ans = sub(ans, mult(all, inverse_modulo(2)));

  cout << ans << endl;

  return 0;
}