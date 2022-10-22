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
int dp[105][20005];
int a[105],b[105],n;
int maxi=1e18;
void solve(){
	int ans=0;
	cin>>n;
	FOR(i,0,n)FOR(j,0,n*200)dp[i][j]=1e18;
	int sum=0;
	dp[0][0]=0;
	int s=0;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		cin>>b[i];
		s+=a[i]*a[i]+b[i]*b[i];
		FOR(j,0,min(i*100,sum))if(dp[i-1][j]<maxi){
			gmin(dp[i][j+a[i]],dp[i-1][j]+a[i]*j+(sum-j)*b[i]);
			gmin(dp[i][j+b[i]],dp[i-1][j]+b[i]*j+(sum-j)*a[i]);
		}
		sum+=a[i]+b[i];
	}
	int mini=1e18;
	FOR(i,0,sum)gmin(mini,dp[n][i]);
	cout<<mini*2+s*(n-1)<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}