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
#define uni(x) (x).erase(unique(all(x)), (x).end());
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
int n;
ll ans;

bool check(int lo, int hi) {
  FOR(i, lo, hi) FOR(j, 1, 9) {
    if (i + 2 * j > hi) break;
    if (s[i] == s[i + j] && s[i] == s[i + 2 * j]) return true;
  }
  return false;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1), ans = ll(n) * (n + 1) / 2;
  FOR(i, 1, n) FOR(j, i, min(i + 9, n)) if (!check(i, j)) ans--;
  printf("%lld", ans);
}