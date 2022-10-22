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
class segtree{
	public:
	int N=524288,inf=1e9;
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
		up(p<<1,l1,r1,x);
		up((p<<1)|1,l1,r1,x);
		now[p]=max(now[p<<1],now[(p<<1)|1]);
	}
	int get(int p,int l1,int r1){
		if(l[p]>=l1&&r1>=r[p])RE now[p];
		if(l1>r[p]||l[p]>r1)RE -inf;
		push(p);
		RE max(get(p<<1,l1,r1),get((p<<1)|1,l1,r1));
	}
}tree;
int a[300005],b[300005],n; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	tree.build();
	cin>>n;
	int x;
	FOR(i,1,n)cin>>x,a[x]=i;
	FOR(i,1,n)cin>>b[i];
	cout<<n;
	tree.up(1,1,a[n],1);
	int ans=n;
	rep(i,1,n){
		tree.up(1,1,b[i],-1);
		while(tree.get(1,1,n)<=0)tree.up(1,1,a[--ans],1);
		cout<<' '<<ans;
	}
	RE 0;
}