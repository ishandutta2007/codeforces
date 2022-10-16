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

int n, k;
char s[maxn];
int x[maxn];

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  reset(x, 0x3f);
  REP(i, n) {
    int pre = (i - 1 + n) % n, nxt = (i + 1) % n;
    if (s[i] == s[pre] || s[i] == s[nxt]) {
      x[i] = 0;
      continue;
    }
  }
  int st = 0;
  while (st < n && x[st]) st++;
  REP(_i, n) {
    int i = (st + _i) % n;
    if (!x[i]) continue;
    int pre = (i - 1 + n) % n;
    chkmin(x[i], x[pre] + 1);
  }
  REP(_i, n) {
    int i = (st - _i + n) % n;
    if (!x[i]) continue;
    int nxt = (i + 1) % n;
    chkmin(x[i], x[nxt] + 1);
  }
  REP(i, n) {
    int op = min(x[i], k);
    if (op & 1) s[i] = s[i] == 'W' ? 'B' : 'W';
    putchar(s[i]);
  }
}