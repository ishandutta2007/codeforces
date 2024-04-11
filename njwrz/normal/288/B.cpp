/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
int n,m,cnt,mod=1e9+7;
int p[10];
bool vis[10];
void check(){
	FOR(i,2,m){
		int x=i;
		FILL(vis,0);
		vis[i]=1;
		while(x!=1){
			x=p[x];
			if(vis[x])RE ;
			vis[x]=1;
		}
	}
	cnt++;
}
void dfs(int x){
	if(x==m+1){
		check();RE ;
	}
	FOR(i,1,m){
		p[x]=i;
		dfs(x+1);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	dfs(2);
	cnt=cnt*m;
	FOR(i,m+1,n){
		cnt=cnt*(n-m)%mod;
	}
	cout<<cnt;
	RE 0;
}