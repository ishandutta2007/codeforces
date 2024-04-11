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

const int maxn = 512;

int n;
int a[maxn], b[maxn];

void solve() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  FOR(i, 1, n) scanf("%d", b + i);
  if (n % 2 == 1 && a[n / 2 + 1] != b[n / 2 + 1]) {
    puts("No");
    return;
  }
  vector<pii> va, vb;
  FOR(i, 1, n / 2) {
    if (a[i] > a[n - i + 1]) swap(a[i], a[n - i + 1]);
    va.eb(a[i], a[n - i + 1]);
    if (b[i] > b[n - i + 1]) swap(b[i], b[n - i + 1]);
    vb.eb(b[i], b[n - i + 1]);
  }
  sort(all(va)); sort(all(vb));
  puts(va == vb ? "Yes" : "No");
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}