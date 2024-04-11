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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int dp[5005][9][1<<9];
int it[5015],n,k;
int sum[5015][5015];
const int inf=2e9;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
//	n=5000;k=8;
	k++;
	FOR(i,1,n){
		int x;
//		x=i;
		cin>>x;
		it[x]=i;
	}
	FOR(i,1,n){
		FOR(j,1,i)sum[i][j]=sum[i][j-1]+(it[j]>it[i]);
	}
	FOR(i,0,n)rep(j,0,k)rep(mask,0,1<<k)dp[i][j][mask]=inf;
	FOR(i,1,k){
		int mask=1;
		rep(j,i,k)mask|=(1<<j);
		dp[1][i-1][mask]=0;
	}
	FOR(i,2,n)rep(j,0,k)rep(mask,0,1<<k)if(dp[i-1][j][mask]!=inf){
		rep(to,0,k)if(!(mask&(1<<to))){
			int cost=sum[i-1+j-to][max(0,i-1+j-k)];
			rep(t,0,k)if(mask&(1<<t))if(i-1+j-t>=1)cost+=(it[i-1+j-t]>it[i-1+j-to]);
			gmin(dp[i][j-1][mask|(1<<to)],cost+dp[i-1][j][mask]);
		}
		FOR(to,j+1,k){
			int msk=mask*(1<<(to-j))+1;
			int now=msk%(1<<k);
			if((msk/(1<<k))==(1<<(to-j))-1){
				int cost=sum[i+to-1][max(0,i+to-1-k)];
				rep(t,1,k)if(msk&(1<<t))if(i+to-1-t>=1)cost+=(it[i+to-1-t]>it[i+to-1]);
				gmin(dp[i][to-1][now],cost+dp[i-1][j][mask]);
			}
		}
	}
	cout<<dp[n][0][(1<<k)-1];
	RE 0;
}