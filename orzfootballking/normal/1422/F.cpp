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
using namespace std;
int lc[40000005],rc[40000005],mul[40000005],cnt;
int root[100005];
int a[100005],mod=1e9+7,n;
V<P<int,int> > v[200005];
void build(int &x,int l,int r){
	x=++cnt;
	if(l==r){
		mul[x]=a[l];RE;
	}
	int mid=(l+r)>>1;
	build(lc[x],l,mid);
	build(rc[x],mid+1,r);
	mul[x]=1ll*mul[lc[x]]*mul[rc[x]]%mod;
}
void update(int &x,int p,int l,int r,int it,int val){
	x=++cnt;
	if(l==r){
		mul[x]=mul[p]/val;RE;
	}
	int mid=(l+r)>>1;
	if(it<=mid)update(lc[x],lc[p],l,mid,it,val),rc[x]=rc[p];
	else update(rc[x],rc[p],mid+1,r,it,val),lc[x]=lc[p];
	mul[x]=1ll*mul[lc[x]]*mul[rc[x]]%mod;
}
int get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE mul[x];
	if(l>tr||tl>r)RE 1;
	int mid=(l+r)>>1;
	RE 1ll*get(lc[x],l,mid,tl,tr)*get(rc[x],mid+1,r,tl,tr)%mod;
}
void solve(int cnt,int i,int j){
	int t=cnt;
	while(!v[j].empty()&&v[j].back().S<=t){
		t/=v[j].back().S;
//		cout<<v[j].back().F<<' '<<v[j].back().S<<'\n';
		update(root[i],root[i],1,n,v[j].back().F,v[j].back().S);
		v[j].pop_back();
	}
	if(!v[j].empty()&&t!=1){
		update(root[i],root[i],1,n,v[j].back().F,t);
		v[j].back().S/=t;
	}
	v[j].PB(MP(i,cnt));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	build(root[0],1,n);
	FOR(i,1,n){
		root[i]=root[i-1];
		int num=a[i];
		for(int j=2;j*j<=a[i];j++){
			if(num%j==0){
				int cnt=1;
				while(num%j==0)num/=j,cnt*=j;
				solve(cnt,i,j);
			}
		}
		if(num!=1)solve(num,i,num);
	}
	int m;
	cin>>m;
	int x,y,lst=0;
	FOR(i,1,m){
		cin>>x>>y;
		x=(x+lst)%n+1;
		y=(y+lst)%n+1;
		if(x>y)swap(x,y);
		lst=get(root[y],1,n,x,y);
		cout<<lst<<'\n';
	}
	RE 0;
}