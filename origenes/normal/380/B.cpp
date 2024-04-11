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

const int maxn = 7123;

int n, m;
int nxt[212345];
vector<int> L[maxn], R[maxn], X[maxn];

int main() {
  scanf("%d%d", &n, &m);
  FOR(i, 1, 2e5) {
    nxt[i] = nxt[i - 1];
    if (i & (i - 1)) nxt[i]++;
    else nxt[i] += 2;
  }
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int t, l, r, x;
      scanf("%d%d%d%d", &t, &l, &r, &x);
      L[t].eb(l), R[t].eb(r), X[t].eb(x);
    } else {
      int t, u;
      scanf("%d%d", &t, &u);
      set<int> s;
      int l = u, r = u;
      while (t <= n) {
        REP(i, int(L[t].size())) if (l <= R[t][i] && r >= L[t][i]) s.emplace(X[t][i]);
        t++;
        l = nxt[l - 1] + 1, r = nxt[r];
      }
      printf("%lu\n", s.size());
    }
  }
}