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

const int maxn = 112345;

int a[maxn], n, q, cnt[maxn];
char op[5];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, 100000) cnt[a[i]]++;
  set<pii> s;
  FOR(i, 1, 100000) if (cnt[i]) s.emplace(-cnt[i], i);
  scanf("%d", &q);
  while (q--) {
    int x;
    scanf("%s %d", op, &x);
    s.erase(mp(-cnt[x], x));
    if (op[0] == '+') cnt[x]++;
    else cnt[x]--;
    if (cnt[x]) s.emplace(-cnt[x], x);
    if (!s.empty()) {
      if (-s.begin()->_1 >= 8) {
        puts("YES");
        continue;
      }
      if (-s.begin()->_1 < 4) {
        puts("NO");
        continue;
      }
      if (-s.begin()->_1 >= 6) {
        auto it = s.begin(); ++it;
        puts(it != s.end() && -it->_1 >= 2 ? "YES" : "NO");
        continue;
      }
      auto it1 = s.begin(); ++it1;
      if (it1 == s.end() || -it1->_1 < 2) {
        puts("NO");
        continue;
      }
      if (-it1->_1 >= 4) {
        puts("YES");
        continue;
      }
      auto it2 = it1; it2++;
      puts(it2 != s.end() && -it2->_1 >= 2 ? "YES" : "NO");
    } else puts("NO");
  }
}