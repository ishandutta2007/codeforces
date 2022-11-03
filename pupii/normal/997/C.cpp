#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
il int gi(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int p[1000010],inv[1000010],ip[1000010];
il int C(int n,int m){return 1ll*p[n]*ip[m]%mod*ip[n-m]%mod;}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
#endif
	int n=gi(),ans=0;
	inv[1]=1;for(int i=2;i<=n;++i)inv[i]=mod-1ll*(mod/i)*inv[mod%i]%mod;
	p[0]=ip[0]=1;
	for(int i=1;i<=n;++i)p[i]=1ll*p[i-1]*i%mod;
	for(int i=1;i<=n;++i)ip[i]=1ll*ip[i-1]*inv[i]%mod;
	for(int i=1;i<=n;++i)ans=(ans+1ll*(i&1?mod-1:1)*C(n,i)%mod*(3ll*pow(pow(3,n-i)-1,n)+1ll*(pow(3,i)-3+mod)*pow(3,1ll*(n-i)*n%(mod-1))%mod))%mod;
	ans=((pow(3,1ll*n*n%(mod-1))-pow(pow(3,n)-3+mod,n)+mod)%mod-ans+mod)%mod;
	printf("%d\n",ans);
	return 0;
}