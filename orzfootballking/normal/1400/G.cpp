#pragma GCC optimize("Ofast")
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
int f[300005],finv[300005],inv[300005],p[300005][45],t[300005];
int l[300005],r[300005],q1[45],q2[45],mod=998244353;
bool vis[300005];
int n,m;
int C(int x,int y){
	if(x<0||y<0||x<y)RE 0;
	RE f[x]*finv[y]%mod*finv[x-y]%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>l[i]>>r[i],t[l[i]]++,t[r[i]+1]--;
	FOR(i,1,m)cin>>q1[i]>>q2[i];
	FOR(i,1,n)t[i]+=t[i-1]; 
	f[0]=f[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	FOR(i,2,n){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-(mod/i)*inv[mod%i]%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	FOR(i,1,n){
		FOR(j,0,40){
			p[i][j]=p[i-1][j]+C(t[i]-j,i-j);p[i][j]%=mod;
		}
	}
	int ans=0;
	rep(mask,0,1<<m){
		int cnt=__builtin_popcount(mask),num=0,nl=1,nr=n;
		FOR(i,1,m)if(mask&(1<<(i-1))){
			if(!vis[q1[i]]){
				vis[q1[i]]=1;num++;gmin(nr,r[q1[i]]);gmax(nl,l[q1[i]]);
			}
			if(!vis[q2[i]]){
				vis[q2[i]]=1;num++;gmin(nr,r[q2[i]]);gmax(nl,l[q2[i]]);
			}
		}
		if(nr>=nl){
			if(cnt&1){
				ans=(ans-p[nr][num]+p[nl-1][num]+mod)%mod;
			}else ans=(ans+p[nr][num]-p[nl-1][num]+mod)%mod;
		}
		FOR(i,1,m)vis[q1[i]]=0,vis[q2[i]]=0;
	}
	cout<<ans;
	RE 0;
}