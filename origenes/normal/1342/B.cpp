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

const int maxn = 112;

char t[maxn];

void solve() {
  scanf("%s", t + 1);
  int n = strlen(t + 1);
  bool same = true;
  FOR(i, 2, n) if (t[i] != t[1]) same = false;
  if (same) {
    puts(t + 1);
    return;
  }
  char ch[5];
  ch[1] = t[1], ch[0] = (t[1] - '0' ^ 1) + '0';
  int cnt = 1;
  FOR(i, 1, n) {
    if (t[i] != ch[cnt & 1]) putchar(ch[cnt & 1]), cnt++;
    putchar(t[i]);
    cnt++;
  }
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}