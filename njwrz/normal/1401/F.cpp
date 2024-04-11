#pragma GCC optimize("Ofast")
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
using namespace std;
int a[300000];
int sum[600000],val[600000],lc[600000],rc[600000];
int n,q; 
void pd(int x,int l,int r,int d){
	if(l!=r){
		if(val[x]&(1<<d)){
			swap(lc[x],rc[x]);
		}
		val[lc[x]]^=val[x];
		val[rc[x]]^=val[x];
		val[x]=0;
	}
}
void build(int x,int l,int r){
	if(l==r){
		sum[x]=a[l];RE;
	}
	int mid=(l+r)>>1;lc[x]=x<<1;rc[x]=(x<<1)|1;
	build(x<<1,l,mid);
	build((x<<1)|1,mid+1,r);
	sum[x]=sum[lc[x]]+sum[rc[x]];
}
void ch(int x,int l,int r,int t,int v,int d){
	pd(x,l,r,d);
	if(l>t||r<t)RE;
	if(l==r){
		sum[x]=v;
		RE;
	}
	int mid=(l+r)>>1;
	ch(lc[x],l,mid,t,v,d-1);
	ch(rc[x],mid+1,r,t,v,d-1);
	sum[x]=sum[lc[x]]+sum[rc[x]];
}
int get(int x,int l,int r,int tl,int tr,int d){
	pd(x,l,r,d);
	if(l>tr||tl>r)RE 0;
	if(l>=tl&&r<=tr)RE sum[x];
	int mid=(l+r)>>1;
	RE get(lc[x],l,mid,tl,tr,d-1)+get(rc[x],mid+1,r,tl,tr,d-1);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	int m=n;
	n=1<<n;
	int x,y;
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	FOR(i,1,q){
		cin>>x;
		if(x==1){
			cin>>x>>y;
			ch(1,1,n,x,y,m);
		}else if(x==2){
			cin>>x;x++;
			val[1]^=(1<<x)-1;
		}else if(x==3){
			cin>>x;x++;
			val[1]^=(1<<x);
		}else{
			cin>>x>>y;
			cout<<get(1,1,n,x,y,m)<<'\n';
		}
	}
	RE 0;
}