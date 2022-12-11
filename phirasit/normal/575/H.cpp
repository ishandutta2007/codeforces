#include <iostream>
#include <cassert>

using namespace std;

const long long mod = 1000000007ll;
const int N = 2000010;

long long fac[N], inv_fac[N];
long long inv[N];
int n;

long long C(int x, int r) {
  long long ans = fac[x];
  ans = (ans * inv_fac[r]) % mod;
  ans = (ans * inv_fac[x-r]) % mod;
  return ans;
}
int main() {
  cin >> n;
  inv[1] = 1ll;
  for(int i = 2;i < N;i++) {
    inv[i] = (-(mod / i) * inv[mod % i]) % mod;
    inv[i] = (inv[i] + mod) % mod;
    assert((inv[i] * i) % mod == 1);
  }
  fac[0] = inv_fac[0] = 1ll;
  for(int i = 1;i < N;i++) {
    fac[i] = (i * fac[i-1]) % mod;
    inv_fac[i] = (inv[i] * inv_fac[i-1]) % mod;
  }
  long long ans = 0ll;
  for(int i = 1;i <= n+1;i++) {
    ans = (ans + C(i+n, n)) % mod;
  }
  cout << ans << endl;
  return 0;
}