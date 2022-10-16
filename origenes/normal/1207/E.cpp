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

const int maxn = 100;

int main() {
  vector<int> a(maxn);
  iota(all(a), 1);
  int ans1, ans2;
  cout << '?';
  for (auto it : a) cout << ' ' << it;
  cout << endl;
  cin >> ans1;
  ans1 &= ~((1 << 7) - 1);
  cout << '?';
  for (auto it : a) cout << ' ' << (it << 7);
  cout << endl;
  cin >> ans2;
  ans2 &= (1 << 7) - 1;
  cout << "! " << ans1 + ans2 << endl;
}