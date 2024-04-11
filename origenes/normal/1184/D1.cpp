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
  int n, k, m, t;
  cin >> n >> k >> m >> t;
  vector<int> lis(n);
  lis[k - 1] = 1;
  while (t--) {
    int op, i;
    cin >> op >> i;
    if (op) {
      i--;
      lis.insert(lis.begin() + i, 0);
    } else {
      bool flag = false;
      REP(j, i) if (lis[j]) flag = true;
      vector<int> now;
      if (!flag) now = vector<int>(lis.begin() + i, lis.end());
      else now = vector<int>(lis.begin(), lis.begin() + i);
      swap(now, lis);
    }
    REP(j, int(lis.size())) if (lis[j]) {
      cout << lis.size() << ' ' << j + 1 << '\n';
      break;
    }
  }
}