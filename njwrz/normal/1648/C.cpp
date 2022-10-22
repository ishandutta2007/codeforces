#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
int n,m,a[200005],b[200005];
int cnta[200005],cntb[200005];
struct Bit{
	int s[200005];
	void update(int x,int y){
		while(x<=200000){
			s[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
}T;
int f[200005],finv[200005],inv[200005],mul,mod=998244353;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],cnta[a[i]]++;
	FOR(i,1,m)cin>>b[i],cntb[b[i]]++;
	f[0]=f[1]=finv[0]=finv[1]=inv[1]=1;
	FOR(i,2,200000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	int ans=0;
	mul=1;
	FOR(i,1,200000)if(cnta[i]){
		mul=mul*finv[cnta[i]]%mod;
		T.update(i,cnta[i]);
	}
	FOR(i,1,min(n,m)){
		ans=(ans+f[n-i]*mul%mod*T.get(b[i]-1))%mod;
		if(!cnta[b[i]])break;
		mul=mul*cnta[b[i]]%mod;
		cnta[b[i]]--;
		T.update(b[i],-1);
		if(i==n&&n<m)ans=(ans+1)%mod;
	}
	cout<<ans;
	RE 0;
}