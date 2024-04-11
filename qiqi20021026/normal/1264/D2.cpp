#include<bits/stdc++.h>

using namespace std;

typedef long long LL;
#define N 1200000

const LL mod=998244353;
LL n,ans,l[N],r[N],fac[N],ifac[N];
char s[N];

LL inv(LL x){return x==1?1:(mod-mod/x)*inv(mod%x)%mod;}

LL C(LL x,LL y){
	return x<y||y<0?0:fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

void upd(LL &x,LL y){x=(x+y)%mod;}

int main(){
	scanf("%s",s+1); n=strlen(s+1);
	for (LL i=1;i<=n;++i){
		l[i]=l[i-1]+(s[i]=='(');
		r[i]=r[i-1]+(s[i]==')');
	}
	fac[0]=1; for (LL i=1;i<=n;++i) fac[i]=fac[i-1]*i%mod;
	ifac[n]=inv(fac[n]); for (LL i=n-1;~i;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	for (LL i=0;i<=n;++i){
		LL a=l[i],b=i-l[i]-r[i],c=r[n]-r[i],d=n-i-(r[n]-r[i])-(l[n]-l[i]);
		upd(ans,a*C(b+d,d+c-a)+b*C(b+d-1,d-a+c-1));
	}
	printf("%lld\n",ans);
	
	return 0;
}