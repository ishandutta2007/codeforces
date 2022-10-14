#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  const int MAX = 1e6 + 5;
  vector<int> ans(MAX);

  vector<int> primes;
  vector<bool> isprime(MAX, true);
  isprime[1] = false;
  for (int i = 2; i < MAX; i++) {
    if (isprime[i]) {
      primes.emplace_back(i);
    } else {
      continue;
    }
    for (int j = i + i; j < MAX; j += i) {
      isprime[j] = false;
    }
  }

  for (auto p : primes) {
    if (1ll * p * p < MAX) {
      ans[p * p]++;
    }
  }
  for (int i = 1; i < MAX; i++) {
    ans[i] += ans[i - 1];
  }

  for (int i = 1; i < MAX; i++) {
    ans[i] = upper_bound(begin(primes), end(primes), i) - begin(primes) - ans[i] + 1;
  }

  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cout << ans[n] << "\n";
  }
  return 0;
}