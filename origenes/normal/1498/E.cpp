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
  int n; cin >> n;
  vector<int> k(n);
  REP(i, n) cin >> k[i];
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) { return k[i] > k[j]; });
  vector<tuple<int, int, int>> queries;
  REP(i, n) ROF(j, n - 1, i + 1) queries.eb(k[id[i]] - k[id[j]], id[i] + 1, id[j] + 1);
  sort(all(queries), greater<>());
  for (auto [_, i, j] : queries) {
    cout << "? " << i << ' ' << j << endl;
    string resp; cin >> resp;
    if (resp == "Yes") {
      cout << "! " << i << ' ' << j << endl;
      return 0;
    }
  }
  cout << "! 0 0" << endl;
}