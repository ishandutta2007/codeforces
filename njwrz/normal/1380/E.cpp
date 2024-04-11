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
int n,m,a[200005];
V<int> v[200005];
int it[200005];
int ans;
int cost(int x,int y){
	if(x<1||y>n)RE 0;
	RE a[x]!=a[y];
}
void merge(int x,int y){
	for(auto u:v[y]){
		ans-=cost(u-1,u)+cost(u,u+1);
		a[u]=x;
		ans+=cost(u-1,u)+cost(u,u+1);
		v[x].PB(u);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n){
		it[i]=i;
		cin>>a[i];
		v[a[i]].PB(i);
	}
	FOR(i,2,n){
		ans+=a[i]!=a[i-1];
	}
	cout<<ans<<'\n';
	rep(i,1,m){
		int x,y;
		cin>>x>>y;
		int nx,ny;
		nx=it[x];
		ny=it[y];
		if(v[nx].size()<v[ny].size()){
			it[x]=ny;merge(ny,nx);
		}else merge(nx,ny);
		cout<<ans<<'\n';
	}
	RE 0;
}