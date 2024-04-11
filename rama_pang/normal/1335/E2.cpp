#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int nxt[200005];
int prv[200005];
int ls[205];
int cnt[200005][205];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n + 5);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i <= n + 1; i++) {
      for (int j = 0; j <= 200; j++) {
        cnt[i][j] = 0;
      }
    }
    for (int j = 0; j <= 200; j++) ls[j] = 0;
    for (int i = 1; i <= n; i++) {
      prv[i] = ls[a[i]];
      ls[a[i]] = i;
    }
    for (int i = 0; i <= 200; i++) {
      ls[i] = n + 1;
    }
    for (int i = n; i >= 1; i--) {
      nxt[i] = ls[a[i]];
      ls[a[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= 200; j++) {
        cnt[i][j] = cnt[i - 1][j];
      }
      cnt[i][a[i]]++;
    }

    for (int p = 1; p <= 200; p++) {
      int l = 1;
      while (l <= n && a[l] != p) l++;
      int r = n;
      while (r >= 1 && a[r] != p) r--;
      if (l > r) continue;
      int c = 1;
      while (l < r) {
        for (int j = 1; j <= 200; j++) {
          ans = max(ans, 2 * c + cnt[r - 1][j] - cnt[l][j]);
        }
        c++;
        l = nxt[l];
        r = prv[r];
      }
    }

    for (int j = 1; j <= 200; j++) {
      ans = max(ans, cnt[n][j]);
    }

    cout << ans << "\n";
  }

}