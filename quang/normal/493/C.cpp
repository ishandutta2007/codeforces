#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 200010;

int n, m, sl1, sl2;
pair<int ,int> a[N * 2];
pair<long long, long long> res;

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = 1;
  cin >> m;
  for(int i = 1; i <= m; i++) cin >> a[i + n].first, a[n + i].second = 2;
  sort(a + 1, a + n + m + 1);
  sl1 = sl2 = 0;
  a[m + n + 1] = make_pair(-1, -1);
  res = make_pair(1ll * n * 3, 1ll * m * 3);
  for(int i = 1; i <= n + m; i++) {
    if(a[i].second == 1) sl1++;
    else sl2++;
    if(a[i] != a[i + 1]) {
      long long sum1 = (1ll * sl1 * 2) + (1ll * n - sl1) * 3;
      long long sum2 = (1ll * sl2 * 2) + (1ll * m - sl2) * 3;
      if(res.first - res.second < sum1 - sum2)
        res = make_pair(sum1, sum2);
    }
  }
  long long sum11 = 1ll * n * 2;
  long long sum22 = 1ll * m * 2;
  if(res.first - res.second < sum11 - sum22)
      res = make_pair(sum11, sum22);
  cout << res.first << ":" << res.second;
  return 0;
}