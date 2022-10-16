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

void solve() {
  int n; cin >> n;
  vector<int> a(n), cnt(n + 1);
  REP(i, n) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  auto b = a;
  sort(all(b), [&](int x, int y) { return cnt[x] == cnt[y] ? x < y : cnt[x] > cnt[y]; });
  map<int, queue<int>> cyc;
  vector<bool> vis(n);
  REP(i, n) {
    int now = b[i];
    if (i + cnt[now] >= n || vis[i + cnt[now]]) cyc[now].emplace(b[0]);
    else {
      cyc[now].emplace(b[i + cnt[now]]);
      vis[i + cnt[now]] = true;
    }
  }
  REP(i, n) {
    cout << cyc[a[i]].front() << ' ';
    cyc[a[i]].pop();
  }
  cout << '\n';
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int T; cin >> T;
  while (T--) solve();
}