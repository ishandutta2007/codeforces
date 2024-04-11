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
#define rc ((x<<1)|1)
using namespace std;
int a[100005];
int maxi[1<<18],sum[1<<18];
void update(int x){
	maxi[x]=max(maxi[lc],maxi[rc]);
	sum[x]=sum[lc]+sum[rc];
}
void build(int x,int l,int r){
	if(l==r){
		maxi[x]=sum[x]=a[l];RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(x);
}
void update(int x,int l,int r,int it,int val){
	if(l==r){
		sum[x]=maxi[x]=val;RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update(lc,l,mid,it,val);
	else update(rc,mid+1,r,it,val);
	update(x);
}
void update(int x,int l,int r,int tl,int tr,int val){
	if(l>=tl&&r<=tr){
		if(l==r){
			sum[x]=maxi[x]=sum[x]%val;RE;
		}
		int mid=(l+r)>>1;
		if(maxi[lc]>=val)update(lc,l,mid,tl,tr,val);
		if(maxi[rc]>=val)update(rc,mid+1,r,tl,tr,val);
		update(x);
		RE;
	}
	if(l>tr||tl>r)RE;
	int mid=(l+r)>>1;
	update(lc,l,mid,tl,tr,val);
	update(rc,mid+1,r,tl,tr,val);
	update(x);
}
int get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE sum[x];
	if(tl>r||l>tr)RE 0;
	int mid=(l+r)>>1;
	RE get(lc,l,mid,tl,tr)+get(rc,mid+1,r,tl,tr);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,q;
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	build(1,1,n);
	FOR(i,1,q){
		int tap;
		cin>>tap;
		if(tap==1){
			int l,r;
			cin>>l>>r;
			cout<<get(1,1,n,l,r)<<'\n';
		}else if(tap==2){
			int l,r,x;
			cin>>l>>r>>x;
			update(1,1,n,l,r,x);
		}else{
			int k,x;
			cin>>k>>x;
			update(1,1,n,k,x);
		}
	}
	RE 0;
}