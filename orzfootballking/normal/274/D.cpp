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
int n,m;
int vis[500005];
V<int> g[500005],ans;
void dfs(int p){
	if(vis[p]==1){
		cout<<-1;exit(0);
	}
	if(vis[p]==2)RE;
	vis[p]=1;
	for(auto u:g[p])dfs(u);
	vis[p]=2;
	if(p<=m)ans.PB(p);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int now=m+1,x;
	FOR(i,1,n){
		V<P<int,int> > v;
		FOR(j,1,m){
			cin>>x;
			if(x!=-1)v.PB(MP(x,j));
		}
		sort(ALL(v));
		if(!v.size())continue;
		rep(j,0,v.size()){
			if(j!=0&&v[j].F!=v[j-1].F)now++;
			g[now].PB(v[j].S);
			g[v[j].S].PB(now+1);
		}
		now+=2;
	}
	FOR(i,1,m)if(!vis[i])dfs(i);
	reverse(ALL(ans));
	for(auto u:ans)cout<<u<<' ';
	RE 0;
}