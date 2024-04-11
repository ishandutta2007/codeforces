#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020,mod=1000000007,inv2=500000004;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,t[maxn],fac[maxn],inv[maxn],invfac[maxn],f[maxn],ans,pro=1;
ll r[maxn];
int C(int n,ll m){
	if(n<m) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	n=read();r[0]=read();
	FOR(i,1,n) t[i]=read();
	FOR(i,1,n) r[i]=r[i-1]-t[i];
	fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1;
	FOR(i,2,n){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		invfac[i]=1ll*invfac[i-1]*inv[i]%mod;
	}
	FOR(i,0,min(1ll,r[1])) f[1]=(f[1]+C(1,i))%mod;
	FOR(i,2,n){
		if(r[i]<0) break;
		f[i]=(2ll*f[i-1]-C(i-1,r[i-1])+mod)%mod;
		ROF(j,min<ll>(i,r[i-1]),r[i]+1) f[i]=(f[i]-C(i,j)+mod)%mod;
	}
	FOR(i,1,n){
		if(r[i]<0) break;
		pro=1ll*pro*inv2%mod;
		ans=(ans+1ll*pro*f[i])%mod;
	}
	printf("%d\n",ans);
}