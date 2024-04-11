#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 3000000

const LL mod=1000000007;
LL ans,n,f[N];
char s[N];

LL ppc(LL x){
	LL ret=0;
	for (;x;x>>=1) ret+=x&1;
	return ret;
}

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

void fwt(LL f[],LL n){
	for (LL i=0;i<n;++i){
		LL t=1<<i;
		for (LL j=0;j<1<<n;j+=t<<1){
			LL *f1=f+j,*f2=f+j+t;
			for (LL k=0;k<t;++k){
				LL x=f1[k],y=f2[k];
				f1[k]=(x+y)%mod;
				f2[k]=(x-y+mod)%mod;
			}
		}
	}
}

int main(){
	scanf("%lld%s",&n,s);
	for (LL i=0;i<1<<n;++i) f[i]=s[i]-'0';
	fwt(f,n);
	for (LL i=0;i<1<<n;++i) f[i]=f[i]*f[i]%mod;
	fwt(f,n);
	for (LL i=0,ii=inv(1<<n);i<1<<n;++i){
		f[i]=f[i]*ii%mod;
		ans=(ans+f[i]*(1<<(n-ppc(i))))%mod;
	}
	printf("%lld\n",ans*3%mod);
	
	return 0;
}