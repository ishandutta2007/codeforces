#include<bits/stdc++.h>

using namespace std;

#define LL long long
#define N 300000
#define M 240000

const LL mod=1000000007;
LL n,m,op,x,ans,xb,fac[N],ifac[N],pw25[N],pw26[N],ipw26[N],c[N][2],h[N];
map<int,int> f[N],g[N];
char s[N];

LL C(LL x,LL y){
	return fac[x]*ifac[y]%mod*ifac[x-y]%mod;
}

LL inv(LL x){
	return x==1?1:(mod-mod/x)*inv(mod%x)%mod;
}

void calc(LL n){
	LL tmp=1; if (g[n].count(0)) f[n][0]=tmp;
	for (LL i=1;i<=h[n];++i){
		tmp=(tmp+pw25[i]*ipw26[i]%mod*C(i+n-1,n-1))%mod;
		if (g[n].count(i)) f[n][i]=tmp;
	}
}

int main(){
	scanf("%lld%s",&m,s+1);
	pw25[0]=1; for (LL i=1;i<=M;++i) pw25[i]=pw25[i-1]*25%mod;
	pw26[0]=ipw26[0]=1; for (LL i=1;i<=M;++i){pw26[i]=pw26[i-1]*26%mod; ipw26[i]=ipw26[i-1]*inv(26)%mod;}
	fac[0]=1; for (LL i=1;i<=M;++i) fac[i]=fac[i-1]*i%mod;
	ifac[M]=inv(fac[M]); for (LL i=M-1;i>=0;--i) ifac[i]=ifac[i+1]*(i+1)%mod;
	n=strlen(s+1);
	while (m--){
		scanf("%lld",&op);
		if (op==1){scanf("%s",s+1); n=strlen(s+1);}
		else{
			scanf("%lld",&x); x-=n;
			c[++xb][0]=n; c[xb][1]=x;
			g[n][x]=1; h[n]=max(h[n],x);
		}
	}
	for (int i=1;i<=M;++i) calc(i);
	for (int i=1;i<=xb;++i){
		n=c[i][0]; x=c[i][1];
		printf("%lld\n",(LL)f[n][x]*pw26[x]%mod);
	}
	
	return 0;
}