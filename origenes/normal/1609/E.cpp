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

struct Seg {
  int l, r;
  int c[3][3];
} T[maxn << 2];

string s;

void push_up(int o) {
  REP(i, 3) T[o].c[i][i] = T[o << 1].c[i][i] + T[o << 1 | 1].c[i][i];
  REP(i, 3) FOR(j, i + 1, 2) {
    T[o].c[i][j] = 1e9;
    FOR(k, i, j) chkmin(T[o].c[i][j], T[o << 1].c[i][k] + T[o << 1 | 1].c[k][j]);
  }
}

void build(int o, int l, int r) {
  T[o].l = l, T[o].r = r;
  if (l == r) T[o].c[s[l] - 'a'][s[l] - 'a'] = 1;
  else {
    int mi = l + r >> 1;
    build(o << 1, l, mi);
    build(o << 1 | 1, mi + 1, r);
    push_up(o);
  }
}

void update(int o, int x, int v) {
  if (T[o].l == T[o].r) {
    reset(T[o].c, 0);
    T[o].c[v][v] = 1;
    return;
  }
  int mi = T[o].l + T[o].r >> 1;
  if (x <= mi) update(o << 1, x, v);
  else update(o << 1 | 1, x, v);
  push_up(o);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n, q; cin >> n >> q;
  cin >> s;
  build(1, 0, n - 1);
  while (q--) {
    int pos; string ch;
    cin >> pos >> ch;
    update(1, pos - 1, ch[0] - 'a');
    cout << *min_element(T[1].c[0], T[1].c[0] + 3) << '\n';
  }
}