#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 250005;

int fact[N];

main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  fact[0] = 1;
  for(int i = 1; i < N; ++i) fact[i] = fact[i - 1] * i % m;

  int ans = 0;
  for(int len = 1; len <= n; ++len) {
    int wei = n - len + 1;
    int cost = fact[n - len] * fact[len] % m;
    ans += (wei * wei % m) * cost % m;
    ans %= m;
  }

  cout << ans << endl;

  return 0;
}