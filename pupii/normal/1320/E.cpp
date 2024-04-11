#include<bits/stdc++.h>
#define mod 1019260817
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int fir[200010],dis[400010],nxt[400010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int key[200010],num[1000010],to[200010];
int o,dfn[200010],end[200010],spd[200010],siz[200010],son[200010],fa[200010],top[200010],dep[200010];
void dfs(int x){
	siz[x]=1;dfn[x]=++dfn[0];
	for(int i=fir[x];i;i=nxt[i]){
		if(fa[x]==dis[i])continue;
		fa[dis[i]]=x;
		dep[dis[i]]=dep[x]+1;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[dis[i]]>siz[son[x]])son[x]=dis[i];
	}
	end[x]=dfn[0];
}
void dfs(int x,int tp){
	top[x]=tp;if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i]&&son[x]!=dis[i])dfs(dis[i],dis[i]);
}
int LCA(int x,int y){
	while(top[x]^top[y])
		if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
		else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
struct edge{int t,w;};
std::vector<edge>G[200010];
int stk[200010],f[200010],g[200010],sta[200010];
#define pi std::pair<int,int>
void DFS(int x,int fa=-1){
	for(edge i:G[x])
		if(fa!=i.t){
			DFS(i.t,x);
			if(g[i.t]&&(!g[x]||pi{(f[i.t]+spd[g[i.t]]-1+i.w)/spd[g[i.t]],g[i.t]}<pi{(f[x]+spd[g[x]]-1)/spd[g[x]],g[x]}))f[x]=f[i.t]+i.w,g[x]=g[i.t];
		}
}
void DFS2(int x,int fa=-1){
	for(edge i:G[x])
		if(fa!=i.t){
			if(g[x]&&(!g[i.t]||pi{(f[x]+spd[g[x]]-1+i.w)/spd[g[x]],g[x]}<pi{(f[i.t]+spd[g[i.t]]-1)/spd[g[i.t]],g[i.t]}))f[i.t]=f[x]+i.w,g[i.t]=g[x];
			DFS2(i.t,x);
		}
}
signed main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),x,y;
	for(int i=1;i<n;++i)x=gi(),y=gi(),link(x,y),link(y,x);
	int q=gi();
	dep[1]=1;dfs(1);dfs(1,1);
	std::queue<int>que;
	while(q--){
		int k=gi(),m=gi();o=0;
		for(int i=1;i<=k;++i)sta[i]=num[++o]=gi(),spd[i]=gi();
		for(int i=1;i<=m;++i)key[i]=gi(),num[++o]=key[i];
		std::sort(num+1,num+o+1,[&](int a,int b){return dfn[a]<dfn[b];});o=std::unique(num+1,num+o+1)-num-1;
		for(int i=1;i<o;++i)num[i+o]=LCA(num[i],num[i+1]);
		o+=o-1;
		std::sort(num+1,num+o+1,[&](int a,int b){return dfn[a]<dfn[b];});o=std::unique(num+1,num+o+1)-num-1;
		for(int i=1;i<=o;++i)to[num[i]]=i,G[i].clear();
		auto isanc=[&](int a,int b){return dfn[a]<=dfn[b]&&dfn[b]<=end[a];};
		for(int i=1,tp=0;i<=o;++i){
			while(tp&&!isanc(num[stk[tp]],num[i]))--tp;
			if(tp)G[i].push_back({stk[tp],dep[num[i]]-dep[num[stk[tp]]]}),G[stk[tp]].push_back({i,dep[num[i]]-dep[num[stk[tp]]]});
			stk[++tp]=i;
		}
		for(int i=1;i<=o;++i)f[i]=1e9,g[i]=0;
		for(int i=1;i<=k;++i)sta[i]=to[sta[i]],f[sta[i]]=0,g[sta[i]]=i;
		for(int i=1;i<=m;++i)key[i]=to[key[i]];
		DFS(1);
		DFS2(1);
		for(int i=1;i<=m;++i)printf("%d ",g[key[i]]);puts("");
	}
	return 0;
}