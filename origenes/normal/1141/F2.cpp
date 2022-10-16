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

const int maxa = 212345;
const int maxn = 1512;

map<int, vector<pii>> tab;
int n, a[maxn], s[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", a + i);
    s[i] = s[i - 1] + a[i];
  }
  FOR(i, 1, n) {
    set<int> now;
    FOR(j, i, n) {
      int cur = s[j] - s[i - 1];
      if (!now.count(cur)) tab[cur].eb(j, i);
    }
  }
  vector<pii> ans;
  for (auto &it : tab) {
    auto &lis = it._2;
    sort(all(lis));
    int pre = -1;
    vector<pii> tmp;
    for (auto now : lis) if (now._2 > pre) {
      pre = now._1;
      tmp.eb(now);
    }
    if (tmp.size() > ans.size()) swap(ans, tmp);
  }
  printf("%d\n", int(ans.size()));
  for (auto now : ans) printf("%d %d\n", now._2, now._1);
}