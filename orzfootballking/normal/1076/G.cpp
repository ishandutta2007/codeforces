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
#define rc ((x<<1)^1)
using namespace std;
int n,m,q,dp[1<<19][7][2],a[200005];
int rev[1<<19];
void up(int x){
	rep(i,0,2){
		FOR(j,1,m+1)dp[x][j][i]=dp[lc][dp[rc][j][i]][i];
	}
}
void build(int x,int l,int r){
	if(l==r){
		FOR(i,1,m)dp[x][i][0]=dp[x][i][1]=i+1;
		if(a[l]==1){
			dp[x][m+1][1]=1;
			dp[x][m+1][0]=m+1; 
		}else{
			dp[x][m+1][0]=1;
			dp[x][m+1][1]=m+1;
		}
		RE;
	}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	up(x);
}
void pushdown(int x){
	if(rev[x]){
		FOR(i,1,m+1){
			swap(dp[lc][i][0],dp[lc][i][1]);
			swap(dp[rc][i][0],dp[rc][i][1]);
		}
		rev[lc]^=1;
		rev[rc]^=1;
		rev[x]=0;
	}
}
void update(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		rev[x]^=1;
		FOR(i,1,m+1){
			swap(dp[x][i][0],dp[x][i][1]);
		}
		RE;
	}
	if(l>tr||tl>r)RE ;
	int mid=(l+r)>>1;
	pushdown(x);
	update(lc,l,mid,tl,tr);
	update(rc,mid+1,r,tl,tr);
	up(x);
}
V<int> merge(V<int> x,V<int> y){
	V<int> re;
	FOR(i,0,m+1)re.PB(x[y[i]]);
	RE re; 
}
V<int> get(int x,int l,int r,int tl,int tr){
	if(l>=tl&&r<=tr){
		V<int> re;
		FOR(i,0,m+1)re.PB(dp[x][i][0]);
		RE re;
	}
	if(l>tr||tl>r){
		V<int> re;
		FOR(i,0,m+1)re.PB(i);
		RE re;
	}
	int mid=(l+r)>>1;
	pushdown(x);
	RE merge(get(lc,l,mid,tl,tr),get(rc,mid+1,r,tl,tr));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	FOR(i,1,n)cin>>a[i],a[i]=(a[i]&1)^1;
	build(1,1,n);
	FOR(i,1,q){
		int tap,l,r,num;
		cin>>tap;
		if(tap==1){
			cin>>l>>r>>num;
			if(num&1){
				update(1,1,n,l,r);
			}
		}else{
			cin>>l>>r;
			V<int> t=get(1,1,n,l,r);
//			FOR(i,0,m+1)cout<<t[i]<<' ';
			if(t[m+1]==1){
				cout<<2;
			}else cout<<1;
			cout<<'\n';
		}
	}
	RE 0;
}