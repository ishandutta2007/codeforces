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

char s[maxn];
int one[maxn], zero[maxn];

void solve() {
  scanf("%s", s + 1);
  int n = strlen(s + 1);
  FOR(i, 1, n) {
    one[i] = one[i - 1];
    zero[i] = zero[i - 1];
    if (s[i] == '0') zero[i]++;
    else one[i]++;
  }
  int ans = n;
  REP(b, n + 1) {
    chkmin(ans, one[b] + zero[n] - zero[b]);
    chkmin(ans, zero[b] + one[n] - one[b]);
  }
  printf("%d\n", ans);
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}