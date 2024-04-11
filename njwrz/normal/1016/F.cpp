#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
V<P<int,int> > v[300005];
int n,m,dis[300005];
int p[300005],len,l,node[300005];
bool f[300005];
void dfs(int x,int y){
	p[++len]=x;
	if(x==n){
		l=len;
		FOR(i,1,len)node[i]=p[i];
	}
	for(auto u:v[x])if(u.F!=y){
		dis[u.F]=dis[x]+u.S;
		dfs(u.F,x);
	}
	len--;
}
int siz[300005];
int dep[300005],add;
void dfs2(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u.F!=y&&!f[u.F]){
		dfs2(u.F,x);
		siz[x]+=siz[u.F];
		gmax(dep[x],dep[u.F]+u.S);
	}
}
int to[300005],ma[300005],m2[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,2,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	dfs(1,-1);
	FOR(i,1,l)f[node[i]]=1;
	FOR(i,1,l)dfs2(node[i],-1);
	int sum=0;
	FOR(i,1,l){
		if(siz[node[i]]>=3){
			add=dis[n];
		}
		if(i>1){
			for(auto u:v[node[i]])if(u.F==node[i-1]){
				to[i]=u.S;sum+=u.S;
			}
		}
		ma[i]=max(ma[i-1],sum+dep[node[i]]);
	}
	sum=0;
	for(int i=l;i>=1;i--){
		sum+=to[i+1];
		m2[i]=max(m2[i+1]+to[i+1],sum+dep[node[i]]);
	}
	FOR(i,2,l){
		if(dep[node[i-1]]!=0||dep[node[i]]!=0)gmax(add,ma[i-1]+m2[i]);
		if(i>2)gmax(add,ma[i-2]+m2[i]);
	}
	FOR(i,1,m){
		int x;
		cin>>x;
		cout<<min(dis[n],add+x)<<'\n';
	}
	RE 0;
}