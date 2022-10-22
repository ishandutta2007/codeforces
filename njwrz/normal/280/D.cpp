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
int n,a[100005];
struct node{
	int val[2][2][22];
};
node p[1<<18];
node emp;
node merge(node x,node y){
	node re=emp;
	FOR(i,0,20)FOR(j,0,min(21-i,20)){
		rep(i1,0,2)if(i||!i1)rep(j1,0,2)if(j||!j1){
			gmax(re.val[i1][j1][i+j],x.val[i1][0][i]+y.val[0][j1][j]);
			if(i&&j)gmax(re.val[i1][j1][i+j-1],x.val[i1][1][i]+y.val[1][j1][j]);
		}
	}
	RE re;
}
void build(int x,int l,int r){
	if(l==r){
		p[x]=emp;
		rep(i,0,2)rep(j,0,2)FOR(k,1,20)p[x].val[i][j][k]=a[l];
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	p[x]=merge(p[lc],p[rc]);
}
void update(int x,int l,int r,int it){
	if(l==r){
		p[x]=emp;
		rep(i,0,2)rep(j,0,2)FOR(k,1,20)p[x].val[i][j][k]=a[l];
		RE;
	}
	int mid=(l+r)>>1;
	if(mid>=it)update(lc,l,mid,it);
	else update(rc,mid+1,r,it);
	p[x]=merge(p[lc],p[rc]);
}
node get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr)RE p[x];
	int mid=(l+r)>>1;
	if(mid>=tr)RE get(lc,l,mid,tl,tr);
	else if(mid+1<=tl)RE get(rc,mid+1,r,tl,tr);
	else RE merge(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(k,1,20)emp.val[1][0][k]=emp.val[0][1][k]=emp.val[1][1][k]=-1e9;
	build(1,1,n);
	int q;
	cin>>q;
	FOR(_,1,q){
		int tap;
		cin>>tap;
		if(tap==0){
			int x,y;
			cin>>x>>y;a[x]=y;
			update(1,1,n,x);
		}else{
			int l,r,k;
			cin>>l>>r>>k;
			node now=get(1,1,n,l,r);
			int ans=0;
			rep(i,0,2)rep(j,0,2)FOR(p,0,k)gmax(ans,now.val[i][j][p]);
			cout<<ans<<'\n';
		}
	}
	RE 0;
}