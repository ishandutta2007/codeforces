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
int a[300010];
std::map<int,int>st;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),p=gi(),k=gi();
	ll ans=0;
	for(int i=1;i<=n;++i){
		a[i]=gi();
		int x=(1ll*a[i]*a[i]%p*a[i]%p*a[i]%p-1ll*k*a[i]%p+p)%p;
		ans+=st[x];
		st[x]++;
	}
	printf("%d\n",ans%mod);
	return 0;
}