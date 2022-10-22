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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
const int mod=998244353;
int dp[35][22][22][22][22][2][2];
P<int,int> p[5];
int n,m;
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	rep(i,0,n)cin>>p[i].F>>p[i].S;
	dp[0][0][0][0][0][1][1]=1;
	rep(i,0,31)FOR(upx,0,20)FOR(upy,0,20)FOR(upnx,0,20)FOR(upny,0,20)rep(f1,0,2)rep(f2,0,2)if(dp[i][upx][upy][upnx][upny][f1][f2]){
		rep(mask,0,1<<n){
			int to1=upx,to2=upy,to3=upnx,to4=upny,tof1=f1,tof2=f2;
			rep(j,0,n)if(mask&(1<<j)){
				if(p[j].F<0)upnx-=p[j].F;else upx+=p[j].F;
				if(p[j].S<0)upny-=p[j].S;else upy+=p[j].S;
			}
			if((upnx&1)!=(upx&1)||(upny&1)!=(upy&1)){
				
			}else{
				int t=(m>>i)&1;
				if(t>(upx&1)){
					tof1=1;
				}else if(t<(upx&1))tof1=0;
				if(t>(upy&1)){
					tof2=1;
				}else if(t<(upy&1))tof2=0;
				upx/=2;upy/=2;upnx/=2;upny/=2;
				add(dp[i+1][upx][upy][upnx][upny][tof1][tof2],dp[i][to1][to2][to3][to4][f1][f2]);
			}
			upx=to1;upy=to2;upnx=to3;upny=to4;
		}
	}
	cout<<(dp[31][0][0][0][0][1][1]-1+mod)%mod;
	RE 0;
}