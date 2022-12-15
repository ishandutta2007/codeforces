#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define PR(x,a,b) {cout << #x << " = "; FOR (_,a,b) cout << x[_] << ' '; cout << endl;}
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, lis[200005], val, odd, even, mino, mine;
unordered_set<int> s;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  int ans = n;
  REP (i, n) {
    cin >> val;
    if (!s.count(val)) {
      s.insert(val);
      if (val % 2 == 0) even++;
      else odd++;
      if (val % 2 == 0 && even > n / 2 || val % 2 == 1 && odd > n / 2) continue;
      lis[i] = val;
      ans--;
    }
  }
  mino = 1;
  mine = 2;
  REP (i, n) if (!lis[i]) {
    if (odd < n / 2) {
      odd++;
      while (s.count(mino)) mino += 2;
      if (mino > m) {
        cout << -1;
        return 0;
      }
      lis[i] = mino;
      mino += 2;
    } else {
      even++;
      while (s.count(mine)) mine += 2;
      if (mine > m) {
        cout << -1;
        return 0;
      }
      lis[i] = mine;
      mine += 2;
    }
  }
  cout << ans << endl;
  REP (i, n) cout << lis[i] << ' ';
}