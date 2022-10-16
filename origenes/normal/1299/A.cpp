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

int n, a[maxn];
int cnt[31];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  REP(i, 31) FOR(j, 1, n) if (a[j] & (1 << i)) cnt[i]++;
  int sp = 1;
  ROF(i, 30, 0) if (cnt[i] == 1) {
    FOR(j, 1, n) if (a[j] & (1 << i)) sp = j;
    break;
  }
  printf("%d ", a[sp]);
  FOR(i, 1, n) if (i != sp) printf("%d ", a[i]);
}