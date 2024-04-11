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
int dp[400005];
int f[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		char c;
		cin>>c;
		if(c=='1')f[i]=1;
	}
	set<P<int,int> > s;
	s.emplace(MP(0,0));
	int mini=0; 
	FOR(i,1,n)dp[i]=1e18;
	int ans=1e18;
	FOR(i,1,n){
		mini=min(dp[i-1],mini)+i;
		gmin(dp[i],mini);
		if(f[i]){
			while((*s.begin()).S+1<i-k)s.erase(s.begin());
			if(!s.empty()){
				gmin(dp[i+k],(*s.begin()).F+i);
				if(i+k<=n)s.emplace(MP(dp[i+k],i+k));
				if(i+k>=n){
					gmin(ans,(*s.begin()).F+i);
				}
			}
		}
		s.emplace(MP(dp[i],i));
	}
	gmin(ans,dp[n]);
	cout<<ans;
	RE 0;
}