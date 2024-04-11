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
V<int> v[80005];
int siz[80005],n;
__int128 ans;
void dfs(int x,int y){
	siz[x]=1;
	__int128 t=0;
	for(auto u:v[x])if(u!=y){
		dfs(u,x);
		t+=1ll*siz[x]*(siz[u]);
		siz[x]+=siz[u];
	}
	ans=ans-t*t;
	ans=ans-t*(n-siz[x])*siz[x]*2;
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ans=n;
	ans=ans*(n-1);
	ans=ans*n;
	ans=ans*(n-1);
	ans=ans/4;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);
	ll ts=ans;
	cout<<ts;
	RE 0;
}