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

int n;
int ans[15];
char s[maxn];

int main() {
  scanf("%d%s", &n, s + 1);
  FOR(i, 1, n) {
    if (isdigit(s[i])) ans[s[i] - '0'] = 0;
    else {
      if (s[i] == 'L') {
        REP(j, 10) if (!ans[j]) {
          ans[j] = 1;
          break;
        }
      } else {
        ROF(j, 9, 0) if (!ans[j]) {
          ans[j] = 1;
          break;
        }
      }
    }
  }
  REP(i, 10) printf("%d", ans[i]);
}