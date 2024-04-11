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

const int maxn = 112;

int t, n;
char s[maxn];

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%s", &n, s + 1);
    int lo = n + 1, hi = -1;
    FOR(i, 1, n) if (s[i] == '>') {
      lo = i;
      break;
    }
    ROF(i, n, 1) if (s[i] == '<') {
      hi = i;
      break;
    }
    printf("%d\n", min(lo - 1, n - hi));
  }
}