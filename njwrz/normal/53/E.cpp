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
bool f[11][11];
int dp[1024][1024],n;
int cnt(int x){
	int re=0;
	rep(i,0,n){
		if(x&(1<<i))re++;
	}
	RE re;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,k;
	cin>>n>>m>>k;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		x--;y--;
		f[x][y]=1;
		f[y][x]=1;
		dp[(1<<y)|(1<<x)][(1<<y)|(1<<x)]=1;
	}
	rep(mask1,0,1<<n){
		rep(mask2,0,1<<n)if((mask2&mask1)==mask2&&dp[mask1][mask2]){
			int min1=1e9,min2=1e9;
			for(int now=n-1;now>=0;now--)if(mask2&(1<<now)){
				min2=min1,min1=now;
			}
			rep(now,0,n)if(!(mask1&(1<<now))){
				rep(fr,0,n)if(mask1&(1<<fr))if(f[now][fr]){
					if(mask2&(1<<fr)){
						if(fr==min1&&now<min2||now<min1){
							dp[mask1|(1<<now)][mask2^(1<<fr)^(1<<now)]+=dp[mask1][mask2];
						}
					}else{
						if(now<min1){
							dp[mask1|(1<<now)][mask2^(1<<now)]+=dp[mask1][mask2];
						}
					}
				}
			}
		}
	}
	int ans=0;
	rep(i,0,1<<n){
		if(cnt(i)==k)ans+=dp[(1<<n)-1][i];
//		cout<<i<<' '<<dp[(1<<n)-1][i]<<'\n';
	}
	cout<<ans;
	RE 0;
}