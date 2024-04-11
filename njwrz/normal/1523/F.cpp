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
int dp[1<<14][105],f[1<<14][105];
P<int,P<int,int> > p[105];
P<int,int> pos[14];
int n,m; 
int cost[1<<14][105],c[1<<14][14],dis[105][105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,0,n)cin>>pos[i].F>>pos[i].S;
	FOR(i,1,m){
		cin>>p[i].S.F>>p[i].S.S>>p[i].F;
	}
	sort(p+1,p+m+1);
	FOR(i,1,m){
		rep(mask,0,1<<n){
			cost[mask][i]=1e18;
			rep(j,0,n)if(mask&(1<<j))gmin(cost[mask][i],abs(pos[j].F-p[i].S.F)+abs(pos[j].S-p[i].S.S));
		}
	}
	FOR(i,1,m)FOR(j,1,m)dis[i][j]=abs(p[i].S.F-p[j].S.F)+abs(p[i].S.S-p[j].S.S);
	rep(i,0,n){
		rep(mask,0,1<<n){
			c[mask][i]=1e18;
			rep(j,0,n)if(mask&(1<<j))gmin(c[mask][i],abs(pos[j].F-pos[i].F)+abs(pos[j].S-pos[i].S));
		}
	}
	rep(i,0,1<<n)FOR(j,0,m){
		if(__builtin_popcount(i)<=1&&!j)dp[i][j]=0; else dp[i][j]=1e18;
		if(!i)f[i][j]=1;else f[i][j]=-1e18;
	}
	int ans=0;
	rep(mask,0,1<<n){
		if(mask)FOR(i,0,m){
			FOR(j,1,m)if(dp[mask][i]<p[j].F){
				if(p[j].F>=dp[mask][i]+cost[mask][j]){
					gmax(f[mask][j],i+1);
				}
			}
			rep(j,0,n)if(!(mask&(1<<j))){
				gmin(dp[mask|(1<<j)][i],dp[mask][i]+c[mask][j]);
			}
		}
		FOR(i,1,m)if(f[mask][i]>0){
			gmax(ans,f[mask][i]);
			FOR(j,i+1,m){
				if(p[j].F>=p[i].F+min(cost[mask][j],dis[i][j])){
					gmax(f[mask][j],f[mask][i]+1);
				}
			}
			rep(j,0,n)if(!(mask&(1<<j))){
				gmin(dp[mask|(1<<j)][f[mask][i]],p[i].F+min(c[mask][j],abs(p[i].S.F-pos[j].F)+abs(p[i].S.S-pos[j].S)));
			} 
		}
	}
	cout<<ans;
	RE 0;
}