#pragma GCC optimize("Ofast")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC target("fma","avx2")
#pragma GCC target("xop","fma4")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
using namespace std;
struct dsu{
	int fa[10000005];
	void init(){
		FOR(i,1,10000000)fa[i]=i;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);
		y=get(y);
		fa[x]=y;
	}
}D;
int lc[10000005],rc[10000005];
ll l[50005],r[50005];
int tap[50005],n,q;
P<ll,ll> p[50005];
int root,cnt,ans[50005];
ll siz[10000005];
bool f[10000005];
int a[2][100],len[2];
void dfs(int x,ll l,ll r,ll iter,int pit){
	if(!x)RE ;
	a[pit][++len[pit]]=x;
	if(l==r)RE;
	ll mid=(l+r)>>1;
	if(iter<=mid)dfs(lc[x],l,mid,iter,pit);
	else dfs(rc[x],mid+1,r,iter,pit);
}
void dfs2(int x,ll l,ll r,ll tl,ll tr,int num){
	if(!x||!siz[x])RE ;
	if(l>tr||tl>r)RE ;
	if(siz[x]==r-l+1){
		D.merge(x,num);
		RE;
	}
	if(l==tl&&r==tr){
		f[x]=1;
		D.merge(x,num);
	}
	ll mid=(l+r)>>1;
	dfs2(lc[x],l,mid,tl,tr,num);
	dfs2(rc[x],mid+1,r,tl,tr,num);
}
V<P<P<ll,ll>,int> > nowv;
void update(int &x,ll l,ll r,ll tl,ll tr){
	if(!x)x=++cnt;
	if(l>=tl&&r<=tr){
		siz[x]=r-l+1;
		f[x]=1;
		nowv.PB(MP(MP(l,r),x));
		RE ;
	}
	if(l>tr||tl>r)RE ;
	ll mid=(l+r)>>1;
	update(lc[x],l,mid,tl,tr);
	update(rc[x],mid+1,r,tl,tr);
	siz[x]=siz[lc[x]]+siz[rc[x]];
	f[x]|=r-l+1==siz[x];
	if(f[x]){
		if(lc[x])D.merge(lc[x],x);
		if(rc[x])D.merge(rc[x],x);
	}
}
//bool check(int x,ll l,ll r,ll tl,ll tr){
//	if(siz[x]==r-l+1)RE 1;
//	if(!x)RE 0;
//	if(l==tl&&r==tr)RE siz[x]>0;
//	ll mid=(l+r)>>1;
//	if(mid>=tr){
//		RE check(lc[x],l,mid,tl,tr);
//	}else RE check(rc[x],mid+1,r,tl,tr);
//}
void update(ll l,ll r){
	if(l<=r)update(root,0,(1ll<<n)-1,l,r);
	for(auto u:nowv){
		ll l=u.F.F,r=u.F.S;
		for(int i=n-1;i>=0;i--)if((1ll<<i)>=r-l+1){
			dfs2(root,0,(1ll<<n)-1,l^(1ll<<i),r^(1ll<<i),u.S);
		}
	}
	nowv.clear();
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	D.init();
	cin>>n>>q;
	int cnt=0;
	FOR(i,1,q){
		string s;
		cin>>s;
		if(s[0]=='b')tap[i]=1;
		cin>>l[i]>>r[i];
		if(tap[i])p[++cnt]=MP(l[i],r[i]);
	}
	while(tap[q])q--,cnt--;
	sort(p+1,p+cnt+1);
	p[0].S=-1;
	p[cnt+1].F=(1ll<<n);
	FOR(i,0,cnt){
		update(p[i].S+1,p[i+1].F-1);
	}
	for(int i=q;i>=1;i--){
		if(tap[i])update(l[i],r[i]);
		else{
			V<int> v1,v2;
			len[0]=len[1]=0;
			dfs(root,0,(1ll<<n)-1,l[i],0);
			dfs(root,0,(1ll<<n)-1,r[i],1);
			FOR(u1,1,len[0]){
				FOR(u2,1,len[1]){
					if(a[0][u1]!=a[1][u2]){
						if(D.get(a[0][u1])==D.get(a[1][u2])){
							ans[i]=1;break;
						}
					}else{
						if(f[a[0][u1]]){
							ans[i]=1;break;
						}
					}
				}
				if(ans[i])break;
			} 
		}
	} 
	FOR(i,1,q)if(!tap[i])cout<<ans[i]<<'\n';
	RE 0;
}