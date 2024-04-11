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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
class segtree{
	public:
	int N=524288,inf=1e17;
	int add[1048576],now[1048576],l[1048576],r[1048576];
	void build(){
		rep(i,0,N)l[i+N]=r[i+N]=i+1;
		for(int i=N-1;i>=1;i--)l[i]=l[i<<1],r[i]=r[(i<<1)|1];
	}
	void push(int p){
		if(add[p]){
			add[p<<1]+=add[p];now[p<<1]+=add[p];
			add[(p<<1)|1]+=add[p];now[(p<<1)|1]+=add[p];
			add[p]=0;
		}
	}
	void up(int p,int l1,int r1,int x){
		if(l[p]>=l1&&r1>=r[p]){
			now[p]+=x;
			add[p]+=x;
			RE;
		}
		if(l1>r[p]||l[p]>r1)RE;
		push(p);
		up(p<<1,l1,r1,x);up((p<<1)|1,l1,r1,x);
		now[p]=max(now[p<<1],now[(p<<1)|1]);
	}
	int get(int p,int l1,int r1){
		if(l[p]>=l1&&r1>=r[p])RE now[p];
		if(l1>r[p]||l[p]>r1)RE -inf;
		push(p);
		RE max(get(p<<1,l1,r1),get((p<<1)|1,l1,r1));
	}
}tree;
P<int,int> p1[200005],p2[200005];
struct node{int x,y,z;};
node a[200005];
bool cmp(node s1,node s2){RE s1.y<s2.y;}
int de[200005],at[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	tree.build(); 
	int n,m,p;
	cin>>n>>m>>p;
	FOR(i,1,n)cin>>p1[i].F>>p1[i].S;
	FOR(i,1,m)cin>>p2[i].F>>p2[i].S;
	FOR(i,1,p)cin>>a[i].x>>a[i].y>>a[i].z,a[i].x++,a[i].y++,swap(a[i].x,a[i].y);
	sort(p2+1,p2+m+1);
	FOR(i,1,m)tree.up(1,i,i,-p2[i].S);
	FOR(i,1,m)de[i]=p2[i].F;
	sort(a+1,a+p+1,cmp);
	FOR(i,1,p)at[i]=a[i].y;
	sort(p1+1,p1+n+1);
	int last=0,t,ans=-1e17,t1;
	FOR(i,1,n){
		t=upper_bound(at+1,at+p+1,p1[i].F)-at-1;
		FOR(j,last+1,t){
			t1=lower_bound(de+1,de+m+1,a[j].x)-de;
			tree.up(1,t1,m,a[j].z);
		}
		gmax(ans,tree.get(1,1,m)-p1[i].S);
		last=t;
	}
	cout<<ans<<'\n';
	RE 0;
}