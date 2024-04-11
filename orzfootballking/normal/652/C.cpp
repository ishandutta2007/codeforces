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
int it[300005],l[300005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		int x;
		cin>>x;
		it[x]=i;
	}
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		if(it[x]>it[y])swap(x,y);
		gmax(l[it[y]],it[x]);
	}
	int ans=0;
	FOR(i,1,n){
		gmax(l[i],l[i-1]);
		ans+=i-l[i]-1;
	}
	cout<<ans+n;
	RE 0;
}