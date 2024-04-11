#include <bits/stdc++.h>
using namespace std;
using lint = long long;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 200005;

int n, k;
int a[MAXN];
lint pref[MAXN];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);

  for (int i = 1; i <= n; i++) {
    pref[i] = a[i] + pref[i - 1];
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << a[i] << " \n"[i == n];
  // }

  lint ans = 1e18;
  lint l = k;
  lint cur = 0;

  map<int, int> freq;
  for (int i = 1; i <= n; i++) {
    freq[a[i]]++;
  }
  for (auto &f : freq) {
    if (f.second >= k) {
      cout << 0 << "\n";
      return 0;
    }
  }

  for (int i = 1; i <= k; i++) {
    if (a[i] < a[k]) {
      cur += a[k] - 1 - a[i];
    }
  }
  cur += k - freq[a[k]];
  ans = min(ans, cur);

  cur = 0;
  for (int i = n - k + 1; i <= n; i++) {
    if (a[i] > a[n - k + 1]) {
      cur += a[i] - a[n - k + 1] - 1;
    }
  }
  cur += k - freq[a[n - k + 1]];
  ans = min(ans, cur);


  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j + 1 <= n && a[j + 1] == a[i]) j++;
    int pv = a[i];

    lint cost = 0;
    cost += 1ll * (pv - 1) * (i - 1) - pref[i - 1];
    cost += (pref[n] - pref[j]) - 1ll * (pv + 1) * (n - j);
    cost += k - freq[pv];
    ans = min(ans, cost);
    i = j;
  }

  cout << ans << "\n";
  return 0;
}