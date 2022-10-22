#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int up[200005],ud[200005],n,fa[200005],f[200005];
V<int> v[200005];
void dfs1(int p){
	ud[p]=f[p];
	for(int u:v[p])if(u!=fa[p]){
		fa[u]=p;
		dfs1(u);
		ud[p]+=max(0,ud[u]);
	}
}
void dfs2(int p){
	int t=up[p];
	for(int u:v[p])if(u!=fa[p])t+=max(0,ud[u]);
	for(int u:v[p])if(u!=fa[p])up[u]=f[u]+max(0,t-max(ud[u],0)),dfs2(u);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		f[i]=x?1:-1;
	}
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs1(1);
	up[1]=f[1];dfs2(1);
	FOR(i,1,n){
		cout<<ud[i]+up[i]-f[i]<<' ';
	}
	RE 0;
}