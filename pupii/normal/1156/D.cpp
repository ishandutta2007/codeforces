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
int fir[200010],dis[400010],nxt[400010],id;bool w[400010];
il vd link(int a,int b,bool c){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
int N,f[200010],siz[200010],rt;
bool vis[200010];
il vd getrt(int x,int fa=-1){
	siz[x]=1,f[x]=0;
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa||vis[dis[i]])continue;
		getrt(dis[i],x);
		siz[x]+=siz[dis[i]];
		f[x]=std::max(f[x],siz[dis[i]]);
	}
	f[x]=std::max(f[x],N-siz[x]);
	if(f[rt]>f[x])rt=x;
}
ll ans=0;
int tot[2];
il vd dfs(int x,bool y,bool f,bool c,int fa=-1){
	++tot[f];if(c)++ans;
	for(int i=fir[x];i;i=nxt[i]){
		if(vis[dis[i]]||dis[i]==fa)continue;
		if(w[i]&&!y)continue;
		dfs(dis[i],w[i],f,c,x);
	}
}
il vd DFS(int x,bool y,bool f,int fa=-1){
	ans+=tot[0]+f*tot[1];
	for(int i=fir[x];i;i=nxt[i]){
		if(vis[dis[i]]||dis[i]==fa)continue;
		if(!w[i]&&y)continue;
		DFS(dis[i],w[i],f,x);
	}
}
il vd solve(int x){
	vis[x]=1;std::vector<std::pair<int,bool>>son;
	for(int i=fir[x];i;i=nxt[i])if(!vis[dis[i]])son.push_back({dis[i],w[i]});
	tot[0]=1,tot[1]=0;for(auto i:son)DFS(i.first,i.second,i.second),dfs(i.first,i.second,i.second,1);
	std::reverse(son.begin(),son.end());
	tot[0]=tot[1]=0;for(auto i:son)DFS(i.first,i.second,i.second),dfs(i.first,i.second,i.second,0);
	//printf("%d %lld\n",x,ans);
	for(auto i:son)rt=0,N=siz[i.first],getrt(i.first),solve(rt);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),a,b,c;
	for(int i=1;i<n;++i)a=gi(),b=gi(),c=gi(),link(a,b,c),link(b,a,c);
	N=n,f[0]=1e9,getrt(1);solve(rt);
	printf("%lld\n",ans);
	return 0;
}