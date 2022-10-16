#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 2000100
#define pb(a) push_back(a)
#define N 2000500
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

namespace n5 {
//*/
int low[N],vis[N],scomp[N],scompNum,I;
vector<int> adj[N]; stack<int> verts;
void scc(int u) { low[u] = vis[u] = ++I; verts.push(u);
  for (int v : adj[u]) {
    if (!vis[v]) scc(v);
    if (scomp[v] == -1) low[u] = min(low[u], low[v]); }
  if (vis[u] <= low[u]) { int v;
    do { v=verts.top(); verts.pop(); scomp[v]=scompNum; } while (v != u);
    ++scompNum; }}
void get_scc(int n) { memset(vis,0,sizeof vis); memset(scomp,-1,sizeof scomp);
  scompNum=I=0; for (int i=0; i<n; ++i) if (!vis[i]) scc(i); }
}
int arr[MAX];
int  sz[MAX];
void deal(){
	int n,m;
	cin>>n>>m;
	fori(m){
		int k;
		cin>>k;
		fori(k)
			cin>>arr[i], --arr[i];
		fori(k)
			n5::adj[arr[i]].pb(arr[(i+1)%k]);
	}
	n5::get_scc(n);
	fori(n)
		sz[n5::scomp[i]]++;
	fori(n)
		cout<<sz[n5::scomp[i]]<<' ';
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





/* 
1
7 
...O...
..O.O..
.O.O.O.
O.O.O.O
.....O.
.......
.......




*/