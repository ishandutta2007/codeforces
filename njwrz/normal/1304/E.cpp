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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int de[200005],n,fa[200005][18];
V<int> v[200005];
void dfs(int p){
	for(auto u:v[p]){
		if(u!=fa[p][0]){
			fa[u][0]=p;
			de[u]=de[p]+1;
			dfs(u);
		}
	}
}
int lca(int x,int y){
	if(de[x]>de[y])swap(x,y);
	int t=de[y]-de[x];
	FOR(i,0,17){
		if((1<<i)&t)y=fa[y][i];
	}
	if(x==y)RE x;
	for(int i=17;i>=0;i--){
		if(fa[x][i]!=fa[y][i]){
			x=fa[x][i];
			y=fa[y][i];
		}
	}
	RE fa[x][0];
}
int dist(int x,int y){
	RE de[x]+de[y]-2*de[lca(x,y)];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	de[1]=1;
	dfs(1);
	FOR(i,1,17){
		FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int a,b,k,q,d;
	cin>>q;
	FOR(i,1,q){
		cin>>x>>y>>a>>b>>k;
		d=dist(a,b);
		if(k>=d&&!((k-d)&1)){
			cout<<"YES\n";continue;
		}
		d=dist(a,x)+dist(y,b)+1;
		if(k>=d&&!((k-d)&1)){
			cout<<"YES\n";continue;
		}
		d=dist(a,y)+dist(b,x)+1;
		if(k>=d&&!((k-d)&1)){
			cout<<"YES\n";
		}else cout<<"NO\n";
	}
	RE 0;
}