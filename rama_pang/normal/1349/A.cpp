#include <bits/stdc++.h>
using namespace std;
using lint = long long;




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) cin >> i;

  const int MAXN = 200005;
  vector<int> divis(MAXN);
  vector<int> comp(MAXN, 0);
  iota(begin(divis), end(divis), 0);

  for (int i = 2; i < MAXN; i++) {
    if (!comp[i]) {
      for (int j = i + i; j < MAXN; j += i) {
        divis[j] = min(divis[j], i);
        comp[j] = 1;
      }
    }
  }

  vector<vector<int>> ls(MAXN);
  map<int, int> primes;
  for (int i = 0; i < n; i++) {
    int j = a[i];
    primes.clear();
    while (j > 1) {
      primes[divis[j]]++;
      j /= divis[j];
    }
    // cout << a[i] << ":\n";
    for (auto &p : primes) {
      // cout << p.first << " " << p.second << "\n";
      ls[p.first].emplace_back(p.second);
    }
  }
  // cout << "ans\n";
  lint ans = 1;
  for (int i = 0; i < MAXN; i++) {
    sort(begin(ls[i]), end(ls[i]));
    int zeroes = n - int(ls[i].size());
    if (zeroes >= 2) continue;
    if (zeroes == 1) {
      for (int j = 0; j < ls[i][0]; j++) {
        ans *= i;
      }
    }
    if (zeroes == 0) {
      for (int j = 0; j < ls[i][1]; j++) {
        ans *= i;
      }
    }
  }

  cout << ans << "\n";
    

}