#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
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
using namespace std;
int n,m;
ll a[105],b[100005];
ll mini[1<<18],sum[1<<18],sum2[1<<18],tag[1<<18],num[100005];
void update(int x,int len){
	sum[x]=sum[lc]+sum[rc];
	sum2[x]=sum2[rc]+sum2[lc]+sum[lc]*len;
	mini[x]=min(mini[lc],mini[rc]);
}
void pushdown(int x,int l,int r){
	int mid=(l+r)>>1;
	sum2[lc]+=tag[x]*num[mid-l+1];
	sum2[rc]+=tag[x]*num[r-mid];
	sum[lc]+=(mid-l+1)*tag[x];
	sum[rc]+=(r-mid)*tag[x];
	mini[lc]+=tag[x];
	mini[rc]+=tag[x];
	tag[lc]+=tag[x];
	tag[rc]+=tag[x];
	tag[x]=0;
}
void build(int x,int l,int r){
	if(l==r){
		sum[x]=sum2[x]=mini[x]=b[l];
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x,r-mid); 
}
void update(int x,int l,int r,int tl,int tr,ll add){
	if(l>tr||tl>r)RE ;
	if(l>=tl&&r<=tr){
		tag[x]+=add;
		sum2[x]+=add*num[r-l+1];
		sum[x]+=(r-l+1)*add;
		mini[x]+=add;
		RE;
	}
	int mid=(l+r)>>1;
	if(tag[x])pushdown(x,l,r);
	update(lc,l,mid,tl,tr,add);
	update(rc,mid+1,r,tl,tr,add);
	update(x,r-mid);
}
int get(int x,int l,int r,ll num){
	if(l==r)RE l;
	int mid=(l+r)>>1;
	if(tag[x])pushdown(x,l,r);
	if(mini[rc]<=num){
		RE get(rc,mid+1,r,num);
	}else RE get(lc,l,mid,num);
}
P<ll,ll> add(P<ll,ll> x,P<ll,ll> y){
	RE MP(x.F+y.F,x.S+y.S);
}
P<ll,ll> getsum(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE MP(sum2[x]+sum[x]*(tr-r),sum[x]);
	}
	if(l>tr||tl>r)RE MP(0,0);
	int mid=(l+r)>>1;
	if(tag[x])pushdown(x,l,r);
	RE add(getsum(lc,l,mid,tl,tr),getsum(rc,mid+1,r,tl,tr));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>n>>m>>q;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m)cin>>b[i];
	for(int i=n;i>=2;i--)a[i]-=a[i-1];
	for(int i=m;i>=2;i--)b[i]-=b[i-1];
	FOR(i,1,100000)num[i]=1ll*i*(i+1)/2;
	build(1,1,m);
	ll st=a[1]+b[1];
	FOR(_,1,q){
		int tap,x,y;
		cin>>tap>>x>>y;
		if(tap==1){
			if(x==n)st+=y;
			FOR(i,n-x+1,n){
				a[i]+=y;
			}
		}else{
			if(x==m)st+=y;
			update(1,1,m,m-x+1,m,y);
		}
		int nowy=1;
		ll ans=st*(n+m-1);
		rep(nowx,1,n){
			ll val=a[nowx+1];
			int it=get(1,1,m,val);
			if(it>nowy){
				P<ll,ll> now=getsum(1,1,m,nowy+1,it);
				ans=ans+now.F+now.S*(m-it+n-nowx);
			}
			ans=ans+val*(m-it+n-nowx);
			nowy=it;
		}
		int it=m;
		if(it>nowy){
			P<ll,ll> now=getsum(1,1,m,nowy+1,it);
			ans=ans+now.F;
		}
		cout<<ans<<'\n';
	}
	RE 0;
}