#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
int sx[100005],sy[100005],ex[100005],ey[100005];
int n; 
struct node{
	int val[2][2];
};
int cost[100005][2][2];
int get(int x1,int y1,int x2,int y2){
	RE abs(x1-x2)+abs(y1-y2);
}
int inf=1e18;
node p[1<<18];
node INF={
inf,inf,
inf,inf
};
node merge(node x,node y){
	node re=INF;
	rep(i,0,2)rep(j,0,2)rep(k,0,2)gmin(re.val[i][j],x.val[i][k]+y.val[k][j]);
	RE re;
}
void build(int x,int l,int r){
	if(l==r){
		p[x]=(node){
			cost[l][0][0],cost[l][0][1],
			cost[l][1][0],cost[l][1][1]
		};
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	p[x]=merge(p[lc],p[rc]);
}
node emp={
0,inf,
inf,0
};
node get(int x,int l,int r,int tl,int tr){
	if(tl>tr)RE emp;
	if(l>=tl&&r<=tr){
//		cout<<"!"<<p[x].val[0][0]<<'\n';
		RE p[x];
	}
	if(l>tr||tl>r)RE emp;
	int mid=(l+r)>>1;
	RE merge(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>sx[i]>>sy[i]>>ex[i]>>ey[i];
	}
	rep(i,1,n-1){
		cost[i][0][1]=get(sx[i]+1,sy[i],ex[i+1],ey[i+1])+1;
		cost[i][0][0]=get(sx[i]+1,sy[i],sx[i+1],sy[i+1])+1;
		cost[i][1][0]=get(ex[i],ey[i]+1,sx[i+1],sy[i+1])+1;
		cost[i][1][1]=get(ex[i],ey[i]+1,ex[i+1],ey[i+1])+1;
	}
	if(n>2)build(1,1,n-2);
	int q;
	cin>>q;
	FOR(i,1,q){
		int dx,dy,px,py;
		cin>>dx>>dy>>px>>py;
		if(max(dx,dy)>max(px,py))swap(px,dx),swap(py,dy);
		int ind=max(dx,dy),inp=max(px,py);
		int dt[2],pt[2];
		if(inp==ind){
			cout<<get(dx,dy,px,py)<<'\n';continue;
		}
		dt[0]=get(sx[ind],sy[ind],dx,dy);
		dt[1]=get(ex[ind],ey[ind],dx,dy);
		pt[0]=get(sx[inp-1]+1,sy[inp-1],px,py);
		pt[1]=get(ex[inp-1],ey[inp-1]+1,px,py);
		int ans=inf;
		node now=get(1,1,n-2,ind,inp-2);
		rep(i1,0,2)rep(i2,0,2){
			gmin(ans,dt[i1]+pt[i2]+now.val[i1][i2]);
//			cout<<now.val[i1][i2]<<' ';
		}
		cout<<ans+1<<'\n';
	}
	RE 0;
}