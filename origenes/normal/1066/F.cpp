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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

const int maxn = 212345;

map<int, vector<pii>> mmap;
ll dp[maxn][2];
int n;

inline int dis(pii a, pii b) {
  return abs(a._1 - b._1) + abs(a._2 - b._2);
}

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    mmap[max(x, y)].eb(x, y);
  }
  for (auto &vec : mmap) sort(all(vec._2), [](pii a, pii b) { return a._1 < b._1  || a._2 > b._2; });
  mmap[0].eb(0, 0);
  auto pre = mmap.begin();
  int i = 0;
  for (const auto &now : mmap) {
    if (!i) {
      i++;
      continue;
    }
    ll inc = dis(now._2.front(), now._2.back());
    dp[i][0] = inc + min(dp[i - 1][0] + dis(pre->_2.front(), now._2.back()), dp[i - 1][1] + dis(pre->_2.back(), now._2.back()));
    dp[i][1] = inc + min(dp[i - 1][0] + dis(pre->_2.front(), now._2.front()), dp[i - 1][1] + dis(pre->_2.back(), now._2.front()));
    i++, pre++;
  }
  printf("%lld", min(dp[i - 1][0], dp[i - 1][1]));
}