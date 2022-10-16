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

const int maxn = 112345;

char S[maxn], T[maxn];
int n, m, q;
int sa[maxn], sb[maxn], ta[maxn], tb[maxn];

int main() {
  scanf("%s%s", S + 1, T + 1);
  n = strlen(S + 1), m = strlen(T + 1);
  FOR(i, 1, n) {
    if (S[i] == 'A') sa[i] = sa[i - 1] + 1;
    sb[i] = sb[i - 1] + (S[i] != 'A');
  }
  FOR(i, 1, m) {
    if (T[i] == 'A') ta[i] = ta[i - 1] + 1;
    tb[i] = tb[i - 1] + (T[i] != 'A');
  }
  scanf("%d", &q);
  while (q--) {
    int ls, rs, lt, rt;
    scanf("%d%d%d%d", &ls, &rs, &lt, &rt);
    int a1 = min(rs - ls + 1, sa[rs]), a2 = min(rt - lt + 1, ta[rt]);
    int b1 = sb[rs] - sb[ls - 1], b2 = tb[rt] - tb[lt - 1];
    if (a1 < a2 || (b1 == b2 && (a1 - a2) % 3 != 0)) {
      putchar('0');
      continue;
    }
    if (b1 > b2 || (b2 - b1) % 2 != 0) {
      putchar('0');
      continue;
    }
    if (!b1 && b2 && a1 == a2) putchar('0');
    else putchar('1');
  }
}