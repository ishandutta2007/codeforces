#include<bits/stdc++.h>
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
const int mod=998244353;
struct DSU{
	int fa[2005];
	void init(int n){
		FOR(i,1,n)fa[i]=i;
	}
	int get(int x){
		RE (fa[x]==x)?x:(fa[x]=get(fa[x]));
	}
	void merge(int x,int y){
		x=get(x);y=get(y);
		fa[x]=y;
	}
}T;
int dp[2005][2005],n,a[2005][2005],f[2005];
void add(int &x,int y){
	x+=y;
	if(x>=mod)x-=mod;
}
int POW(int x,int y){
	int re=1;
	while(y){
		if(y&1)re=re*x%mod;
		x=x*x%mod;
		y/=2;
	}
	RE re;
}
struct bit{
	int s[2005];
	void init(int n){
		FOR(i,1,n)s[i]=0;
	}
	void update(int x,int y){
		while(x<=n){
			s[x]+=y;
			x+=x&-x;
		}
	}
	int get(int x){
		int re=0;
		while(x){
			re+=s[x];
			x-=x&-x;
		}
		RE re;
	}
}B,B2;
int pw[2005],vis[2005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	f[0]=1;
	FOR(i,1,n)f[i]=f[i-1]*i%mod;
	FOR(i,1,n){
		FOR(j,1,n){
			cin>>a[i][j];
		}
	}
	int ans=0;
	dp[0][0]=1;
	FOR(s,0,n)FOR(i,0,s){
		int j=s-i;
		if(j){
			if(i)add(dp[i][j],dp[i-1][j]*i%mod);
			if(j)add(dp[i][j],dp[i][j-1]*j%mod);
		}else{
			if(i>1)add(dp[i][j],dp[i-2][j+1]*(i-1)%mod);
		}
	}
	pw[0]=1;
	pw[1]=dp[n][0];
	FOR(i,2,n)pw[i]=pw[i-1]*pw[1]%mod;
	FOR(i,1,n){
		B.update(a[1][i],1);
		int now=a[1][i]-B.get(a[1][i]);
		add(ans,now*pw[n-1]%mod*f[n-i]%mod);
	}
	FOR(i,2,n){
		T.init(n);FILL(vis,0);
		int sum=0;B.init(n);B2.init(n);
		FOR(j,1,n)B2.update(j,1);
		int t1=n,t2=0;
		FOR(j,1,n){
			t2=(n-j+1)-t1;
			int tail=T.get(a[i-1][j]);
			B.update(a[i][j],1);
			int now=a[i][j]-B.get(a[i][j]);
			int now1=B2.get(a[i][j]-1),now2=now-now1;
			if(tail<a[i][j]&&tail!=a[i-1][j]){
				now2--;
				add(sum,dp[t1][t2-1]);
			}else if(tail<a[i][j])now1--;
			int to1=t1;
			to1-=!vis[a[i-1][j]];
			if(now2)add(sum,now2*dp[to1][n-j-to1]%mod);
			to1--;
			if(now1)add(sum,now1*dp[to1][n-j-to1]%mod);
			if(!vis[a[i-1][j]]){
				t1--;B2.update(a[i-1][j],-1);
			}
			if(!vis[a[i][j]]){
				t1--;B2.update(a[i][j],-1);
			}
			vis[a[i-1][j]]=vis[a[i][j]]=1;
			T.merge(a[i][j],a[i-1][j]);
		}
		add(ans,sum*pw[n-i]%mod);
	}
	cout<<ans;
	RE 0;
}