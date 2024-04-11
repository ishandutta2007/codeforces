#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 
const int N=4e5+5;

int n,m,scc,h[N],b[N],c[N],ans[N];
int zero[N],height[N];
VI e[N],flip[N];
bool mark[N];

void dfs(int u,int f,int dis,int desk) {
	mark[u]=true;
	if (dis<0) dis=0;
	// bug(u),bug(dis),debug(desk);
	if (dis==0) ans[u]=max(ans[u],h[u]*2-desk);
	
	for (auto v:e[u])  {
		if (v==f) continue;
		if (h[v]==desk||h[v]<h[u]) continue;
		
		dfs(v,u,dis+(h[u]==h[v]?1:-1),desk);
	}
}

int main() {
	queue<int> Q;
	
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",&zero[i]);
		if (zero[i]==1) h[i]=0,Q.push(i);
		else h[i]=inf;
	}
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v),e[v].pb(u);	
	}
	
	while (!Q.empty()) {
		int u=Q.front(); Q.pop();
		for (auto v:e[u]) {
			if (h[v]>h[u]+1) h[v]=h[u]+1,Q.push(v);
		}
	}
	
	rep(i,1,n+1) {
		for (auto x:e[i]) if (h[i]==h[x]) {
			flip[h[i]].pb(i);
			break;
		}
	}
	
	rep(i,1,n+1) ans[i]=h[i];
	rep(i,0,n+1) if (SZ(flip[i])) {
		rep(j,0,n+1) mark[j]=false;
		for (auto u:flip[i]) dfs(u,0,0,i);
	}
	rep(i,1,n+1) printf("%d ",ans[i]);
	puts("");
	return 0;	
}