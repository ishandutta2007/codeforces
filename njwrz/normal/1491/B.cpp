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
int n,u,v,a[105];
void solve(){
	cin>>n>>u>>v;
	FOR(i,1,n){
		cin>>a[i];
	}
	bool f=0;
	FOR(i,2,n){
		if(abs(a[i]-a[i-1])>1){
			cout<<0<<'\n';RE;
		}
		if(abs(a[i]-a[i-1])==1){
			f=1;
		}
	}
	if(f){
		cout<<min(u,v);
	}else{
		cout<<v+min(u,v);
	}
	cout<<'\n'; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}