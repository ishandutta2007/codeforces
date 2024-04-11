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

const int maxn = 312345;

pii s[maxn];
int t[maxn];
int n;

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", &s[i]._1);
    s[i]._2 = i;
  }
  FOR(i, 1, n) scanf("%d", t + i);
  sort(s + 1, s + n + 1);
  sort(t + 1, t + n + 1);
  stack<pii> q;
  vector<tuple<int, int, int>> ans;
  FOR(i, 1, n) {
    int dis = t[i] - s[i]._1;
    if (!dis) continue;
    if (dis < 0) {
      while (!q.empty()) {
        int idx = q.top()._1, r = q.top()._2; q.pop();
        if (r < 0) {
          puts("NO");
          return 0;
        }
        if (dis + r > 0) {
          ans.eb(idx, s[i]._2, -dis);
          r += dis;
          dis = 0;
          q.emplace(idx, r);
          break;
        }
        if (dis + r == 0) {
          ans.eb(idx, s[i]._2, -dis);
          dis = 0;
          break;
        }
        ans.eb(idx, s[i]._2, r);
        dis += r;
      }
      if (!dis) continue;
      puts("NO");
      return 0;
    } else {
      q.emplace(s[i]._2, dis);
    }
  }
  if (!q.empty()) {
    puts("NO");
    return 0;
  }
  puts("YES");
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d %d %d\n", get<0>(it), get<1>(it), get<2>(it));
}