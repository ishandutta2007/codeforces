#include<bits/stdc++.h>
#define int long long
#define lb long double
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
int dp[5005][5005],val[5005];
int n;
P<int,int> p[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	dp[0][0]=1;
	rep(i,0,n){
		if(p[i+1].F-p[i].F>=abs(p[i+1].S-p[i].S)){
			FOR(j,i+2,n)dp[i+1][j]|=dp[i][j];
		}
		if(dp[i][i+1]){
			if(i+2<=n){
				if(abs(p[i+2].S-p[i].S)<=p[i+2].F-p[i].F){
					dp[i+2][0]=1;val[i+2]=max(p[i].F+abs(p[i+2].S-p[i].S),p[i+1].F);
				}
				FOR(j,i+3,n)if(abs(p[i].S-p[j].S)+abs(p[j].S-p[i+2].S)<=p[i+2].F-p[i].F&&abs(p[j].S-p[i+2].S)<=p[i+2].F-p[i+1].F){
					dp[i+2][j]=1;
				}
			}
		}
		if(dp[i][0]){
			if(p[i+1].F-val[i]>=abs(p[i+1].S-p[i].S)){
				int to=val[i]+abs(p[i+1].S-p[i].S);gmax(to,p[i].F);
				if(!dp[i+1][0]||val[i+1]>to){
					dp[i+1][0]=1;
					val[i+1]=to;
				}
			}
			FOR(j,i+2,n)if(abs(p[j].S-p[i].S)+abs(p[j].S-p[i+1].S)<=p[i+1].F-val[i]&&p[i+1].F-p[i].F>=abs(p[j].S-p[i+1].S)){
				dp[i+1][j]=1;
			}
		}
	}
	if(dp[n-1][n]||dp[n][0]){
		cout<<"YES";
	}else cout<<"NO";
	RE 0;
}