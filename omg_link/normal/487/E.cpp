#include <stdio.h>
#include <string.h>
#include <set>
#include <stack>
#define MN 100000
#define MM 100000
const int INF=0x7fffffff;
int n,m,q,w[MN+5];
int low[MN+5],dfn[MN+5];
struct SG{
	int hd[MN+5],to[MM*2+5],nxt[MM*2+5];
	SG(){
		memset(hd,0xff,sizeof(hd));
	}
	void add(int u,int v){
		static int rn=0;
		to[rn]=v,nxt[rn]=hd[u];
		hd[u]=rn++;
	}
}sg;
struct CST{
	int hd[MN*2+5],to[MN*4+5],nxt[MN*4+5];
	int fa[MN*2+5],sn[MN*2+5],sz[MN*2+5],dfn[MN*2+5],adfn[MN*2+5],top[MN*2+5],dep[MN*2+5];
	int T[MN*8+5],dfn_cnt;
	std::multiset<int> s[MN*2+5];
	CST(){
		dfn_cnt=0;
		memset(hd,0xff,sizeof(hd));
	}
	void add(int u,int v){
//		printf("add %d %d\n",u,v);
		static int rn=0;
		to[rn]=v,nxt[rn]=hd[u];
		hd[u]=rn++;
	}
	void dfs1(int u){
		sz[u]=1;
		for(int i=hd[u];~i;i=nxt[i]){
			if(to[i]==fa[u]) continue;
			fa[to[i]]=u;
			dep[to[i]]=dep[u]+1;
			dfs1(to[i]);
			sz[u]+=sz[to[i]];
			if(sz[to[i]]>sz[sn[u]])
				sn[u]=to[i];
		}
		if(u>MN)
			for(int i=hd[u];~i;i=nxt[i]){
				if(to[i]==fa[u]) continue;
				s[u].insert(w[to[i]]);
			}
	}
	void dfs2(int u){
		dfn[u]=(++dfn_cnt);
		adfn[dfn[u]]=u;
		if(!top[u]) top[u]=u;
		if(sn[u]) top[sn[u]]=top[u],dfs2(sn[u]);
		for(int i=hd[u];~i;i=nxt[i]){
			if(to[i]==sn[u]||to[i]==fa[u]) continue;
			dfs2(to[i]);
		}
	}
	void build(int k,int l,int r){
		if(l==r){
			if(adfn[l])
				T[k]=*s[adfn[l]].begin();
			return;
		}
		int mid=(l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		T[k]=std::min(T[k<<1],T[k<<1|1]);
	}
	void modify(int k,int l,int r,int p){
//		printf("modify %d %d %d %d\n",k,l,r,p);
		if(l==r){
			T[k]=(*s[adfn[l]].begin());
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid) modify(k<<1,l,mid,p);
		else modify(k<<1|1,mid+1,r,p);
		T[k]=std::min(T[k<<1],T[k<<1|1]);
	}
	int query(int k,int l,int r,int L,int R){
		if(l==L&&r==R) return T[k];
		int mid=(l+r)>>1;
		if(R<=mid) return query(k<<1,l,mid,L,R);
		if(L>mid) return query(k<<1|1,mid+1,r,L,R);
		return std::min(query(k<<1,l,mid,L,mid),query(k<<1|1,mid+1,r,mid+1,R));
	}
	void change(int x,int y){
		if(fa[x]>MN){
			s[fa[x]].erase(s[fa[x]].find(w[x]));
			s[fa[x]].insert(y);
			modify(1,1,dfn_cnt,dfn[fa[x]]);
		}
		s[x].erase(w[x]);
		s[x].insert(y);
		modify(1,1,dfn_cnt,dfn[x]);
		w[x]=y;
	}
	int query(int x,int y){
		int ret=INF;
		for(;top[x]!=top[y];x=fa[top[x]]){
			if(dep[top[x]]<dep[top[y]]) std::swap(x,y);
			ret=std::min(ret,query(1,1,dfn_cnt,dfn[top[x]],dfn[x]));
		}
		if(dep[x]<dep[y]) std::swap(x,y);
		ret=std::min(ret,query(1,1,dfn_cnt,dfn[y],dfn[x]));
		if(y>MN) ret=std::min(ret,*s[fa[y]].begin());
		return ret;
	}
}cst;
void tarjan(int u){
	static int dfn_cnt=0;
	static std::stack<int> s;
	dfn[u]=low[u]=(++dfn_cnt);
	s.push(u);
	for(int i=sg.hd[u];~i;i=sg.nxt[i]){
		if(!dfn[sg.to[i]]){
			tarjan(sg.to[i]);
			low[u]=std::min(low[u],low[sg.to[i]]);
			if(low[sg.to[i]]>=dfn[u]){
				static int scc=MN;
				++scc;
				for(int x=s.top();;s.pop(),x=s.top()){
					cst.add(x,scc);
					cst.add(scc,x);
					cst.s[x].insert(w[x]);
					if(x==sg.to[i]){s.pop();break;}
				}
				cst.add(u,scc);
				cst.add(scc,u);
				cst.s[u].insert(w[u]);
			}
		}else{
			low[u]=std::min(low[u],dfn[sg.to[i]]);
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		sg.add(u,v),sg.add(v,u);
	}
	tarjan(1);
	cst.dfs1(1),cst.dfs2(1),cst.build(1,1,cst.dfn_cnt);
	while(q--){
		static char s[2];
		static int x,y;
		scanf("%s%d%d",&s[0],&x,&y);
		/*
		printf("operation is %s %d %d\n",s,x,y);
		puts("----");
		for(int i=1;i<=9;i++)
			printf("T[%d] = %d (aka %d)\n",i,cst.query(1,1,cst.dfn_cnt,i,i),cst.adfn[i]);
		puts("----");
		*/
		if(s[0]=='C'){
			cst.change(x,y);
		}else{
			printf("%d\n",cst.query(x,y));
		}
	}
}