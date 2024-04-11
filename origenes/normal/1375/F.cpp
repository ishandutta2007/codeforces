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

ll a[5];

int main() {
  cin >> a[1] >> a[2] >> a[3];
  cout << "First" << endl;
  int mx = 1, mn = 1;
  FOR(i, 2, 3) {
    if (a[mx] < a[i]) mx = i;
    else if (a[mn] > a[i]) mn = i;
  }
  int other = 6 - mx - mn;
  ll x = a[mx] * 2 - a[mn] - a[other];
  cout << x << endl;
  int id;
  label: cin >> id;
  if (id == mn) {
    cout << a[mx] - a[other] << endl;
  } else if (id == other) {
    cout << a[mx] - a[mn] << endl;
  } else {
    a[mx] += x;
    x = a[mx] * 2 - a[mn] - a[other];
    cout << x << endl;
    goto label;
  }
  cin >> id;
  assert(id == 0);
}