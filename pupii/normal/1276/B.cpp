#include<bits/stdc++.h>
#define vd void
#define il inline
using namespace std;
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
int fir[200010],dis[1000010],nxt[1000010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int va[200010],vb[200010];
void dfs(int x,int*vis,int ban){
	vis[x]=1;if(x==ban)return;
	for(int i=fir[x];i;i=nxt[i])
		if(!vis[dis[i]])
			dfs(dis[i],vis,ban);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int T=gi();
	while(T--){
		int n=gi(),m=gi(),a=gi(),b=gi(),u,v;
		memset(fir+1,0,4*n),id=0;
		for(int i=1;i<=m;++i)u=gi(),v=gi(),link(u,v),link(v,u);
		memset(va+1,0,4*n),memset(vb+1,0,4*n);
		dfs(a,va,b),dfs(b,vb,a);
		int SA=0,SB=0;
		for(int i=1;i<=n;++i){
			if(i==a)continue;
			if(i==b)continue;
			if(va[i]&&!vb[i])++SA;
			if(vb[i]&&!va[i])++SB;
		}
		printf("%lld\n",va[b]?1ll*SA*SB:0);
	}
	return 0;
}