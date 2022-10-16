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

const int maxn = 1123456;

int n;
char s[maxn], t[maxn];

int main() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  int cnt = 0;
  FOR(i, 1, n) {
    if (s[i] == '0') cnt++;
    else cnt--;
    if (t[i] == '0') cnt--;
    else cnt++;
  }
  if (cnt) {
    puts("-1");
    return 0;
  }
  int ans[2] = {};
  FOR(i, 1, n) if (s[i] != t[i]) {
    if (s[i] == '0') {
      ans[0]++;
      if (ans[1] > 0) ans[1]--;
    } else {
      ans[1]++;
      if (ans[0] > 0) ans[0]--;
    }
  }
  printf("%d", ans[0] + ans[1]);
}