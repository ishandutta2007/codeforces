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

int n, k, lis[3333], vst[3333][3333], ans, canLive[3333], canDie[3333], all;

int main(){
  ios::sync_with_stdio(0);
  cin >> n >> k;
  FOR (i, 1, n) cin >> lis[i];
  canLive[n + 1] = 1;
  FORD (i, n, 2) {
    if (lis[i] == 100) canLive[i] = 0;
    else canLive[i] = canLive[i + 1];
    if (lis[i]) canDie[i] = 1;
    else canDie[i] = canDie[i + 1];
  }
  reset(vst, 55);
  vst[1][2] = 0;
  // ans = 1;
  FOR (fir, 1, n - 1) FOR (sec, fir + 1, n) if (vst[fir][sec] <= k) {
    ans++;
    // cout << fir << ' ' << sec << endl;
    if (lis[fir] && canLive[sec]) vst[fir][sec + 1] = min(vst[fir][sec + 1], 1 + vst[fir][sec]);
    if (lis[fir] && canDie[sec]) vst[sec + 1][sec + 2] = min(vst[sec + 1][sec + 2], 1 + vst[fir][sec]);
    if (lis[fir] != 100 && canDie[sec]) vst[sec][sec + 1] = min(vst[sec][sec + 1], 1 + vst[fir][sec]);
  }
  if (vst[n + 1][n + 2] <= k) ans++;
  FOR (fir, 1, n) if (vst[fir][n + 1] <= k) ans++;
  cout << ans;
}