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
int mini[1100000],d[1100000],val[300005],n,a[300005],ans[300005],now;
V<P<int,int > > qus[300005];
void up(int x,int y){
	while(x<=n){
		val[x]+=y;
		x+=x&-x;
	}
} 
int get(int x){
	int sum=0;
	while(x){
		sum+=val[x];
		x-=x&-x;
	}
	RE sum;
}
set<int> s;
void pd(int x,int l,int r){
	if(l!=r){
		mini[lc]+=d[x];
		mini[rc]+=d[x];
		d[lc]+=d[x];
		d[rc]+=d[x];
	}
	d[x]=0;
}
void build(int x,int l,int r){
	if(l==r){
		if(a[l]<0)mini[x]=1e9;else mini[x]=a[l];
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	mini[x]=min(mini[lc],mini[rc]);
}
void update(int x,int l,int r,int tl,int tr,int p){
	pd(x,l,r);
	if(l>=tl&&r<=tr){
		mini[x]+=p;d[x]+=p;RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,p);
	update(rc,mid+1,r,tl,tr,p);
	mini[x]=min(mini[lc],mini[rc]);
}
void ch(int x,int l,int r){
	pd(x,l,r);
	if(mini[x]>=0)RE;
	if(l==r){
		mini[x]=1e9;RE;
	}
	int mid=(l+r)>>1;
	ch(lc,l,mid);
	ch(rc,mid+1,r);
	mini[x]=min(mini[lc],mini[rc]);
}
void find(int x,int l,int r){
	pd(x,l,r);
	if(mini[x]>0)RE;
	if(r<now)RE;
	if(l==r){
		up(l,1);s.emplace(l);
		RE;
	}
	int mid=(l+r)>>1;
	find(lc,l,mid);
	find(rc,mid+1,r);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i],a[i]=i-a[i];
	FOR(i,1,q){
		int x,y;
		cin>>x>>y;
		qus[x+1].PB(MP(n-y,i));
	}
	build(1,1,n);
	for(int i=n;i>=1;i--){
		now=i;
		if(!a[i]){
			s.clear();
			s.emplace(i);up(i,1);
			while(!s.empty()){
				int it=*s.begin();s.erase(s.begin());
				update(1,1,n,it,n,-1);
				ch(1,1,n);
				find(1,1,n);
			}
		}
		for(auto u:qus[i]){
			ans[u.S]=get(u.F);
		}
	}
	FOR(i,1,q)cout<<ans[i]<<'\n';
	RE 0;
}