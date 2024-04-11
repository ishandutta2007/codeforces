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

int n, k, lis[200005], dp[200005][2];
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  FOR (i, 1, n) cin >> lis[i];
  int cnt = 0;
  int cur = 0;
  int st = 1;
  while (st <= n && lis[st] >= 0) st++;
  if (st > n) {
    cout << 0;
    return 0;
  }
  FOR (i, st, n) {
    if (lis[i] < 0) {
      cnt++;
      if (cur) {
        v.pb(cur);
        cur = 0;
      }
    } else {
      cur++;
    }
  }
  if (cnt > k) {
    cout << -1;
    return 0;
  }
  cnt = k - cnt;
  sort(v.begin(), v.end());
  int cul = 0;
  int ans1 = 1 + 2 * v.size();
  if (cur) ans1++;
  int ans2 = ans1;
  // BUG(ans2);
  // PR(v, 0, v.size() - 1);
  for (int i: v) {
    cul += i;
    if (cul <= cnt) ans1 -= 2;
  }
  if (cur && cur <= cnt) {
    ans2--;
    cul = cur;
    for (int i: v) {
      cul += i;
      if (cul <= cnt) ans2 -= 2;
    }
  }
  cout << min(ans1, ans2);
}