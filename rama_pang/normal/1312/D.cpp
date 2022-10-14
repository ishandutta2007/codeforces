#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MOD = 998244353;

lint n, m;
lint fact[1000005];

lint power(int n, int x) {
  if (x == 0) {
    return 1;
  }
  lint res = power(n, x / 2);
  res *= res;
  res %= MOD;
  if (x & 1) {
    res *= n;
    res %= MOD;
  }
  return res;
}

lint Choose(int n, int k) {
  if (k < 0 || k > n) return 0;
  return fact[n] * power(fact[k], MOD - 2) % MOD * power(fact[n - k], MOD - 2) % MOD;
}


int main() {
  fact[0] = 1;
  for (int i = 1; i < 1000005; i++) {
    fact[i] = fact[i - 1] * i % MOD;
  }

  cin >> n >> m;
  lint ans = 0;
  for (int pivot = 1; pivot < n - 1; pivot++) {
    lint pick_numbers = Choose(m, n - 1);
    lint pick_left = Choose(n - 2, pivot); // maximum is forced to be pivot, there is n-2 left
    ans += pick_numbers * pick_left % MOD * pivot % MOD; // pivot ways for duplicate number
    ans %= MOD;
  }

  cout << ans << "\n";
  return 0;
}