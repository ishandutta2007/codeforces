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

int n, m, k, u, v, ans, vst[1111], gov[1111];
vector<int> adj[1111], cluster;
queue<int> q;

int main() {
  // ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  REP (i, k) cin >> gov[i];
  REP (i, m) {
    cin >> u >> v;
    adj[v].pb(u);
    adj[u].pb(v);
  }
  int fre = n;
  REP (i, k) {
    v = gov[i];
    assert(vst[v] == 0);
    q.push(v);
    vst[v] = 1;
    int cnt = 0;
    while (!q.empty()) {
      cnt++;
      u = q.front();
      q.pop();
      for (int nex: adj[u]) if (!vst[nex]) {
        vst[nex] = 1;
        q.push(nex);
      }
    }
    cluster.pb(cnt);
    fre -= cnt;
  }
  // BUG(fre);
  sort(cluster.begin(), cluster.end());
  v = cluster.back();
  cluster.pop_back();
  cluster.pb(v + fre);
  for (int i: cluster) ans += i * (i - 1) / 2;
  cout << ans - m;
  // PR(cluster, 0, cluster.size());
}