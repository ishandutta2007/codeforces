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

int n, k;
int l[maxn], r[maxn];
bool good[maxn], dup[maxn];
vector<int> seq;

void dfs(int u) {
  if (u == -1) return;
  dfs(l[u]);
  seq.eb(u);
  dfs(r[u]);
}

void dfs(int u, int cost) {
  if (u == -1) return;
  if (cost > k) return;
  if (l[u]) dfs(l[u], cost + 1);
  if (dup[l[u]]) dup[u] = true;
  else if (good[u]) {
    k -= cost;
    dup[u] = true;
  }
  if (dup[u]) dfs(r[u], 1);
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> k;
  string s; cin >> s;
  REP(i, n) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
  }
  dfs(0);
  char last = s[seq.back()];
  ROF(i, n - 2, 0) {
    int now = seq[i], nxt = seq[i + 1];
    if (s[now] != s[nxt]) last = s[nxt];
    if (s[now] < last) good[now] = true;
  }
  dfs(0, 1);
  for (auto i : seq) {
    cout << s[i];
    if (dup[i]) cout << s[i];
  }
}