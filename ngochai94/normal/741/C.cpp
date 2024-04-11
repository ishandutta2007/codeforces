#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, lis[200005], ans[200005], id[200005], u, v;
queue<int> q;

int main(){
  ios::sync_with_stdio(0);
  cin >> n;
  FOR (i, 1, n) {
    cin >> u >> v;
    lis[u] = v;
    lis[v] = u;
    id[i * 2] = u;
    id[i * 2 + 1] = v;
  }
  FOR (i, 1, 2 * n) if (!ans[i]) {
    ans[i] = 1;
    q.push(i);
    while (!q.empty()) {
      int cur = q.front();
      q.pop();
      int nex = (cur & 1) ? cur + 1 : cur - 1;
      if (!ans[nex]) {
        ans[nex] = 3 - ans[cur];
        q.push(nex);
      }
      nex = lis[cur];
      if (!ans[nex]) {
        ans[nex] = 3 - ans[cur];
        q.push(nex);
      }
    }
  }
  FOR (i, 1, n) {
    cout << ans[id[i * 2]] << ' ' << ans[id[i * 2 + 1]] << endl;
  }
}