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

int ask(const string &s) {
  cout << "? " << s << endl;
  int ret; cin >> ret;
  return ret;
}

int main() {
  int n, m;
  cin >> n >> m;
  string s(m, '0');
  vector<pii> edges(m);
  REP(i, m) {
    s[i] = '1';
    edges[i] = {ask(s), i};
    s[i] = '0';
  }
  sort(all(edges));
  vector<int> sum(m + 1);
  REP(i, m) {
    s[edges[i]._2] = '1';
    sum[i + 1] = ask(s);
  }
  int ans = 0;
  REP(i, m) if (sum[i + 1] == sum[i] + edges[i]._1) ans += edges[i]._1;
  cout << "! " << ans << endl;
}