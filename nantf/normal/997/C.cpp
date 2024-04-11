#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000100,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,fac[maxn],invfac[maxn],ans,s;
int qpow(int a,ll b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int C(int n,int m){
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int main(){
	n=read();
	fac[0]=1;
	FOR(i,1,n) fac[i]=1ll*fac[i-1]*i%mod;
	invfac[n]=qpow(fac[n],mod-2);
	ROF(i,n-1,0) invfac[i]=1ll*invfac[i+1]*(i+1)%mod;
	ans=qpow(3,1ll*n*n);
	FOR(i,1,n){
		int tmp=2ll*C(n,i)*qpow(3,1ll*n*(n-i)+i)%mod;
		if(i&1) ans=(ans-tmp+mod)%mod;
		else ans=(ans+tmp)%mod;
	}
	FOR(i,0,n-1){
		int tmp=mod-qpow(3,i);
		tmp=(qpow((tmp+1)%mod,n)-qpow(tmp,n)+mod)%mod;
		tmp=3ll*tmp*C(n,i)%mod;
		if(i&1) s=(s-tmp+mod)%mod;
		else s=(s+tmp)%mod;
	}
	printf("%d\n",(qpow(3,1ll*n*n)-(ans+s)%mod+mod)%mod);
}
// orz CDW fudajfosdjisjhagiohsegs