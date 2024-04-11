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
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
int n,N,D,f[3010][3010];
int fir[3010],dis[6010],nxt[6010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
void dfs(int x){
	for(int i=1;i<=N;++i)f[x][i]=1;
	for(int i=fir[x];i;i=nxt[i]){
		dfs(dis[i]);
		for(int j=N,s=0;j;--j)s=(s+f[dis[i]][j])%mod,f[x][j]=1ll*f[x][j]*s%mod;
	}
}
int ifact[3010],pre[3010],suf[3010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();D=gi();N=n+1;
	for(int i=2;i<=n;++i)link(gi(),i);
	dfs(1);
	std::reverse(f[1]+1,f[1]+N+1);
	for(int i=1;i<=N;++i)f[1][i]=(f[1][i-1]+f[1][i])%mod;
	if(D<=n)return printf("%d\n",f[1][D]),0;
	ifact[0]=1;for(int i=1;i<=N;++i)ifact[i]=1ll*ifact[i-1]*i%mod;
	ifact[N]=pow(ifact[N],mod-2);for(int i=N;i;--i)ifact[i-1]=1ll*ifact[i]*i%mod;
	pre[0]=1;for(int i=1;i<=N;++i)pre[i]=1ll*pre[i-1]*(D-i)%mod;
	suf[N+1]=1;for(int i=N;i;--i)suf[i]=1ll*suf[i+1]*(D-i)%mod;
	int ans=0;
	for(int i=N,M=1;i;--i,M=mod-M)ans=(ans+1ll*f[1][i]*pre[i-1]%mod*suf[i+1]%mod*ifact[i-1]%mod*ifact[N-i]%mod*M)%mod;
	printf("%d\n",ans);
	return 0;
}