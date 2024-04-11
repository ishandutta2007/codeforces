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
	int N=32768,inf=1e9;
	int add[65536],now[65536],l[65536],r[65536];
	void build(){
		rep(i,0,N)l[i+N]=r[i+N]=i+1;
		for(int i=N-1;i>=1;i--)l[i]=l[i<<1],r[i]=r[(i<<1)|1];
	}
	void clear(){
		FILL(add,0);
		FILL(now,0);
	} 
	void push(int p){
		if(add[p]){
			add[p<<1]+=add[p];now[p<<1]+=add[p];
			add[(p<<1)|1]+=add[p];now[(p<<1)|1]+=add[p];
			add[p]=0;
		}
	}
	void up(int p,int l1,int r1,int x){
		if(l1>r1)RE;
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
int dp[55][20005],s[55][20005],a[55][20005],n,m,k,t;
void repe(int x,int y){
	if(y)tree.up(1,max(1,y-k+1),min(t,y),-a[x][y]);
}
void del(int x,int y){
	if(y)tree.up(1,max(1,y-k+1),min(t,y),a[x][y]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	t=m-k+1;
	FOR(i,1,n)FOR(j,1,m)cin>>a[i][j],s[i][j]=s[i][j-1]+a[i][j];
	tree.build();
	FOR(i,1,n){
		if(i>1)rep(j,1,k)repe(i,j);
		FOR(j,1,t){
			if(i>1){
				repe(i,j+k-1);del(i,j-1);
				dp[i][j]=s[i][j+k-1]-s[i][j-1]+tree.get(1,1,t);
			}else dp[i][j]=s[i][j+k-1]-s[i][j-1];
		}
		tree.clear();
		FOR(j,1,t)tree.up(1,j,j,dp[i][j]+s[i+1][j+k-1]-s[i+1][j-1]);
	}
	int ans=0;
	FOR(i,1,t)gmax(ans,dp[n][i]);
	cout<<ans;
	RE 0;
}