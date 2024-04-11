#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
#define int long long
#define lb long double
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
int a[3][500005],sum[3][500005];
P<P<int,int>,int> p[500005];
int val[500005];
int num[500005][20],l2[500005];
int get(int l,int r){
	if(l<1||r>n)RE max(0ll,get(1,n));
	int t=l2[r-l+1];
	RE max(num[l][t],num[r-(1<<t)+1][t]);
}
int maxi[1<<20];
int m1[1<<20],m2[1<<20],m3[1<<20];
void build(int x,int l,int r){
	if(l==r){
		maxi[x]=sum[0][l]-sum[1][l]+a[1][l];
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	maxi[x]=max(maxi[lc],maxi[rc]);
}
void update(int x,int l,int r,int it,int vl){
	if(l==r){
		gmax(maxi[x],sum[0][l]-sum[1][l]+vl+a[1][l]);
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update(lc,l,mid,it,vl);
	else update(rc,mid+1,r,it,vl);
	maxi[x]=max(maxi[lc],maxi[rc]);
} 
int get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE maxi[x];
	}
	if(l>tr||tl>r)RE -1e18;
	int mid=(l+r)>>1;
	RE max(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
void build2(int x,int l,int r){
	if(l==r){
		m1[x]=sum[0][l]-sum[1][l]+a[1][l];
		m2[x]=val[l]+a[1][l];
		m3[x]=m1[x]+m2[x];
		RE ;
	}
	int mid=(l+r)>>1;
	build2(lc,l,mid);
	build2(rc,mid+1,r);
	m1[x]=max(m1[lc],m1[rc]);
	m2[x]=max(m2[lc],m2[rc]);
	m3[x]=max(m3[lc],m3[rc]);
	gmax(m3[x],m1[lc]+m2[rc]);
}
void update2(int x,int l,int r,int it,int vl){
	if(l==r){
		gmax(m1[x],sum[0][l]-sum[1][l]+vl+a[1][l]);
		m3[x]=m1[x]+m2[x];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update2(lc,l,mid,it,vl);
	else update2(rc,mid+1,r,it,vl);
	maxi[x]=max(maxi[lc],maxi[rc]);
	m1[x]=max(m1[lc],m1[rc]);
	m2[x]=max(m2[lc],m2[rc]);
	m3[x]=max(m3[lc],m3[rc]);
	gmax(m3[x],m1[lc]+m2[rc]);
}
P<P<int,int>,int> merge(P<P<int,int>,int> x,P<P<int,int>,int> y){
	P<P<int,int>,int> re=MP(MP(max(x.F.F,y.F.F),max(x.F.S,y.F.S)),max(x.S,y.S));
	gmax(re.S,x.F.F+y.F.S);
	RE re;
}
P<P<int,int>,int> get2(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		RE MP(MP(m1[x],m2[x]),m3[x]);
	}
	if(l>tr||tl>r)RE MP(MP(-1e18,-1e18),-1e18);
	int mid=(l+r)>>1;
	P<P<int,int>,int> plc=get2(lc,l,mid,tl,tr),prc=get2(rc,mid+1,r,tl,tr);
	RE merge(plc,prc);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	rep(i,0,3)FOR(j,1,n)cin>>a[i][j],sum[i][j]=a[i][j];
	rep(i,0,3)FOR(j,1,n)sum[i][j]+=sum[i][j-1];
	FOR(i,2,n)l2[i]=l2[i/2]+1;
	FOR(i,1,q){
		cin>>p[i].F.F>>p[i].F.S>>p[i].S;
	}
	sort(p+1,p+q+1);
	int ans=-1e18;
	FOR(i,1,n)val[i]=a[2][i]-a[1][i];
	for(int i=n;i>=1;i--)val[i]+=val[i+1],num[i][0]=val[i]+a[1][i];
	rep(i,1,20){
		FOR(j,1,n-(1<<i)+1)num[j][i]=max(num[j][i-1],num[j+(1<<(i-1))][i-1]);
	}
	build(1,1,n);
	build2(1,1,n);
	FOR(i,1,q){
		int now=get(1,1,n,p[i].F.F,p[i].F.S)-p[i].S+sum[1][p[i].F.S];
		if(p[i].F.S<n){
			update(1,1,n,p[i].F.S+1,now-sum[0][p[i].F.S+1]);
			update2(1,1,n,p[i].F.S+1,now-sum[0][p[i].F.S+1]);
		}
//		cout<<get(1,1,n,p[i].F.F,p[i].F.S)<<' '<<get2(1,1,n,p[i].F.F,p[i].F.S).F.F<<'\n';
		gmax(ans,get2(1,1,n,p[i].F.F,p[i].F.S).S
		+sum[1][n]-sum[1][p[i].F.S]-p[i].S+sum[1][p[i].F.S]);
//		gmax(ans,now+get(p[i].F.F,p[i].F.S)+sum[1][n]-sum[1][p[i].F.S]);
	}
	cout<<ans;
	RE 0;
}