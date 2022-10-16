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
  int n, q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    vector<pii> tab(n + 1);
    FOR(i, 1, n) {
      int a, f;
      scanf("%d%d", &a, &f);
      tab[a]._1++;
      if (!f) tab[a]._2++;
    }
    vector<vector<int>> cnt(n + 1);
    FOR(i, 1, n) if (tab[i]._1) cnt[tab[i]._1].eb(i);
    int ans = 0, zero = 0;
    set<pair<pii, int>> s; // zero, tot, id
    ROF(i, n, 1) {
      decltype(s) tmp;
      for (auto it : s) {
        if (it._1._1) it._1._1--;
        it._1._2--;
        if (it._1._2) tmp.emplace(it);
      }
      for (auto it : cnt[i]) tmp.emplace(mp(tab[it]._2, tab[it]._1), it);
      if (!tmp.empty()) {
        auto now = *tmp.begin(); tmp.erase(tmp.begin());
        ans += now._1._2, zero += now._1._1;
      }
      s = tmp;
    }
    printf("%d %d\n", ans, ans - zero);
  }
}