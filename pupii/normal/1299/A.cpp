#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#endif
int a[100010],pre[100010],suf[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	for(int i=1;i<=n;++i)pre[i]=pre[i-1]|a[i];
	for(int i=n;i;--i)suf[i]=suf[i+1]|a[i];
	int p=1,MX=0;
	for(int i=1;i<=n;++i){
		int w=a[i]&~(pre[i-1]|suf[i+1]);
		if(w>MX)p=i,MX=w;
	}
	printf("%d ",a[p]);
	for(int i=1;i<=n;++i)if(i!=p)printf("%d ",a[i]);
	return 0;
}