#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define LL long long

const LL mod=998244353;
LL a,b,c,ansa,ansb,ansc,tot,fac[6000],inv[6000];

LL pow(LL x,LL y){
	if (y==0) return 1;
	LL tmp=pow(x*x%mod,y/2);
	if (y&1) return tmp*x%mod;
	return tmp;
}

void prepare(int n){
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=pow(fac[n],mod-2); for (int i=n-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}

LL C(int x,int y){return fac[x]*inv[y]%mod*inv[x-y]%mod;}

LL P(int x,int y){return fac[x]*inv[x-y]%mod;}

int main(){
	scanf("%lld%lld%lld",&a,&b,&c);
	prepare(5000);
	for (register int i=0,mn=min(a,b);i<=mn;i++) ansa=(ansa+C(a,i)*P(b,i))%mod;
	for (register int i=0,mn=min(b,c);i<=mn;i++) ansb=(ansb+C(b,i)*P(c,i))%mod;
	for (register int i=0,mn=min(c,a);i<=mn;i++) ansc=(ansc+C(c,i)*P(a,i))%mod;
	printf("%lld\n",ansa*ansb%mod*ansc%mod);
	return 0;
}