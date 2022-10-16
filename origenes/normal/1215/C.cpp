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

const int maxn = 212345;

int n;
char s[maxn], t[maxn];

int main() {
  scanf("%d", &n);
  scanf("%s%s", s + 1, t + 1);
  int a = 0, b = 0;
  FOR(i, 1, n) {
    if (s[i] == 'a') a++;
    else b++;
    if (t[i] == 'a') a++;
    else b++;
  }
  if ((a & 1) || (b & 1)) {
    puts("-1");
    return 0;
  }
  vector<pii> ans;
  int pre = -1;
  FOR(i, 1, n) if (s[i] == 'a' && t[i] == 'b') {
    if (pre == -1) pre = i;
    else {
      ans.eb(pre, i);
      s[pre] = 'b';
      t[i] = 'a';
      pre = -1;
    }
  }
  pre = -1;
  FOR(i, 1, n) if (s[i] == 'b' && t[i] == 'a') {
    if (pre == -1) pre = i;
    else {
      ans.eb(pre, i);
      s[pre] = 'a';
      t[i] = 'b';
      pre = -1;
    }
  }
  if (pre != -1) {
    FOR(i, 1, n) if (s[i] == 'a' && t[i] == 'b') {
      ans.eb(i, i);
      ans.eb(pre, i);
      break;
    }
  }
  printf("%d\n", int(ans.size()));
  for (auto it : ans) printf("%d %d\n", it._1, it._2);
}