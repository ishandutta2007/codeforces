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
int n;
V<P<int,int> > v[2005]; 
int dp[2005][2005][2],a[2005],nxt[2005][2005][2],dis[2005],len[2];
int it[2005][2],sum[2005][2005][2],f[2005][2005][2];
void get(int st,int k){
	priority_queue<P<int,int> ,V<P<int,int> > ,greater<P<int,int> > > q;
	FOR(i,1,n)dis[i]=1e18;
	q.emplace(MP(0,st)); 
	dis[st]=0;
	int cnt=0;
	int lst=-1;
	while(!q.empty()){
		P<int,int> now=q.top();
		q.pop();
		if(dis[now.S]!=now.F)continue;
		if(now.F!=lst){
			cnt++;
			lst=now.F;
		}
		it[now.S][k]=cnt;
		for(auto u:v[now.S]){
			if(dis[u.F]>now.F+u.S){
				dis[u.F]=now.F+u.S;
				q.emplace(MP(dis[u.F],u.F));
			}
		}
	}
	len[k]=cnt;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m;
	cin>>n>>m;
	int s,t;
	cin>>s>>t;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m){
		int x,y,z;
		cin>>x>>y>>z;
		v[x].PB(MP(y,z));
		v[y].PB(MP(x,z));
	}
	get(s,0);
	get(t,1);
	FOR(i,0,n)FOR(j,0,n)nxt[i][j][0]=nxt[i][j][1]=n+1;
	FOR(i,1,n){
		assert(it[i][0]>0&&it[i][1]>0);
		gmin(nxt[it[i][0]-1][it[i][1]-1][0],it[i][0]);
		gmin(nxt[it[i][0]-1][it[i][1]-1][1],it[i][1]);
		sum[it[i][0]][it[i][1]-1][0]+=a[i];
		sum[it[i][0]-1][it[i][1]][1]+=a[i];
	}
	for(int i=n;i>=0;i--)for(int j=n;j>=0;j--)rep(k,0,2){
		if(i)gmin(nxt[i-1][j][k],nxt[i][j][k]);
		if(j)gmin(nxt[i][j-1][k],nxt[i][j][k]);
	}
	for(int i=n;i>=0;i--)for(int j=n;j>=0;j--){
		sum[i][j][0]+=sum[i][j+1][0]; 
		sum[i][j][1]+=sum[i+1][j][1];
	}
	FOR(i,0,n+1){
		FOR(j,0,n+1){
			if(i)sum[i][j][0]+=sum[i-1][j][0];
			if(j)sum[i][j][1]+=sum[i][j-1][1];
		}
	}
	FOR(i,0,n+1)FOR(j,0,n+1){
		dp[i][j][0]=f[i][j][0]=-1e18;
		dp[i][j][1]=f[i][j][1]=-1e18;
	}
	for(int i=n;i>=0;i--){
		for(int j=n;j>=0;j--){
			int to1=nxt[i][j][0],to2=nxt[i][j][1];
			if(to1==n+1||to2==n+1){
				dp[i][j][0]=dp[i][j][1]=f[i][j][0]=f[i][j][1]=0;continue;
			}
			dp[i][j][0]=f[to1][j][1]+sum[to1][j][0]-sum[i][j][0];
			gmax(dp[i][j][0],sum[n][j][0]-sum[i][j][0]);
			dp[i][j][1]=f[i][to2][0]+sum[i][to2][1]-sum[i][j][1];
			gmax(dp[i][j][1],sum[i][n][1]-sum[i][j][1]);
			f[i][j][1]=max(f[i+1][j][1]+sum[i+1][j][0]-sum[i][j][0],-dp[i][j][1]);
			f[i][j][0]=max(f[i][j+1][0]+sum[i][j+1][1]-sum[i][j][1],-dp[i][j][0]);
		}
	}
	if(dp[0][0][0]==0){
		cout<<"Flowers";
	}else if(dp[0][0][0]<0){
		cout<<"Cry";
	}else cout<<"Break a heart";
	RE 0;
}