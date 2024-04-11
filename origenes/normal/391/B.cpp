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

const int maxn = 1123;

vector<int> pos[26];
char s[maxn];

int main() {
  scanf("%s", s + 1);
  int n = strlen(s + 1), ans = 0;
  FOR(i, 1, n) pos[s[i] - 'A'].eb(i);
  REP(i, 26) if (!pos[i].empty()) {
    int cnt = 0, pre = 0;
    for (auto j : pos[i]) {
      if (!pre) {
        pre = j;
        cnt = 1;
      } else if ((j - pre) & 1) {
        cnt++;
        pre = j;
      }
    }
    chkmax(ans, cnt);
  }
  printf("%d", ans);
}