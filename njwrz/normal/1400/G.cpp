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
int p[300005][45],f[300005],inv[300005],finv[300005],l[300005],r[300005],cnt[300005],mod=998244353;
P<int,int> me[20];
bool vis[300005];
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[x-y]%mod*finv[y]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		cin>>l[i]>>r[i];
		cnt[l[i]]++;
		cnt[r[i]+1]--;
	}
	FOR(i,1,n)cnt[i]+=cnt[i-1];
	rep(i,0,m)cin>>me[i].F>>me[i].S;
	inv[1]=finv[0]=finv[1]=f[0]=f[1]=1;
	FOR(i,2,n){
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		f[i]=f[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	FOR(j,0,40){
		FOR(i,1,n){
			p[i][j]=C(cnt[i]-j,i-j);
			p[i][j]+=p[i-1][j];
			if(p[i][j]>=mod)p[i][j]-=mod;
		}
	}
	int ans=0;
	rep(i,0,1<<m){
		int cnt=0,L=1,R=n,num=0;
		rep(j,0,m)if(i&(1<<j)){
			cnt++;
			gmax(L,l[me[j].F]);
			gmax(L,l[me[j].S]);
			gmin(R,r[me[j].F]);
			gmin(R,r[me[j].S]);
			if(!vis[me[j].F]){
				vis[me[j].F]=1;
				num++;
			}
			if(!vis[me[j].S]){
				vis[me[j].S]=1;
				num++;
			}
		}
		rep(j,0,m)vis[me[j].F]=vis[me[j].S]=0;
		if(L>R)continue;
		int tans=p[R][num]-p[L-1][num];
		if(tans<0)tans+=mod;
		if(cnt&1)tans=mod-tans;
		ans+=tans;
		if(ans>=mod)ans-=mod;
	}
	cout<<ans;
	RE 0;
}