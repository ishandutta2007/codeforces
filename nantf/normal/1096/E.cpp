#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353,maxn=1000100;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int t,p,s,r,fac[maxn],inv[maxn],invfac[maxn];
inline int C(int n,int m){
	if(m<0 || n<m) return 0;
	return 1ll*fac[n]*invfac[m]%mod*invfac[n-m]%mod;
}
int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
void init(){
	fac[0]=fac[1]=inv[1]=invfac[0]=invfac[1]=1;
	FOR(i,2,1000000){
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
		invfac[i]=1ll*invfac[i-1]*inv[i]%mod;
	}
}
void solve(){
	p=read();s=read();r=read();
	int ans=0;
	FOR(i,r,s){
		if(i==0){
			if(s!=0) continue;
			ans=(ans+inv[p])%mod;
			continue;
		}
		FOR(j,0,min(s/i-1,p-1)){
			int sum=0;
			if(p-j-1==0) sum=s-i*(j+1)==0;
			else{
				FOR(hhh,0,min(p-j-1,(s-i*(j+1))/i)){
					int k=hhh*i;
					int x=1ll*C(p-j-1,hhh)*C(s-i*(j+1)-k+p-j-2,s-i*(j+1)-k)%mod;
					if(hhh%2==0) sum=(sum+x)%mod;
					else sum=(sum-x+mod)%mod;
				}
			}
			ans=(ans+1ll*sum*inv[j+1]%mod*C(p-1,j))%mod;
		}
	}
	printf("%lld\n",1ll*ans*qpow(C(s-r+p-1,p-1),mod-2)%mod);
}
int main(){
	t=1;
	init();
	while(t--) solve();
}
/*
3
2 6 3
5 20 11
10 30 10
*/