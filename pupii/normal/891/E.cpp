#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
il int gi(){
	int x=0,f=0;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int c[5010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),k=gi(),mul=1;
	c[0]=1;
	for(int i=1;i<=n;++i){
		int a=gi();mul=1ll*a*mul%mod;
		for(int j=n;~j;--j)c[j+1]=(c[j+1]-c[j]+mod)%mod,c[j]=1ll*c[j]*a%mod;
	}
	int ans=0,invn=pow(n,mod-2);
	for(int i=0,pn=1,fc=1;i<=n;fc=1ll*fc*(k-i)%mod,pn=1ll*pn*invn%mod,++i)ans=(ans+1ll*c[i]*fc%mod*pn%mod)%mod;
	printf("%d\n",(mul-ans+mod)%mod);
	return 0;
}