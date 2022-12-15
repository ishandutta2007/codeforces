#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for (int i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(int)(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, val, ans[111];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  while (m--) {
    cin >> val;
    FOR (i, val, n) if (!ans[i]) ans[i] = val;
  }
  FOR (i, 1, n) cout << ans[i] << ' ';
}