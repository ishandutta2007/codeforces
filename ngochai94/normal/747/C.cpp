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

int n, q, t, k, d, lis[111];

int main() {
  // ios::sync_with_stdio(false);
  cin >> n >> q;
  while (q--) {
    cin >> t >> k >> d;
    int cnt = 0;
    FOR (i, 1, n) if (lis[i] <= t) cnt++;
    if (cnt < k) {
      cout << -1 << endl;
      continue;
    }
    int ans = 0;
    cnt = 0;
    FOR (i, 1, n) if (lis[i] <= t) {
      if (cnt == k) break;
      ans += i;
      lis[i] = t + d;
      cnt++;
    }
    cout << ans << endl;
  }
}