#include <bits/stdc++.h>

#define Task "D"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200100, AMAX = 1000001;
typedef pair < pair <int ,int>, int> pii;

int n, t, x;
int a[N], sl[AMAX];
long long res[N];
pii b[N];

bool cmp(pii u, pii v) {
  if (u.first.first / x != v.first.first / x) {
    return u.first.first / x < v.first.first / x;
  }
  return u.first.second < v.first.second;
}

int main() {
  //fi, fo;
  ios_base::sync_with_stdio(0);
  cin >> n >> t;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= t; i++) {
    cin >> b[i].first.first >> b[i].first.second;
    b[i].second = i;
  }
  x = sqrt(n);
  sort(b + 1, b + t + 1, cmp);
  int l, r;
  long long sum;
  l = r = sum = 0;
  for (int i = 1; i <= t; i++) {
    while (l > b[i].first.first) {
      l--;
      sum += a[l] * (sl[a[l]] * 2 + 1);
      sl[a[l]]++;
    }
    while (r < b[i].first.second) {
      r++;
      sum += a[r] * (sl[a[r]] * 2 + 1);
      sl[a[r]]++;
    }
    while (l < b[i].first.first) {
      sl[a[l]]--;
      sum -= a[l] * (sl[a[l]] * 2 + 1);
      l++;
    }
    while (r > b[i].first.second) {
      sl[a[r]]--;
      sum -= a[r] * (sl[a[r]] * 2 + 1);
      r--;
    }
    res[b[i].second] = sum;
  }
  for (int i = 1; i <= t; i++) {
    cout << res[i] << endl;
  }
  return 0;
}