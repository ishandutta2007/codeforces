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
const char way[] = "AWDS";
const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};

int T, n;
char s[maxn];
int xmx[maxn], xmn[maxn], ymx[maxn], ymn[maxn];

inline ll cal(ll x1, ll y1, ll x2, ll y2) {
  return (x2 - x1 + 1) * (y2 - y1 + 1);
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    n = strlen(s);
    xmx[n] = xmn[n] = ymx[n] = ymn[n] = 0;
    ROF(i, n - 1, 0) {
      int id;
      if (s[i] == 'A') id = 0;
      else if (s[i] == 'W') id = 1;
      else if (s[i] == 'D') id = 2;
      else id = 3;
      xmn[i] = min(0, xmn[i + 1] + dx[id]);
      xmx[i] = max(0, xmx[i + 1] + dx[id]);
      ymn[i] = min(0, ymn[i + 1] + dy[id]);
      ymx[i] = max(0, ymx[i + 1] + dy[id]);
    }
    ll ans = cal(xmn[0], ymn[0], xmx[0], ymx[0]);
    ll x = 0, x1 = 0, x2 = 0, y = 0, y1 = 0, y2 = 0;
    REP(i, n) {
      int id;
      if (s[i] == 'A') id = 0;
      else if (s[i] == 'W') id = 1;
      else if (s[i] == 'D') id = 2;
      else id = 3;
      x += dx[id], y += dy[id];
      chkmin(x1, x); chkmax(x2, x);
      chkmin(y1, y); chkmax(y2, y);
      REP(j, 4) {
        ll xx1 = min(x1, x + dx[j] + xmn[i + 1]);
        ll xx2 = max(x2, x + dx[j] + xmx[i + 1]);
        ll yy1 = min(y1, y + dy[j] + ymn[i + 1]);
        ll yy2 = max(y2, y + dy[j] + ymx[i + 1]);
        chkmin(ans, cal(xx1, yy1, xx2, yy2));
      }
    }
    printf("%lld\n", ans);
  }
}