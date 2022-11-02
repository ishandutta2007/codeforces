#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<set>
#define pb push_back
using namespace std;
const int N=1e5+55;
int n,m,q,w[N*2],x,y,z,id;
int pos[N*2],dfn[N*2];
struct Seg{
	#define mid ((l+r)>>1)
	#define ls (u<<1)
	#define rs (u<<1|1)
	int minn[N*10];
	void update(int u){
		minn[u]=min(minn[ls],minn[rs]);
	}
	void build(int u,int l,int r){
		if(l==r){
			minn[u]=w[pos[l]];
			return ;
		}
		build(ls,l,mid);
		build(rs,mid+1,r);
		update(u);
	}
	void modify(int u,int l,int r,int x,int k){
		if(l==r){
			minn[u]=k;
			return ;
		}
		if(x<=mid)modify(ls,l,mid,x,k);
		else modify(rs,mid+1,r,x,k);
		update(u);
	}
	int query(int u,int l,int r,int L,int R){
		if(L<=l and R>=r){
			return minn[u];
		}
		int minn=1e9+7;
		if(L<=mid)minn=query(ls,l,mid,L,R);
		if(R>mid)minn=min(minn,query(rs,mid+1,r,L,R));
		return minn;
	}
}T;
struct Tree{
	vector<int>v[N*2];
	multiset<int>s[N*2];
	void add(int e,int r){
		v[e].pb(r);
		v[r].pb(e);
	}
	int deep[N*2],son[N*2],siz[N*2],top[N*2],fu[N*2],tot;
	void dfs1(int u,int fa){
		siz[u]=1;
		deep[u]=deep[fa]+1;
		fu[u]=fa;
		for(int i=0;i<v[u].size();i++){
			if(v[u][i]==fa)continue;
			dfs1(v[u][i],u);
			siz[u]+=siz[v[u][i]];
			if(siz[v[u][i]]>siz[son[u]]){
				son[u]=v[u][i];
			}
		}
	}
	void dfs2(int u,int fa){
		top[u]=fa;dfn[u]=++tot;pos[tot]=u;
		if(son[u])dfs2(son[u],fa);
		for(int i=0;i<v[u].size();i++){
			if(top[v[u][i]])continue;
			dfs2(v[u][i],v[u][i]);
		}
	}
	void init(){
		dfs1(1,0);
		dfs2(1,1);
		for(int i=n+1;i<=id;i++){
			for(int k=0;k<v[i].size();k++){
				if(deep[v[i][k]]==deep[i]+1){
					s[i].insert(w[v[i][k]]);
				}
				if(!s[i].size())w[i]=1e9+7;
				else w[i]=*s[i].begin();
			}
		}
		T.build(1,1,id);
	}
	void change(int x,int y){
		if(fu[x]){
			s[fu[x]].erase(s[fu[x]].lower_bound(w[x]));
			s[fu[x]].insert(y);
			w[fu[x]]=*s[fu[x]].begin();
			T.modify(1,1,id,dfn[fu[x]],w[fu[x]]);
		}
		w[x]=y;
		T.modify(1,1,id,dfn[x],y);
	}
	int query(int x,int y){
		int ans=1e9+7;
		while(top[x]!=top[y]){
			if(deep[top[x]]<deep[top[y]])swap(x,y);
			ans=min(ans,T.query(1,1,id,dfn[top[x]],dfn[x]));
			x=fu[top[x]];
		}
		if(deep[x]<deep[y]){
			swap(x,y);
		}
		ans=min(ans,T.query(1,1,id,dfn[y],dfn[x]));
		if(y>n){
			ans=min(ans,w[fu[y]]);
		}
		return ans;
	}
}t;
struct pre{
	vector<int>v[N];
	void add(int e,int r){
		v[e].pb(r);
		v[r].pb(e);
	}
	int dfn[N],low[N],tot,st[N],top;
	void tarjan(int u){
		st[++top]=u;
		low[u]=dfn[u]=++tot;
		for(int i=0;i<v[u].size();i++){
			if(!dfn[v[u][i]]){
				int jl=top;
				tarjan(v[u][i]);
				low[u]=min(low[u],low[v[u][i]]);
				if(low[v[u][i]]>=dfn[u]){
					id++;
					t.add(id,u);
					while(top>jl){
						t.add(st[top],id);
						top--;
					}
				}
			}
			else{
				low[u]=min(low[u],dfn[v[u][i]]);
			}
		}
	}
	void init(){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&w[i]);
		}
		id=n;
		for(int i=1;i<=m;i++){
			scanf("%d%d",&x,&y);
			add(x,y);
		}
		tarjan(1);
	}
}S;
char opt[3];
void solve(){
	for(int i=1;i<=q;i++){
		scanf("%s",opt+1);
		scanf("%d%d",&x,&y);
		if(opt[1]=='C'){
			t.change(x,y);
		}
		else{
			printf("%d\n",t.query(x,y));
		}
	}
}
int main(){
	S.init();
	t.init();
	solve();
	return 0;
}
/*
3 3 1
1 2 3
1 2
2 3
1 3
A 2 3
*/