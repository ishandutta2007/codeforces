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

const int maxn = 212345;

int n, fen[maxn];
map<int, vector<int>> lis_x;

inline int lowbit(int x) {
  return x & -x;
}

int query(int x) {
  int ret = 0;
  while (x > 0) {
    ret += fen[x];
    x -= lowbit(x);
  }
  return ret;
}

int query(int l, int r) {
  return query(r) - query(l - 1);
}

void inc(int x) {
  while (x <= n) {
    fen[x]++;
    x += lowbit(x);
  }
}

int main() {
  scanf("%d", &n);
  vector<int> tab(n);
  REP(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    lis_x[y].eb(x);
    tab[i] = x;
  }
  sort(all(tab));
  uni(tab);
  map<int, int> actual;
  REP(i, int(tab.size())) actual[tab[i]] = i + 1;
  ll ans = 0;
  for (auto it = lis_x.rbegin(); it != lis_x.rend(); it++) {
    sort(all(it->_2));
    for (auto x : it->_2) if (!query(actual[x], actual[x])) inc(actual[x]);
    ans += ll(query(1, actual[it->_2[0]])) * query(actual[it->_2[0]], n);
    FOR(i, 1, int(it->_2.size()) - 1)
      ans += ll(query(actual[it->_2[i - 1]] + 1, actual[it->_2[i]])) * query(actual[it->_2[i]], n);
  }
  printf("%lld", ans);
}