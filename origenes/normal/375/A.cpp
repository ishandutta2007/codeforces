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
const int ans[] = {1869, 1968, 1689, 6198, 1698, 1986, 1896};

char s[maxn];

int main() {
  scanf("%s", s);
  int n = strlen(s), zero = 0, sum = 0;
  bool f[10] = {};
  REP(i, n) {
    if (s[i] == '0') zero++;
    else if (s[i] == '1' || s[i] == '6' || s[i] == '8' || s[i] == '9') {
      if (f[s[i] - '0']) {
        putchar(s[i]);
        sum = (sum * 10 + s[i] - '0') % 7;
      } else f[s[i] - '0'] = true;
    } else {
      putchar(s[i]);
      sum = (sum * 10 + s[i] - '0') % 7;
    }
  }
  sum = sum * 10000 % 7;
  printf("%d", ans[(7 - sum) % 7]);
  while (zero--) putchar('0');
}