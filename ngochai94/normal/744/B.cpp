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

int n, ans[1111];
vector<int> v0, v1;

int main() {
  // ios::sync_with_stdio(false);
  cin >> n;
  FOR (i, 1, n) ans[i] = mod;
  REP (ii, 10) {
    v0.clear();
    v1.clear();
    FOR (i, 1, n) {
      if (i & (1 << ii)) v1.pb(i);
      else v0.pb(i);
    }
    if (v1.empty() || v0.empty()) continue;
    cout << v0.size() << endl;
    for (int i: v0) cout << i << ' ';
    cout << endl;
    cout.flush();
    FOR (i, 1, n) {
      int val;
      cin >> val;
      if (i & (1 << ii)) ans[i] = min(ans[i], val);
    }
    cout << v1.size() << endl;
    for (int i: v1) cout << i << ' ';
    cout << endl;
    cout.flush();
    FOR (i, 1, n) {
      int val;
      cin >> val;
      if (!(i & (1 << ii))) ans[i] = min(ans[i], val);
    }
  }
  cout << -1 << endl;
  FOR (i, 1, n) cout << ans[i] << ' ';
  cout << endl;
  cout.flush();
}