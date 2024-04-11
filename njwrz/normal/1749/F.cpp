#include<bits/stdc++.h>
#define ll long long
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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
void read(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int n;
V<int> v[200005];
int cnt,dfn[200005],R[200005],fa[200005][20],dep[200005],son[200005],siz[200005],top[200005];
void dfs(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u!=y){
		dep[u]=dep[x]+1;fa[u][0]=x;
		dfs(u,x);
		siz[x]+=siz[u];
		if(siz[u]>siz[son[x]])son[x]=u;
	}
}
void dfs2(int x,int y,int tp){
	top[x]=tp;
	dfn[x]=++cnt;
	if(son[x])dfs2(son[x],x,tp);
	for(auto u:v[x])if(u!=y&&u!=son[x]){
		dfs2(u,x,u);
	}
	R[x]=cnt;
}
int lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	int t=dep[x]-dep[y];
	FOR(i,0,18)if(t&(1<<i))x=fa[x][i];
	if(x==y)RE x;
	for(int i=18;i>=0;i--)if(fa[x][i]!=fa[y][i]){
		x=fa[x][i];y=fa[y][i];
	}
	RE fa[x][0];
}
int ans[200005];
struct query{
	int tap;
	int x,y,k,d,mid,id;
};
struct bit{
	int s[200005];
	void init(int n){
		FOR(i,1,n)s[i]=0;
	}
	void update(int x,int y){
		while(x<=n){
			s[x]+=y;
			x+=x&-x;
		}
	}
	void update(int x,int y,int val){
		if(x>y)RE;
		update(x,val);update(y+1,-val);
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
}T;
query q[200005];
int num[21][200005],len;
int m;
void update(int x,int y,int val){
	if(dep[x]<dep[y])RE;
	while(1){
		if(dep[top[x]]<=dep[y]){
			T.update(dfn[y],dfn[x],val);RE;
		}
		T.update(dfn[top[x]],dfn[x],val);
		x=fa[top[x]][0];
	}
}
void update2(int x,int y,int val){
	if(dep[x]<=dep[y])RE;
	while(1){
		if(dep[top[x]]<=dep[y]){
			T.update(dfn[y]+1,dfn[x],val);RE;
		}
		T.update(dfn[top[x]],dfn[x],val);
		x=fa[top[x]][0];
	}
}
void solve(int d){
	T.init(n);
	FILL(num,0);
	len=0;
	bool tf=0;
	FOR(i,1,m){
		if(q[i].tap==1){
			if(!tf)continue;
			int now=q[i].x,lst=-1;
			rep(j,0,d){
				ans[i]+=num[d-j][now];
				if(j&&d-j>0)ans[i]-=num[d-j-1][lst];
				lst=now;now=fa[now][0];
				if(!now)break;
			}
			if(now){
				ans[i]+=T.get(dfn[now]);
			}
		}else if(q[i].d==d){
			tf=1;
			int now=q[i].mid;
			FOR(j,0,d){
				FOR(t,j,d)num[t][now]+=q[i].k;
				now=fa[now][0];
			}
			update(q[i].x,q[i].mid,q[i].k);
			update2(q[i].y,q[i].mid,q[i].k);
		}
	}
}
bool vis[22];
signed main(){
	read(n);
	FOR(i,2,n){
		int x,y;
		read(x);read(y);
		v[x].PB(y);
		v[y].PB(x);
	}
	dfs(1,-1);dfs2(1,-1,1);
	FOR(i,1,18)FOR(j,1,n)fa[j][i]=fa[fa[j][i-1]][i-1];
	read(m);
	FOR(i,1,m){
		read(q[i].tap);q[i].id=i;
		if(q[i].tap==1){
			read(q[i].x);
		}else{
			read(q[i].x);read(q[i].y);read(q[i].k);read(q[i].d);
			q[i].mid=lca(q[i].x,q[i].y);
			vis[q[i].d]=1;
		}
	}
	FOR(i,0,20)if(vis[i])solve(i);
	FOR(i,1,m)if(q[i].tap==1){
		write(ans[i]);putchar('\n');
	}
	RE 0;
}