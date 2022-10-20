#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m;
pair <int, int> a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  int res=  0;
  for (int i = 1; i < m; i++) {
    int dis = a[i + 1].first - a[i].first;
    int delh = (abs(a[i + 1].second - a[i].second));
    if (dis < delh) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    int thua = dis - delh;
    thua /= 2;
    res = max(res, thua + max(a[i].second, a[i + 1].second));
  }
  res = max(res, a[1].second + a[1].first - 1);
  res = max(res, a[m].second + n - a[m].first);
  cout << res << endl;
  return 0;
}