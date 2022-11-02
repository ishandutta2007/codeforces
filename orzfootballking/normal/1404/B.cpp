#pragma GCC optimize("Ofast")
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
#define rc ((x<<1)|1)
using namespace std;
V<int> v[100005];
int dis[100005],in[100005],out[100005],cnt,dys[100005],p[100005];
int maxi[300005],tag[300005];
bool to;
void pd(int x,int l,int r){
	if(l!=r){
		maxi[lc]+=tag[x];
		maxi[rc]+=tag[x];
		tag[lc]+=tag[x];
		tag[rc]+=tag[x];
	}
	tag[x]=0;
} 
void build(int x,int l,int r){
	tag[x]=0;
	if(l==r){
		maxi[x]=dis[p[l]];
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	maxi[x]=max(maxi[lc],maxi[rc]);
}
void up(int x,int l,int r,int tl,int tr,int add){
	pd(x,l,r);
	if(l>tr||tl>r)RE;
	if(l>=tl&&r<=tr){
		maxi[x]+=add;
		tag[x]+=add;RE ;
	}
	int mid=(l+r)>>1;
	up(lc,l,mid,tl,tr,add);
	up(rc,mid+1,r,tl,tr,add);
	maxi[x]=max(maxi[lc],maxi[rc]);
}
void dfs(int x,int fa){
	in[x]=++cnt;p[in[x]]=x;
	for(auto u:v[x])if(u!=fa){
		dis[u]=dis[x]+1;dfs(u,x);
	}	
	out[x]=cnt;
} 
int a,b,da,db;
int n;
void get(int x,int fa){
//	cout<<x<<' '<<maxi[1]<<' '<<in[x]<<' '<<out[x]<<'\n'; 
	if(dis[x]>da&&dys[x]<=db){
		if(maxi[1]>da*2)to=1;
	}
	for(auto u:v[x])if(u!=fa){
		up(1,1,n,in[u],out[u],-2);
		up(1,1,n,1,n,1);
		get(u,x);
		up(1,1,n,in[u],out[u],2);
		up(1,1,n,1,n,-1);
	}
}
void slo(int x,int fa){
	for(auto u:v[x])if(u!=fa){
		dys[u]=dys[x]+1;
		slo(u,x);
	}
}
void solve(){
	cin>>n>>a>>b>>da>>db;
	FOR(i,1,n)v[i].clear();
	int x,y;
	rep(i,1,n){
		cin>>x>>y;
		v[x].PB(y);
		v[y].PB(x);
	}
	if(da*2>=db){
		cout<<"Alice\n";RE;
	}
	cnt=0;
	dis[a]=0;
	dfs(a,-1);
	if(dis[b]<=da){
		cout<<"Alice\n";RE ;
	}
	dys[b]=0;
	slo(b,-1);
//	FOR(i,1,n)cout<<dis[i]<<' '<<dys[i]<<'\n';
	build(1,1,n);
	to=0;
	get(a,-1);
	if(to){
		cout<<"Bob\n";
	}else cout<<"Alice\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}