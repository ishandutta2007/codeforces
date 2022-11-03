#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 1000000007
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int f[1010][1010][2][2],ans[1010],fact[1010],ifact[1010];
il vd add(int&a,int b){a+=b;if(a>=mod)a-=mod;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	fact[0]=1;for(int i=1;i<=n;++i)fact[i]=1ll*fact[i-1]*i%mod;
	ifact[n]=pow(fact[n],mod-2);
	for(int i=n-1;~i;--i)ifact[i]=1ll*ifact[i+1]*(i+1)%mod;
	f[0][0][1][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=0;j<i;++j)
			for(int k=0;k<2;++k)
				for(int l=0;l<2;++l){
					if(!f[i-1][j][k][l])continue;
					add(f[i][j][l][0],f[i-1][j][k][l]);
					if(!k)add(f[i][j+1][l][0],f[i-1][j][k][l]);
					add(f[i][j+1][l][1],f[i-1][j][k][l]);
				}
	for(int i=0;i<=n;++i)ans[i]=1ll*(f[n][i][0][0]+f[n][i][1][0])*fact[n-i]%mod;
	int ANS=ans[m];
	for(int i=m+1,mul=mod-1;i<=n;++i,mul=mod-mul)ANS=(ANS+mod+1ll*mul*fact[i]%mod*ifact[m]%mod*ifact[i-m]%mod*ans[i]%mod)%mod;
	printf("%d\n",ANS);
	return 0;
}