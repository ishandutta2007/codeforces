#include <bits/stdc++.h>

#define Task "E"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100, INF = (1 << 30);

int n, k, dem = 0;
vector <int> sl[N];
pair <int, int> limit[N];
int a[N];
int dd[N];
int in[N];

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    if (s == "?") {
      continue;
    }
    a[i] = atoi(&s[0]);
    dd[i] = 1;
  }
  for (int i = 1; i <= n; i++) limit[i] = make_pair(-INF, INF);
  for (int i = 1; i <= n; i++) {
    if (!dd[i]) {
      if (i <= k) {
        in[i] = ++dem;
        sl[dem].push_back(i);
      } else {
        if (!dd[i - k]) {
          in[i] = in[i - k];
          sl[in[i]].push_back(i);
        } else {
          in[i] = ++dem;
          sl[dem].push_back(i);
          limit[dem].first = a[i - k] + 1;
        }
      }
    } else {
      if (i > k) {
        if (!dd[i - k]) {
          limit[in[i - k]].second = a[i] - 1;
        } else {
          if (a[i] <= a[i - k]) {
            cout << "Incorrect sequence";
            return 0;
          }
        }
      }
    }
  }
  for (int i = 1; i <= dem; i++) {
    int  need, l, r, high, low;
    long long pool;
    l = limit[i].first;
    r = limit[i].second;
    pool = 1ll * r - l + 1;
    need = sl[i].size();
    if (pool < need) {
      cout << "Incorrect sequence";
      return 0;
    }
    if (l >= 0) {
      for (int j = 0; j < need; j++) {
        a[sl[i][j]] = l++;
      }
      continue;
    }
    if (r <= 0) {
      for (int j = need - 1; j >= 0; j--) {
        a[sl[i][j]] = r--;
      }
      continue;
    }
    low = -(need - 1) / 2;
    high = -low + (need % 2 == 0);
    if (l > low) {
      for (int j = 0; j < need; j++) {
        a[sl[i][j]] = l++;
      }
      continue;
    }
    if (r < high) {
      for (int j = need - 1; j >= 0; j--) {
        a[sl[i][j]] = r--;
      }
      continue;
    }
    for (int j = 0; j < need; j++) {
      a[sl[i][j]] = low++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}