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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,q;
P<int,P<int,int> > e[300005];
V<int> v[600005];
int fa[600005];
int getfa(int x){
	RE (fa[x]==x)?x:(fa[x]=getfa(fa[x]));
}
int val[600005],up[600005][20];
int cnt;
int tag[1<<20],dep[600005],maxi=1e9;
P<int,int> hmi[1<<20],hmx[1<<20],it[1<<20],mi[1<<20],mx[1<<20];
int lca(int x,int y){
	if(dep[x]>dep[y])swap(x,y);
	int t=dep[y]-dep[x];
	rep(i,0,20)if(t&(1<<i)){
		y=up[y][i];
	}
	if(x==y)RE x;
	for(int i=19;i>=0;i--)if(up[x][i]!=up[y][i]){
		x=up[x][i];y=up[y][i];
	}
	RE up[x][0];
}
void dfs(int x,int y){
	++cnt;
	if(x<=n)it[x]=MP(cnt,x);
	for(auto u:v[x])if(u!=y){
		up[u][0]=x;dep[u]=dep[x]+1;
		dfs(u,x);
	}
}
void build(int x,int l,int r){
	mi[x]=MP(maxi,0);
	if(l==r){
		hmi[x]=hmx[x]=it[l];
		RE;
	} 
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	hmi[x]=min(hmi[lc],hmi[rc]);
	hmx[x]=max(hmx[lc],hmx[rc]);
}
void pushdown(int x){
	if(tag[x]==1){
		mi[lc]=hmi[lc];mi[rc]=hmi[rc];
		mx[lc]=hmx[lc];mx[rc]=hmx[rc];
		tag[lc]=1;
		tag[rc]=1;
	}else if(tag[x]==-1){
		mi[lc]=MP(maxi,0);mi[rc]=MP(maxi,0);
		mx[lc]=MP(0,0);mx[rc]=MP(0,0);
		tag[lc]=-1;
		tag[rc]=-1;
	}
	tag[x]=0;
}
void update1(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		mi[x]=hmi[x];
		mx[x]=hmx[x];
		tag[x]=1;
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	update1(lc,l,mid,tl,tr);
	update1(rc,mid+1,r,tl,tr);
	mi[x]=min(mi[lc],mi[rc]);
	mx[x]=max(mx[lc],mx[rc]);
}
void update2(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		mi[x]=MP(maxi,0);
		mx[x]=MP(0,0);
		tag[x]=-1;
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	pushdown(x);
	update2(lc,l,mid,tl,tr);
	update2(rc,mid+1,r,tl,tr);
	mi[x]=min(mi[lc],mi[rc]);
	mx[x]=max(mx[lc],mx[rc]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	FOR(i,1,n+n)fa[i]=i;
	rep(i,1,n){
		cin>>e[i].S.F>>e[i].S.S>>e[i].F;
	}
	sort(e+1,e+n);
	rep(i,1,n){
		int x=getfa(e[i].S.F),y=getfa(e[i].S.S);
		fa[x]=i+n;fa[y]=i+n;
		val[i+n]=e[i].F;
		v[i+n].PB(x);
		v[i+n].PB(y);
	}
	dfs(n+n-1,-1);
	rep(i,1,20){
		FOR(j,1,n+n){
			up[j][i]=up[up[j][i-1]][i-1];
		}
	}
	build(1,1,n);
	FOR(_,1,q){
		int tap,l,r;
		cin>>tap;
		if(tap==1){
			cin>>l>>r;
			update1(1,1,n,l,r);
		}else if(tap==2){
			cin>>l>>r;
			update2(1,1,n,l,r);
		}else {
			cin>>l;
			int t1=mi[1].S,t2=mx[1].S;
			int ans=-1;
			if(t1&&t1!=l){
				gmax(ans,val[lca(t1,l)]);
			}
			if(t2&&t2!=l){
				gmax(ans,val[lca(t2,l)]);
			}
			cout<<ans<<'\n';
		}
	}
	RE 0;
}