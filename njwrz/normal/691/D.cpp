/*

DP





ll int
 dp 










*/
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
int n,m,a[1000005];
V<int> v[1000005],g[1000005];
int fa[1000005];
int getfa(int x){
	if(x==fa[x])RE x;
	else RE fa[x]=getfa(fa[x]);
}
void merge(int x,int y){
	x=getfa(x);
	y=getfa(y);
	if(x!=y){
		fa[x]=y;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],fa[i]=i;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		merge(x,y);
	}
	FOR(i,1,n)v[getfa(i)].PB(i),g[getfa(i)].PB(a[i]);
	FOR(i,1,n)if(!v[i].empty()){
		sort(ALL(v[i]));
		sort(ALL(g[i]),greater<int>());
		rep(j,0,v[i].size()){
			a[v[i][j]]=g[i][j];
		}
	}
	FOR(i,1,n)cout<<a[i]<<' ';
	RE 0;
}