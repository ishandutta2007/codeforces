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
int cnt[20000005],ans;
int c,d,x;
void solve(int gcd){
	if((d*gcd+x)%c!=0)RE;
	int lcm=(d*gcd+x)/c;
	if(lcm%gcd==0){
		ans=ans+(1<<(cnt[lcm/gcd]));
	}
}
void solve(){
	ans=0;
	cin>>c>>d>>x;
	for(int i=1;i*i<=x;i++)if(x%i==0){
		solve(i);
		if(i*i!=x)solve(x/i);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,2,2e7)if(!cnt[i]){
		for(int j=i;j<=2e7;j+=i){
			cnt[j]++;
		}
	}
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}