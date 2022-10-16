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

const int maxn = 312345;

char s[maxn];
int n, k;

void solve() {
  scanf("%d%d", &n, &k);
  scanf("%s", s);
  REP(i, k) {
    int f = 0;
    for (int j = i; j < n; j += k) {
      if (s[j] == '0') f |= 1;
      else if (s[j] == '1') f |= 2;
    }
    if (f == 3) {
      puts("NO");
      return;
    }
    if (f == 1) s[i] = '0';
    else if (f == 2) s[i] = '1';
  }
  int c[2] = {};
  REP(i, k) {
    if (s[i] == '?') c[0]++;
    else if (s[i] == '0') c[1]++;
  }
  puts(c[1] <= k / 2 && c[0] + c[1] >= k / 2 ? "YES" : "NO");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}