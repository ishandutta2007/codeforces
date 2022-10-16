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
const char fi[] = "Monocarp";
const char se[] = "Bicarp";

int n, l, r, tot;
char s[maxn];

int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  FOR(i, 1, n / 2) {
    if (s[i] == '?') l++;
    else tot += s[i] - '0';
  }
  FOR(i, n / 2 + 1, n) {
    if (s[i] == '?') r++;
    else tot -= s[i] - '0';
  }
  if (l == r) puts(tot ? fi : se);
  else if ((l > r && tot > 0) || (l < r && tot < 0)) puts(fi);
  else {
    int ex = 9 * (abs(l - r) / 2);
    puts(abs(tot) == ex ? se : fi);
  }
}