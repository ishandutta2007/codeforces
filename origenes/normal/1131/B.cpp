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

const int maxn = 11234;

int a[maxn], b[maxn], n, ans;

int main() {
  scanf("%d", &n);
  set<int> s;
  FOR(i, 1, n) {
    scanf("%d%d", a + i, b + i);
    if (a[i] <= b[i] && a[i] >= b[i - 1]) s.insert(a[i]);
    if (b[i] <= a[i] && b[i] >= a[i - 1]) s.insert(b[i]);
    if (a[i - 1] >= b[i - 1] && a[i - 1] <= b[i]) s.insert(a[i - 1]);
    if (b[i - 1] >= a[i - 1] && b[i - 1] <= a[i]) s.insert(b[i - 1]);
    ans += max(min(a[i], b[i]) - 1 - max(a[i - 1], b[i - 1]), 0);
  }
  printf("%d", ans + s.size());
}