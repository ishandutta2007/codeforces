#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct dsu{
	int fa[200010],sz[200010];
	void pre(int n){for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;}
	int hd(int x){return fa[x]==x?x:fa[x]=hd(fa[x]);}
	void Union(int a,int b){
		a=hd(a),b=hd(b);if(a==b)return;
		if(sz[a]>sz[b])std::swap(a,b);
		fa[a]=b,sz[b]+=sz[a];
	}
}A,B;
int n,m;
int fir[200010],head[200010],dis[400010],nxt[400010],w[400010],dwn[400010],id=1;
void link(int a,int b,int c=-1){nxt[++id]=fir[a],fir[a]=id,dis[id]=b,w[id]=c;}
std::vector<int>vA,vB,vC;
int pa[200010],pb[200010],fa[200010],dep[200010],son[200010],top[200010],siz[200010];
bool intree[200010];
void dfs(int x){
	siz[x]=1;
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa[x])continue;
		dep[dis[i]]=dep[x]+1;
		dwn[i]=dwn[i^1]=dis[i];
		fa[dis[i]]=x;
		dfs(dis[i]);
		siz[x]+=siz[dis[i]];
		if(siz[son[x]]<siz[dis[i]])son[x]=dis[i];
	}
}
int dfn[200010],end[200010];
void dfs(int x,int tp){
	dfn[x]=++dfn[0];
	top[x]=tp;if(son[x])dfs(son[x],tp);
	for(int i=fir[x];i;i=nxt[i])if(fa[x]!=dis[i]&&son[x]!=dis[i])dfs(dis[i],dis[i]);
	end[x]=dfn[0];
}
bool vis[200010];
int stk[200010],tp;
bool DFS(int x,int t,std::vector<int>&vec,bool o=0){
	if(!o)stk[++tp]=x;
	if(x==t){
		for(int i=1;i<=tp;++i)vec.push_back(stk[i]);
		tp=0;
		return 1;
	}
	vis[x]=1;
	for(int&i=head[x];i;i=nxt[i])
		if(w[i]>0&&!vis[dis[i]]){
			w[i]=w[i^1]=0;
			if(o)stk[++tp]=i;
			if(DFS(dis[i],t,vec,o))return vis[x]=!o,1;
			if(o)--tp;
		}
	vis[x]=0;
	if(!o)--tp;return 0;
}
void output(){
	puts("YES");
	printf("%d ",vA.size());for(int x:vA)printf("%d ",x);puts("");
	printf("%d ",vB.size());for(int x:vB)printf("%d ",x);puts("");
	printf("%d ",vC.size());for(int x:vC)printf("%d ",x);puts("");
	exit(0);
}
int t[200010];
void update(int x,int o){while(x<=n)t[x]+=o,x+=x&-x;}
int query(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi(),m=gi();
	A.pre(n),B.pre(n);
	for(int i=1;i<=m;++i){
		int a=gi(),b=gi();
		pa[i]=a,pb[i]=b;
		if(A.hd(a)!=A.hd(b))A.Union(a,b),link(a,b,1),link(b,a,1),intree[i]=1;
	}
	for(int i=1;i<=n;++i)if(!dep[i])dep[i]=1,dfs(i),dfs(i,i);
	auto isanc=[&](int a,int b){return dfn[a]<=dfn[b]&&dfn[b]<=end[a];};
	auto LCA=[&](int a,int b){
		while(top[a]^top[b]){
			if(dep[top[a]]>dep[top[b]])a=fa[top[a]];
			else b=fa[top[b]];
		}
		return dep[a]<dep[b]?a:b;
	};
	for(int i=1;i<=m;++i){
		if(intree[i])continue;
		int a=pa[i],b=pb[i],ha=a,hb=b;
		if(dfn[ha]>dfn[hb])std::swap(a,b),std::swap(ha,hb);
		if(isanc(ha,hb)){
			if(isanc(son[ha],hb))ha=son[ha];
			else{
				int _=ha;ha=hb;
				while(fa[ha]!=_)ha=top[fa[ha]];
			}
		}
		int _a=ha,_b=hb,lca=LCA(a,b);
		ha=B.hd(ha),hb=B.hd(hb);
		if(ha==hb){
			memset(w,1,sizeof w);
			memcpy(head,fir,sizeof fir);DFS(a,b,vA);
			memcpy(head,fir,sizeof fir);DFS(a,b,vB);
			vC={a,b},output();
		}else if(B.sz[ha]>1||B.sz[hb]>1){
			if(B.sz[ha]==1)std::swap(a,b),std::swap(_a,_b);
			std::vector<int>v;
			memcpy(head,fir,sizeof fir);DFS(a,b,v,1);
			link(a,b),link(b,a);
			memset(w,1,sizeof w);
			int d;
			for(int x:v)if(B.hd(dwn[x])!=B.hd(_a)){d=dis[x^1];break;}
			memcpy(head,fir,sizeof fir);DFS(d,a,vA);
			memcpy(head,fir,sizeof fir);DFS(d,a,vB);
			memcpy(head,fir,sizeof fir);DFS(d,a,vC);
			output();
		}else if(query(dfn[a])+query(dfn[b])>2*query(dfn[lca])){
			std::vector<int>v;
			memcpy(head,fir,sizeof fir);DFS(a,b,v,1);
			link(a,b),link(b,a);
			memset(w,1,sizeof w);
			int p=-1,q,_;
			for(int x:v)
				if(p==-1&&B.sz[B.hd(dwn[x])]>1)p=dis[x^1],_=B.hd(dwn[x]);
				else if(~p&&B.hd(dwn[x])!=B.hd(_)){q=dis[x^1];break;}
			memcpy(head,fir,sizeof fir);DFS(p,q,vA);
			memcpy(head,fir,sizeof fir);DFS(p,q,vB);
			memcpy(head,fir,sizeof fir);DFS(p,q,vC);
			output();
		}else{
			int x=a,y=b,_;if(dep[x]<dep[y])std::swap(x,y);
			_=x;
			while(dep[x]>dep[y])B.Union(x,_),update(dfn[x],1),update(end[x]+1,-1),x=fa[x];
			while(x!=y)B.Union(x,_),B.Union(y,_),update(dfn[x],1),update(end[x]+1,-1),update(dfn[y],1),update(end[y]+1,-1),x=fa[x],y=fa[y];
			link(a,b),link(b,a);
		}
	}
	puts("NO");
	return 0;
}