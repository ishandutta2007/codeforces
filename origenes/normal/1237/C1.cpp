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

const int maxn = 51234;

int n;
int x[maxn], y[maxn], z[maxn];

int main() {
  scanf("%d", &n);
  map<pii, vector<pii>> XY;
  FOR(i, 1, n) {
    scanf("%d%d%d", x + i, y + i, z + i);
    XY[mp(x[i], y[i])].eb(z[i], i);
  }
  for (auto &now : XY) {
    sort(all(now._2));
    if (now._2.size() == 1) continue;
    int sz = now._2.size();
    for (int i = 0; i < sz - 1; i += 2) printf("%d %d\n", now._2[i]._2, now._2[i + 1]._2);
    if (sz & 1) now._2 = {now._2.back()};
    else now._2.clear();
  }
  map<int, vector<pii>> X;
  for (auto now : XY) if (!now._2.empty()) X[now._1._1].eb(now._1._2, now._2.front()._2);
  for (auto &now : X) {
    sort(all(now._2));
    if (now._2.size() == 1) continue;
    int sz = now._2.size();
    for (int i = 0; i < sz - 1; i += 2) printf("%d %d\n", now._2[i]._2, now._2[i + 1]._2);
    if (sz & 1) now._2 = {now._2.back()};
    else now._2.clear();
  }
  vector<pii> final;
  for (auto now : X) if (!now._2.empty())
    final.eb(now._1, now._2[0]._2);
  sort(all(final));
  int sz = final.size();
  for (int i = 0; i < sz - 1; i += 2) printf("%d %d\n", final[i]._2, final[i + 1]._2);
}