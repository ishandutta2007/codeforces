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
void solve(){
	int a,b;
	cin>>a>>b;
	int T=sqrt(a+1),ans=0;
	FOR(i,1,min(T,b)){
		ans+=min(a/(i+1),i-1);
	}
	T++;
	FOR(i,1,b){
		int r=a/i-1,l=a/(i+1);
		if(l>b)continue;
		gmin(r,b);
		if(l>T){
			ans+=i*(r-l+1);
		}else {
			if(r>=T)ans+=i*(r-T+1);break;
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}