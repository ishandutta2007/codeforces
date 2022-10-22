#pragma GCC optimize("Ofast","inline","unroll-loops")
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
int n;
V<P<int,int> > v[100005];
V<int> g[100005];
int siz[100005],vis[100005],L,R;
P<int,int> hav;
int mi,node,tot;
void getsiz(int x,int y){
	siz[x]=1;
	for(auto u:v[x])if(u.F!=y&&!vis[u.F]){
		getsiz(u.F,x);
		siz[x]+=siz[u.F];
	}
}
void getrt(int x,int y){
	int mx=tot-siz[x];
	for(auto u:v[x])if(u.F!=y&&!vis[u.F]){
		getrt(u.F,x);
		gmax(mx,siz[u.F]);
	}
	if(mx<mi){
		mi=mx;node=x;
	} 
}
void dfs(int lst,int x){
	getsiz(x,-1);tot=siz[x];
	mi=1e9;node=-1;
	getrt(x,-1);
	int mid=node;
	g[lst].PB(mid);vis[mid]=1;
	for(auto u:v[mid])if(!vis[u.F])dfs(mid,u.F);
}
const int inf=1e9;
struct seg{
	P<int,int> p[1<<18];
	void update(int x,int l,int r,int it,P<int,int> val){
		if(l==r){
			gmax(p[x],val);RE;
		}
		int mid=(l+r)>>1;
		if(mid>=it)update(lc,l,mid,it,val);
		else update(rc,mid+1,r,it,val);
		p[x]=max(p[lc],p[rc]);
	}
	void clear(int x,int l,int r){
		if(p[x].F==-inf)RE;
		p[x]=MP(-inf,-inf);
		if(l==r)RE;
		int mid=(l+r)>>1;
		if(p[lc].F!=-inf)clear(lc,l,mid);
		if(p[rc].F!=-inf)clear(rc,mid+1,r);
	}
	P<int,int> get(int x,int l,int r,int tl,int tr){
		if(l>=tl&&r<=tr)RE p[x];
		int mid=(l+r)>>1;
		if(mid>=tr)RE get(lc,l,mid,tl,tr);
		else if(tl>mid)RE get(rc,mid+1,r,tl,tr);
		else RE max(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
	}
}T;
P<int,int> t[100005];
V<int> nd[100005];
int lim,dep[100005];
int M;
void gett(int x,int y,int val){
	gmax(M,dep[x]);
	t[x]=MP(val,x);
	for(auto u:v[x])if(u.F!=y&&!vis[u.F]){
		dep[u.F]=dep[x]+1;
		gett(u.F,x,val+((u.S>=lim)?1:-1));
	}
}
void getnd(int x,int y,int ch){
	nd[ch].PB(x);
	for(auto u:v[x])if(u.F!=y&&!vis[u.F])getnd(u.F,x,ch);
}
void getans(int x){
	M=0;
	dep[x]=0;
	gett(x,-1,0);
	for(auto u:v[x])if(!vis[u.F])nd[u.F].clear(),getnd(u.F,x,u.F);
	T.update(1,0,M,0,MP(0,x));
	bool f=0;
	int MX=0;
	for(auto u:v[x])if(!vis[u.F]){
		for(auto tu:nd[u.F]){
			int tl=L-dep[tu],tr=R-dep[tu];
			gmax(tl,0);gmin(tr,MX);
			if(tl<=tr){
				P<int,int> pos=T.get(1,0,M,tl,tr);
				if(pos.F+t[tu].F>=0){
					hav=MP(tu,pos.S);f=1;break;
				}
			}
		}
		if(f)break;
		for(auto tu:nd[u.F]){
			gmax(MX,dep[tu]);
			T.update(1,0,M,dep[tu],t[tu]);
		}
	}
	T.clear(1,0,M);
	if(f)RE ;
	vis[x]=1;
	for(auto u:g[x]){
		getans(u);
		if(hav.F!=-1)RE ;
	}
}
void check(int x){
	hav=MP(-1,-1);
	lim=x;
	FILL(vis,0);
	getans(g[0][0]);
}
V<int> num;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>L>>R;
	FOR(i,2,n){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
		num.PB(z);
	}
	sort(ALL(num));
	num.erase(unique(ALL(num)),num.end());
	dfs(0,1);
	rep(i,1,(1<<18))T.p[i]=MP(-1e9,-1e9);
	int l=0,r=num.size()-1,mid,ans=-1;
	while(r>=l){
		mid=l+(r-l)/3;
		check(num[mid]);
		if(hav.F==-1){
			r=mid-1;
		}else l=mid+1,ans=mid;
	}
	check(num[ans]);
	cout<<hav.F<<' '<<hav.S;
	RE 0;
}