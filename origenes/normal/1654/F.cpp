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

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  int n; cin >> n;
  string s; cin >> s;
  vector<int> id(1 << n);
  vector<int> t1(all(s)), t2(1 << n);
  iota(all(id), 0);
  REP(i, n) {
    int mask = 1 << i;
    auto cmp = [&](int x, int y) {
      if (t1[x] == t1[y]) return t1[mask ^ x] < t1[mask ^ y];
      return t1[x] < t1[y];
    };
    sort(all(id), cmp);
    int now = 0;
    REP(j, 1 << n) {
      if (!j || cmp(id[j - 1], id[j])) t2[id[j]] = ++now;
      else t2[id[j]] = now;
    }
    t1 = t2;
  }
  int k = id[0];
  REP(i, 1 << n) cout << s[i ^ k];
}