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
V<P<int,int>> v[100005]; 
int fa[100005][18],d[100005],add[100005],as[100005],l1[100005],l2[100005];
void dfs(int p){
	for(auto u:v[p])if(u.F!=fa[p][0]){
		fa[u.F][0]=p;d[u.F]=d[p]+1;
		dfs(u.F);
	}
}
int lca(int x,int y){
	if(d[x]>d[y])swap(x,y);
	int t=d[y]-d[x];
	FOR(i,0,17){
		if(t&(1<<i)){
			y=fa[y][i];
		}
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
int get(int p){
	int ans=add[p];
	for(auto u:v[p])if(u.F!=fa[p][0]){
		ans+=get(u.F);
	}
	RE as[p]=ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(MP(y,i));
		v[y].PB(MP(x,i));
		l1[i]=x;l2[i]=y;
	}
	dfs(1);
	FOR(i,1,17){
		FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int m;
	cin>>m;
	FOR(i,1,m){
		cin>>x>>y;
		int t=lca(x,y);
		add[t]-=2;
		add[x]++;add[y]++;
	}
	get(1);
	rep(i,1,n){
		if(d[l1[i]]>d[l2[i]])swap(l1[i],l2[i]);
		cout<<as[l2[i]]<<' ';
	}
	RE 0;
}