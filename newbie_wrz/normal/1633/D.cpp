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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,dp[1005],a[1005],t[100005],c[1005];
void solve(){
	int n,k;
	cin>>n>>k;
	int sum=0;
	FOR(i,0,100000)t[i]=-2e9;
	t[0]=0;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		cin>>c[i];
		for(int j=sum;j>=0;j--)if(j+dp[a[i]]<=k){
			gmax(t[j+dp[a[i]]],t[j]+c[i]);
		}
		sum+=dp[a[i]];
		gmin(sum,k);
	}
	int ans=0;
	FOR(i,0,sum){
		gmax(ans,t[i]);
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	FOR(i,1,1000)dp[i]=-1;
	dp[1]=0;
	int m=0;
	FOR(i,1,1000){
		gmax(m,dp[i]);
		FOR(j,1,i){
			int t=i+(i/j);
			if(dp[t]==-1||dp[t]>dp[i]+1){
				dp[t]=dp[i]+1;
			}
		}
	}
//	cout<<m<<'\n';
	cin>>T;
	while(T--)solve();
	RE 0;
}