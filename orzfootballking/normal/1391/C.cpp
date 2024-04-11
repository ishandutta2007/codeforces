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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int ans=1;
	cin>>n;
	int mod=1e9+7;
	rep(i,1,n){
		ans=ans*2%mod;
	}
	int t=1;
	FOR(i,2,n)t=t*i%mod; 
	t=(t-ans+mod)%mod;
	cout<<t;
	RE 0;
}