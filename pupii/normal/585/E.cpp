#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int a[500010],p2[500010],cnt[10000010];
int pr[1000010],mu[10000010],P;
bool yes[10000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	for(int i=2;i<=10000000;++i){
		if(!yes[i])pr[++P]=i,mu[i]=1;
		for(int j=1;j<=P&&i*pr[j]<=10000000;++j){
			yes[i*pr[j]]=1;
			if(i%pr[j]==0){mu[i*pr[j]]=0;break;}
			mu[i*pr[j]]=mod-mu[i];
		}
	}
	int n=gi();
	for(int i=1;i<=n;++i)++cnt[a[i]=gi()];
	p2[0]=1;for(int i=1;i<=n;++i)p2[i]=2*p2[i-1]%mod;
	int ans=0;
	for(int d=2,A;d<=10000000;++d){
		A=0;
		for(int i=d;i<=10000000;i+=d)A+=cnt[i];
		ans=(ans+1ll*mu[d]*(p2[A]-1)%mod*(n-A))%mod;
	}
	printf("%d\n",ans);
	return 0;
}