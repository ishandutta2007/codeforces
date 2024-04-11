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
int p[16]={0,2,3,5,7,11,13,17,23,29,31,37,41,43,47,53};
int dp[1005][16];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FILL(dp,-1);
	dp[1][0]=1;
	FOR(i,1,n/2){
		FOR(j,0,14)if(dp[i][j]!=-1){
			int now=dp[i][j],cnt=0;
			do{
				if(i*(cnt+1)>n)break;
				if(dp[i*(cnt+1)][j+1]==-1||dp[i*(cnt+1)][j+1]>now){
					dp[i*(cnt+1)][j+1]=now;
				}
				cnt++;
				if((1e18/now)<p[j+1])break;
				now=now*p[j+1];
			}while(1);
		}
	}
	int ans=1e18;
	rep(i,0,16)if(dp[n][i]!=-1)gmin(ans,dp[n][i]);
	cout<<ans;
	RE 0;
}