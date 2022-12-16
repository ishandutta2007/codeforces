#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <vector>
#define MN 300000

using std::max;
using std::swap;
using std::vector;

using ll = long long;

namespace GTI
{
	char gc(void)
   	{
		const int S = 1 << 16;
		static char buf[S], *s = buf, *t = buf;
		if (s == t) t = buf + fread(s = buf, 1, S, stdin);
		if (s == t) return EOF;
		return *s++;
	}
	ll gti(void)
   	{
		ll a = 0, b = 1, c = gc();
		for (; !isdigit(c); c = gc()) b ^= (c == '-');
		for (; isdigit(c); c = gc()) a = a * 10 + c - '0';
		return b ? a : -a;
	}
	int gts(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && !isspace(c); c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
	int gtl(char *s)
   	{
		int len = 0, c = gc();
		for (; isspace(c); c = gc());
		for (; c != EOF && c != '\n'; c = gc()) s[len++] = c;
		s[len] = 0;
		return len;
	}
}
using GTI::gti;
using GTI::gts;
using GTI::gtl;

namespace Graph{
	const int logN = 19;

	struct Edge{
		int v,w;
	};
	
	struct VTreeState{
		int root;
		int maxW;
	};
	
	int dep[MN+5],fa[MN+5][logN],we[MN+5][logN];
	vector<Edge> e[MN+5];
	
	void addEdge(int u,int v,int w){
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	
	void dfs(int u){
		for(int i=0;i<logN-1;i++){
			if(fa[u][i]){
				fa[u][i+1] = fa[fa[u][i]][i];
				we[u][i+1] = max(we[u][i],we[fa[u][i]][i]);
			}else{
				break;
			}
		}
		for(Edge edge:e[u]){
			int v = edge.v;
			int w = edge.w;
			if(v==fa[u][0]) continue;
			dep[v] = dep[u]+1;
			we[v][0] = w;
			fa[v][0] = u;
			dfs(v);
		}
	}
	
	void init(){
		dfs(1);
	}
	
	//aka lca
	VTreeState operator + (const VTreeState& lhs,const VTreeState& rhs){
		int u = lhs.root;
		int v = rhs.root;
		int w = max(lhs.maxW,rhs.maxW);
		if(u==0) return {v,w};
		if(v==0) return {u,w};
		if(dep[u]<dep[v]){
			swap(u,v);
		}
		for(int d=dep[u]-dep[v],i=logN-1;i>=0;i--){
			if(d&(1<<i)){
				w = max(w,we[u][i]);
				u = fa[u][i];
			}
		}
		if(u==v) return {u,w};
		for(int i=logN-1;i>=0;i--){
			if(fa[u][i]!=fa[v][i]){
				w = max({w,we[u][i],we[v][i]});
				u = fa[u][i];
				v = fa[v][i];
			}
		}
		w = max({w,we[u][0],we[v][0]});
		return {fa[u][0],w};
	}
	
}

using Graph::addEdge;

namespace SegmentTree{
	using Graph::VTreeState;
	
	enum Tag{
		EMPTY,FULL,CLEAR
	};
	
	struct Node{
		VTreeState current,full;
		Tag tag;
	}T[MN*4+5];
	
	void pushup(int k){
		T[k].current = T[k<<1].current+T[k<<1|1].current;
	}
	
	void pushtag(int k,Tag tag){
		if(tag==FULL){
			T[k].current = T[k].full;
			T[k].tag = FULL;
		}
		if(tag==CLEAR){
			T[k].current = {0,-1};
			T[k].tag = CLEAR;
		}
	}
	
	void pushdown(int k){
		if(T[k].tag!=EMPTY){
			pushtag(k<<1,T[k].tag);
			pushtag(k<<1|1,T[k].tag);
			T[k].tag = EMPTY;
		}
	}
	
	void build(int k,int l,int r){
		T[k].tag = EMPTY;
		T[k].current = {0,-1};
		if(l==r){
			T[k].full = {l,-1};
			return;
		}
		int mid = (l+r)>>1;
		build(k<<1,l,mid);
		build(k<<1|1,mid+1,r);
		T[k].full = T[k<<1].full+T[k<<1|1].full;
	}
	
	void modify(int k,int l,int r,int L,int R,Tag tag){
		if(l==L&&r==R){
			pushtag(k,tag);
			return;
		}
		int mid = (l+r)>>1;
		pushdown(k);
		if(R<=mid) modify(k<<1,l,mid,L,R,tag);
		else if(L>mid) modify(k<<1|1,mid+1,r,L,R,tag);
		else modify(k<<1,l,mid,L,mid,tag),modify(k<<1|1,mid+1,r,mid+1,R,tag);
		pushup(k);
	}
	
	int query(int x){
		return (T[1].current+(VTreeState){x,-1}).maxW;
	}
	
}

using SegmentTree::modify;
using SegmentTree::query;

int main(){
	int n,q;
	n = gti();
	q = gti();
	for(int i=2;i<=n;i++){
		int u,v,w;
		u = gti();
		v = gti();
		w = gti(); 
		addEdge(u,v,w);
	}
	Graph::init();
	SegmentTree::build(1,1,n);
	while(q--){
		int o;
		o = gti();
		if(o==1){
			int l,r;
			l = gti();
			r = gti();
			modify(1,1,n,l,r,SegmentTree::FULL);
		}
		if(o==2){
			int l,r;
			l = gti();
			r = gti();
			modify(1,1,n,l,r,SegmentTree::CLEAR);
		}
		if(o==3){
			int x;
			x = gti();
			printf("%d\n",query(x));
		}
	}
}