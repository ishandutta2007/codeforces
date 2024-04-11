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

int ask(vector<int> v) {
  cout << "?";
  for (auto x : v) cout << ' ' << x;
  cout << endl;
  int x, y;
  cin >> x >> y;
  return y;
}

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> cnt;
  FOR(i, 1, k + 1) {
    vector<int> v;
    FOR(j, 1, k + 1) if (j != i) v.eb(j);
    cnt[ask(v)]++;
  }
  cout << "! " << k + 1 - cnt.begin()->_2 << endl;
}