#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int dfn[200005];
int n;
V<int> v[200005];
int siz[200005],son[200005];
int cnt=0,fa[200005],top[200005],dep[200005],it[200005];
void dfs1(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		fa[u]=x;dep[u]=dep[x]+1;
		dfs1(u,x),siz[x]+=siz[u];
		if(siz[son[x]]<siz[u])son[x]=u;
	}
}
int sum[200005];
void dfs2(int x,int y,int tp){
	top[x]=tp;
	dfn[x]=++cnt;it[cnt]=x;
	if(son[x])dfs2(son[x],x,tp);
	for(auto u:v[x])if(u!=y&&u!=son[x]){
		dfs2(u,x,u);
	}
}
P<int,int> p[200005];
int snode[1<<19][2],sedge[1<<19][2];
void up(int x){
	rep(i,0,2){
		snode[x][i]=snode[lc][i]+snode[rc][i];
		sedge[x][i]=sedge[lc][i]+sedge[rc][i];
	}
}
int tag[1<<19];
void build(int x,int l,int r){
	if(l==r){
		snode[x][1]=1;
		sedge[x][1]=sum[l];
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(x);
}
void ch(int x){
	swap(snode[x][0],snode[x][1]);
	swap(sedge[x][0],sedge[x][1]);
	tag[x]^=1;
} 
void pushdown(int x){
	if(tag[x]){
		tag[x]=0;
		ch(lc);
		ch(rc);
	}
}
V<int> ed;
void update(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		ch(x);
		RE;
	}
	if(l>tr||tl>r)RE ;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,tl,tr);
	update(rc,mid+1,r,tl,tr);
	up(x);
}
void solve(int x,int l,int r){
	if(l==r){
		if(snode[x][0]){
			ed.PB(sum[l]);
		}
		RE;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	solve(lc,l,mid);
	solve(rc,mid+1,r);
}
signed main(){
	cin>>n;
	FOR(i,2,n){
		int x,y;
		cin>>x>>y;
		p[i]=MP(x,y);
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs1(1,-1);dfs2(1,-1,1);
	FOR(i,2,n){
		if(dep[p[i].F]<dep[p[i].S]){
			sum[dfn[p[i].S]]=i-1;
		}else{
			sum[dfn[p[i].F]]=i-1;
		}
	}
	build(1,1,n);
	int node=1;
	update(1,1,n,1,1);
	while(1){
		int tap;
		cin>>tap;
		if(tap==3){
			break;
		}else if(tap==1){
			node++;
			int x;
			cin>>x;
			while(x){
				update(1,1,n,dfn[top[x]],dfn[x]);
				x=fa[top[x]];
			}
			if(snode[1][0]==node/2){
				cout<<sedge[1][0]<<'\n';
			}else cout<<0<<'\n';
			fflush(stdout);
		}else{
			if(snode[1][0]==node/2){
				cout<<node/2<<' ';
				ed.clear();
				solve(1,1,n);
				sort(ALL(ed));
				for(auto u:ed)cout<<u<<' ';
				cout<<'\n';
			}else cout<<0<<'\n';
			fflush(stdout);
		}
	}
	RE 0;
}