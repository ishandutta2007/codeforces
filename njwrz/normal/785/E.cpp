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
const int maxn=2e7;
int val[maxn],rc[maxn],lc[maxn],cnt;
int root[200005],a[200005],n,ans;
void update(int &p,int l,int r,int x,int y){
	if(!p)p=++cnt;
	val[p]+=y;
	if(l==r)RE;
	int mid=(l+r)>>1;
	if(mid>=x)update(lc[p],l,mid,x,y);else update(rc[p],mid+1,r,x,y); 
}
int get(int &p,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE val[p];
	if(l>tr||tl>r)RE 0;
	int mid=(l+r)>>1;
	RE get(lc[p],l,mid,tl,tr)+get(rc[p],mid+1,r,tl,tr);
} 
int get(int l,int r,int tl,int tr){
	int re=0;
	while(l){
		re-=get(root[l],1,n,tl,tr);
		l-=l&-l;
	}
	while(r){
		re+=get(root[r],1,n,tl,tr);
		r-=r&-r;
	}
	RE re;
}
void update(int x,int p,int add){
	while(x<=n){
		update(root[x],1,n,p,add);
		x+=x&-x;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	FOR(i,1,n)update(i,i,1),a[i]=i;
	int x,y;
	FOR(i,1,m){
		cin>>x>>y;
		if(x>y)swap(x,y);
		if(x==y){
			cout<<ans<<'\n';continue;
		}
		ans+=get(x,y-1,1,a[y]-1)+get(x,y-1,a[x]+1,n);
		ans-=get(x,y-1,a[y]+1,n)+get(x,y-1,1,a[x]-1);
		ans+=a[x]<a[y] ? 1:-1;
		cout<<ans<<'\n';
		update(x,a[x],-1);
		update(y,a[y],-1);
		update(x,a[y],1);
		update(y,a[x],1);
		swap(a[x],a[y]);
	}
	RE 0;
}