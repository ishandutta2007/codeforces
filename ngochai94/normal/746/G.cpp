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

int n, t, k, lis[200005], par[200005], head[200005], child[200005], lvl[200005];

int main() {
  ios::sync_with_stdio(false);
  cin >> n >> t >> k;
  lis[0] = 1;
  FOR (i, 1, t) cin >> lis[i];
  int ans = 1;
  head[0] = 1;
  int cur = 2;
  FOR (i, 1, t) {
    head[i] = cur;
    REP (j, lis[i]) {
      par[cur] = (head[i - 1] + j % lis[i - 1]);
      ans++;
      if (!child[par[cur]]) ans--;
      child[par[cur]]++;
      lvl[cur] = i;
      cur++;
    }
  }
  // BUG(ans);
  if (ans > k) {
    cout << -1;
    return 0;
  }
  FOR (i, 2, n) {
    if (ans == k) break;
    int l = lvl[i];
    if (par[i] != head[l - 1]) {
      child[par[i]]--;
      if (!child[par[i]]) {
        ans++;
        // if (ans == k) break;
      }
      par[i] = head[l - 1];
    }
  }
  if (ans - k) cout << -1;
  else {
    cout << n << endl;
    FOR (i, 2, n) cout << i << ' ' << par[i] << endl;
  }
}