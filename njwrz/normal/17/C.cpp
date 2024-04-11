#include<bits/stdc++.h>
#define ll long long
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
char c[155];
int dp[155][55][55][55],mod=51123987,nxt[155][3];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int m=n/3+1;
	FOR(i,1,n){
		cin>>c[i];
	}
	nxt[n+1][n+1];
	for(int i=n;i>=1;i--){
		rep(j,0,3)nxt[i][j]=nxt[i+1][j];
		nxt[i][c[i]-'a']=i; 
	}
	dp[1][0][0][0]=1;
	int ans=0;
	FOR(i,1,n){
		FOR(ka,0,m){
			FOR(kb,0,m){
				FOR(kc,0,m){
					if(ka+kb+kc==n&&max(max(ka,kb),kc)-min(min(ka,kb),kc)<2)add(ans,dp[i][ka][kb][kc])
					;add(dp[nxt[i][0]][ka+1][kb][kc],dp[i][ka][kb][kc]);
					add(dp[nxt[i][1]][ka][kb+1][kc],dp[i][ka][kb][kc]);
					add(dp[nxt[i][2]][ka][kb][kc+1],dp[i][ka][kb][kc]);
				}
			}
		}
	}
	cout<<ans;
	RE 0;
}