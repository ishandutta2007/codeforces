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
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

ll n;

int main() {
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2;
    return 0;
  }
  int upp = sqrt(n) + 0.5;
  ll rec = -1;
  FOR(i, 2, upp) if (n % i == 0) {
    rec = i;
    break;
  }
  if (rec == -1) rec = n;
  cout << (n - rec) / 2 + 1;
}