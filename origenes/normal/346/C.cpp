#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

int main() {
  int n, a, b, ans = 0;
  scanf("%d", &n);
  vector<int> x(n);
  for (auto &y : x) scanf("%d", &y);
  sort(all(x));
  uni(x);
  n = x.size();
  scanf("%d%d", &a, &b);
  while (a > b) {
    int j = a - 1;
    ROF(i, n - 1, 0) {
      if (x[i] <= a - j) break;
      int now = a - a % x[i];
      if (now >= b && now < j) j = now;
    }
    while (!x.empty() && a - a % x.back() < b) x.pop_back();
    n = x.size();
    a = j;
    ans++;
  }
  printf("%d", ans);
}