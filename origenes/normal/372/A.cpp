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

const int maxn = 512345;

int n;
int s[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", s + i);
  sort(s + 1, s + n + 1);
  int j = (n + 1) / 2, ans = n;
  FOR(i, 1, n / 2) {
    while (j <= n && s[i] * 2 > s[j]) j++;
    if (j <= n) ans--, j++;
  }
  printf("%d", ans);
}