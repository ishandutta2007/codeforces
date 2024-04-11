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
int a[105],b[105],c[105],d[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,now=0;
	cin>>n>>m;
	FOR(i,1,n){
		a[i]=++now;
		d[i]=++now;
	}
	FOR(i,1,n){
		b[i]=++now;
		c[i]=++now;
	}
	FOR(i,1,n){
		if(b[i]<=m){
			cout<<b[i]<<' ';
		}
		if(a[i]<=m){
			cout<<a[i]<<' ';
		}
		if(c[i]<=m){
			cout<<c[i]<<' ';
		}
		if(d[i]<=m){
			cout<<d[i]<<' ';
		}
	}
	RE 0;
}