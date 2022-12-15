#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.0000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, m, k, val, ans;

 int main(){
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  while (n--) {
    cin >> val;
    if (val == 1) {
      if (!m) ans++;
      else m--;
    } else {
      if (k) k--;
      else if (m) m--;
      else ans++;
    }
  }
  cout << ans;
}