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
int mod=1e9+7;
void solve(){
	map<int,int> mp;
	int n;
	cin>>n;
	int sumx=0,sum=0;
	FOR(i,1,n){
		int x;
		cin>>x;
		int add=(sum-mp[sumx]+mod)%mod;
		if(i==1)add=1;
//		cout<<add<<' ';
		(mp[sumx]+=add)%=mod;
		(sum+=add)%=mod;
		sumx+=x;
	} 
	cout<<sum<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}