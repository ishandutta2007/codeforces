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

int s, b;
int a[maxn];
pii base[maxn];

int main() {
  scanf("%d%d", &s, &b);
  FOR(i, 1, s) scanf("%d", a + i);
  FOR(i, 1, b) scanf("%d%d", &base[i]._1, &base[i]._2);
  sort(base + 1, base + b + 1);
  FOR(i, 2, b) base[i]._2 += base[i - 1]._2;
  FOR(i, 1, s) {
    int pos = upper_bound(base, base + b + 1, mp(a[i] + 1, -1)) - base - 1;
    printf("%d ", base[pos]._2);
  }
}