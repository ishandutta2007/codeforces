#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int fir[1000010],dis[1000010],nxt[1000010],w[1000010],id;
ll W[1000010],S[15010];
int s[15000];
void link(int a,int b,int c){
	nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;
	int p=std::lower_bound(s+1,s+15000,c)-s-1;
	W[id]=1ll*p*c-S[p];
}
int dfn[1000010],low[1000010],stk[1000010],bel[1000010],tp,SCC;
bool ins[1000010];
void tarjan(int x){
	dfn[x]=low[x]=++dfn[0];stk[++tp]=x;ins[x]=tp;
	for(int i=fir[x];i;i=nxt[i])
		if(!dfn[dis[i]])tarjan(dis[i]),low[x]=std::min(low[x],low[dis[i]]);
		else if(ins[dis[i]])low[x]=std::min(low[x],dfn[dis[i]]);
	if(dfn[x]==low[x]){
		++SCC;
		while(ins[x])ins[stk[tp]]=0,bel[stk[tp]]=SCC,--tp;
	}
}
std::vector<std::pair<int,int>>G[1000010];
ll dp[1000010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi(),a,b,c;
	for(int i=1;i<15000;++i)s[i]=1ll*i*(i-1)/2,S[i]=s[i]+S[i-1];
	while(m--)a=gi(),b=gi(),c=gi(),link(a,b,c);
	for(int i=1;i<=n;++i)if(!dfn[i])tarjan(i);
	for(int i=1;i<=n;++i)
		for(int j=fir[i];j;j=nxt[j])
			if(bel[i]==bel[dis[j]])w[j]=0,dp[bel[i]]+=W[j];
			else G[bel[i]].push_back({bel[dis[j]],w[j]});
	for(int i=1;i<=SCC;++i){
		ll www=dp[i];dp[i]=0;
		for(auto[x,w]:G[i])dp[i]=std::max(dp[i],dp[x]+w);
		dp[i]+=www;
	}
	printf("%lld\n",dp[bel[gi()]]);
	return 0;
}