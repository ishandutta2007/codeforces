#include<bits/stdc++.h>
#define il inline
#define vd void
#define mod 998244353
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
int a[100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=1;i<=n;++i)a[i]=gi();
	bool flg=0;
	std::sort(a+1,a+n+1);
	ll tot=0;
	for(int i=1;i<n;++i)
		if(a[i]==a[i+1])
			if(a[i]&&(i==1||a[i]!=a[i-1]+1)&&!flg)--a[i],flg=1;
			else return puts("cslnb"),0;
	for(int i=1;i<=n;++i)tot+=a[i]-i+1;
	if((tot&1)^flg^1)puts("cslnb");
	else puts("sjfnb");
	return 0;
}