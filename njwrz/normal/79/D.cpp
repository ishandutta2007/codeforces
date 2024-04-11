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
int to[25][25];
int it[25],n,k,l;
int a[105];
int pos[15];
V<int> v[10005];
int d[10005];
void solve(int x,int fr){
	FILL(d,-1);
	queue<int> q; 
	d[x]=0;
	q.emplace(x);
	while(!q.empty()){
		int cur=q.front();q.pop();
		for(auto u:v[cur])if(d[u]==-1){
			d[u]=d[cur]+1;
			q.emplace(u);
		}
	}
//	FOR(i,0,n){
//		cout<<d[i]<<' ';
//	}
//	cout<<'\n';
	FOR(i,1,k){
		if(d[pos[i]-1]!=-1){
			to[fr][i]=d[pos[i]-1];
		}else to[fr][i]=-1;
		if(d[pos[i]]!=-1){
			to[fr][i+k]=d[pos[i]];
		}else to[fr][i+k]=-1;
	}
}
int dp[25][1<<10];
int f[1<<10];
void solve2(int x,int fr){
	priority_queue<P<int,P<int,int> > ,V<P<int,P<int,int> > >,greater<P<int,P<int,int> > > > q;
	q.emplace(MP(0,MP(fr,0)));
	FILL(dp,-1);
	dp[fr][0]=0;
	while(!q.empty()){
		P<int,P<int,int> > tt=q.top();q.pop();
		P<int,int> cur=tt.S;
		int now=tt.F;
		if(now!=dp[cur.F][cur.S])continue;
		if(cur.F>k){
			int mask=cur.S^(1<<(cur.F-k-1));
			if(dp[cur.F-k][mask]==-1||dp[cur.F-k][mask]>now){
				dp[cur.F-k][mask]=now;
				q.emplace(MP(now,MP(cur.F-k,mask)));
			}
		}else{
			int mask=cur.S^(1<<(cur.F-1));
			if(dp[cur.F+k][mask]==-1||dp[cur.F+k][mask]>now){
				dp[cur.F+k][mask]=now;
				q.emplace(MP(now,MP(cur.F+k,mask)));
			}
		}
		FOR(i,1,2*k)if(to[cur.F][i]!=-1){
			if(dp[i][cur.S]==-1||dp[i][cur.S]>now+to[cur.F][i]){
				dp[i][cur.S]=now+to[cur.F][i];
				q.emplace(MP(dp[i][cur.S],MP(i,cur.S)));
			}
		}
	}
	rep(i,0,1<<k)if(dp[fr][i]!=-1){
		if(f[i]==-1||f[i]>dp[fr][i]){
			f[i]=dp[fr][i];
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k>>l;
	FOR(i,1,k)cin>>pos[i];
	FOR(i,1,l)cin>>a[i];
	FOR(i,0,n){
		FOR(j,1,l)if(i+a[j]<=n){
			v[i].PB(i+a[j]);
			v[i+a[j]].PB(i);
		}
	}
	FOR(i,1,k){
		solve(pos[i]-1,i);solve(pos[i],i+k);
	}
//	FOR(i,1,2*k){
//		FOR(j,1,2*k){
//			cout<<to[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	FILL(f,-1);
	FOR(i,1,k){
		solve2(pos[i-1],i);solve2(pos[i],i+k);
	}
	rep(i,0,1<<k){
		int mask=i;
		while(1){
			if(f[mask]!=-1&&f[mask^i]!=-1){
				if(f[i]==-1||f[i]>f[mask]+f[mask^i]){
					f[i]=f[mask]+f[mask^i];
				}
			}
			if(!mask)break;
			mask=(mask-1)&i;
		}
	}
	cout<<f[(1<<k)-1];
	RE 0;
}