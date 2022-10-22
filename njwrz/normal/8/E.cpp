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
int dp[55][2],n;
int p[55];
int solve(){
	int re=0;
	FILL(dp,0);
	dp[0][0]=1;
	int m=(n+1)/2;
	rep(i,0,m){
		rep(nl,0,2){
			rep(nr,0,2-(i==0)){
				if(i+i+1==n&&nl!=nr)continue;
				if(p[i+1]!=-1&&p[i+1]!=nl)continue;
				if(p[n-i]!=-1&&p[n-i]!=nr)continue;
				if(nl==nr){
					dp[i+1][0]+=dp[i][0];
					dp[i+1][1]+=dp[i][1];
				}else if(nl<nr){
					dp[i+1][1]+=dp[i][0];
					dp[i+1][1]+=dp[i][1];
				}else{
					dp[i+1][1]+=dp[i][1];
				}
			}
		}
	}
	re=dp[m][0]+dp[m][1];
	FILL(dp,0);
	dp[0][0]=1;
	rep(i,0,m){
		rep(nl,0,2){
			rep(nr,i==0,2){
				if(i+i+1==n&&nl!=nr)continue;
				if(p[i+1]!=-1&&p[i+1]!=nl)continue;
				if(p[n-i]!=-1&&p[n-i]!=nr)continue;
				nr^=1;
				if(nl==nr){
					dp[i+1][0]+=dp[i][0];
					dp[i+1][1]+=dp[i][1];
				}else if(nl<nr){
					dp[i+1][1]+=dp[i][0];
					dp[i+1][1]+=dp[i][1];
				}else{
					dp[i+1][1]+=dp[i][1];
				}
				nr^=1;
			}
		}
	}
	re+=dp[m][0]+dp[m][1];
	FOR(i,1,n)if(p[i]==1)RE re;
	RE re-1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>n>>k;k--;
	FILL(p,-1);
	p[1]=0;
	if(solve()<=k){
		cout<<-1;RE 0;
	}
	FOR(i,2,n){
		p[i]=0;
		int t=solve();
		if(t<=k){
			k-=t;
			p[i]=1;
		}
	}
	if(k){
		cout<<-1;RE 0;
	}
	FOR(i,1,n)cout<<p[i];
	RE 0;
}