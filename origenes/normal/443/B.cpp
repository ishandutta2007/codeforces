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

const int maxn = 212;

char s[maxn];
int k;

int main() {
  scanf("%s", s + 1);
  scanf("%d", &k);
  int n = strlen(s + 1);
  ROF(i, (n + k) / 2, 1) {
    FOR(j, 1, n + k - 2 * i + 1) {
      bool f = true;
      FOR(kk, j, i + j - 1) if (kk + i <= n && s[kk] != s[kk + i]) {
        f = false;
        break;
      }
      if (f) {
        printf("%d", 2 * i);
        return 0;
      }
    }
  }
}