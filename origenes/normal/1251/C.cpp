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

const int maxn = 312345;

int n;
char s[maxn];

void solve() {
  queue<int> q[2];
  scanf("%s", s);
  for (int i = 0; s[i]; i++) q[s[i] & 1].emplace(s[i]);
  while (!q[0].empty() && !q[1].empty()) {
    auto u = q[0].front(), v = q[1].front();
    if (u < v) putchar(u), q[0].pop();
    else putchar(v), q[1].pop();
  }
  while (!q[0].empty()) putchar(q[0].front()), q[0].pop();
  while (!q[1].empty()) putchar(q[1].front()), q[1].pop();
  putchar('\n');
}

int main() {
  int T; scanf("%d", &T);
  while (T--) solve();
}