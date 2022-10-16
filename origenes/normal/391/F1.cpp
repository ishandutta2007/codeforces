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

const int maxn = 4123456;

ll p[maxn], q[maxn];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  FOR(i, 1, n) scanf("%lld", p + i);
  int tail = 0;
  stack<ll> l, r;
  for (int i = 1, j = 1; i <= n; i = j + 1, j = i) {
    while (j <= n && p[j + 1] >= p[j]) j++;
    while (!l.empty() && p[i] <= l.top()) {
      q[++tail] = r.top() - l.top();
      r.pop(); l.pop();
    }
    l.emplace(p[i]);
    while (!r.empty() && p[j] >= r.top()) {
      q[++tail] = r.top() - l.top();
      r.pop(); l.pop();
    }
    r.emplace(p[j]);
  }
  while (!l.empty()) {
    q[++tail] = r.top() - l.top();
    r.pop(); l.pop();
  }
  chkmin(k, tail);
  nth_element(q + 1, q + k, q + tail + 1, greater<>());
  ll ans = 0;
  FOR(i, 1, k) if (q[i] > 0) ans += q[i];
  printf("%lld", ans);
}