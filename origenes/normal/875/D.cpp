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

const int maxn = 212345;

int n;
int a[maxn], l[maxn], r[maxn];

int main() {
  scanf("%d", &n);
  FOR(i, 1, n) scanf("%d", a + i);
  stack<int> s;
  FOR(i, 1, n) {
    while (!s.empty() && (a[s.top()] | a[i]) == a[i] && a[s.top()] != a[i]) s.pop();
    if (s.empty()) l[i] = i;
    else l[i] = i - s.top();
    s.push(i);
  }
  while (!s.empty()) s.pop();
  ROF(i, n, 1) {
    while (!s.empty() && (a[s.top()] | a[i]) == a[i]) s.pop();
    if (s.empty()) r[i] = n - i + 1;
    else r[i] = s.top() - i;
    s.push(i);
  }
  ll ans = ll(n + 1) * (n) / 2;
  FOR(i, 1, n) ans -= ll(l[i]) * r[i];
  printf("%lld", ans);
}