#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int s1x[1000010],s1y[1000010],s2x[1000010],s2y[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a=0,b=0;
	for(int i=1;i<=n;++i){
		if(i&1)for(int j=1;j<=m;++j)++a,s1x[a]=i,s1y[a]=j;
		else for(int j=m;j;--j)++a,s1x[a]=i,s1y[a]=j;
	}
	for(int i=n;i;--i){
		if((n-i)&1)for(int j=1;j<=m;++j)++b,s2x[b]=i,s2y[b]=j;
		else for(int j=m;j;--j)++b,s2x[b]=i,s2y[b]=j;
	}
	int N=n*m;
	for(int i=1;i<=n*m;++i){
		printf("%d %d\n",s1x[i],s1y[i]);
		if(--N==0)break;
		printf("%d %d\n",s2x[i],s2y[i]);
		if(--N==0)break;
	}
	return 0;
}