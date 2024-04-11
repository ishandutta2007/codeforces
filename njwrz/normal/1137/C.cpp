#include<bits/stdc++.h>
#define ll long long
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
int dfn[100005],low[100005],in[100005],sta[100005];
int len,col[100005],cntcol;
V<int> v[100005];
V<int> to[100005];
V<P<int,int> > g[100005];
int a[100005][55],hav[100005][55];
int val[100005],dp[100005][55];
int dep[100005],rt[100005];
V<int> node[100005];
int n,m,d,cnt;
void dfs(int x){
	dfn[x]=low[x]=++cnt;in[x]=1;sta[++len]=x;
	for(auto u:v[x]){
		if(dfn[u]){
			if(in[u])gmin(low[x],dfn[u]);
		}else {
			dfs(u);
			gmin(low[x],low[u]);
		}
	}
	if(low[x]==dfn[x]){
		++cntcol;
		while(sta[len]!=x){
			col[sta[len]]=cntcol;
			in[sta[len]]=0;
			len--;
		}
		in[x]=0;col[x]=cntcol;len--;
	}
}
bool vis[100005];
void dfs(int fr,int x,int y){
	vis[x]=1;
	for(auto u:g[x])if(u.F!=y){
		if(vis[u.F]){
			int now=dep[x]-dep[u.F]+u.S;
			now=(now%d+d)%d;
			val[fr]=__gcd(val[fr],now);
		}else{
			dep[u.F]=(dep[x]+u.S+d)%d;
			dfs(fr,u.F,x);
		}
	}
}
V<P<int,int> > ed[100005];
signed main(){
//	freopen("wd.in","r",stdin);
//	freopen("wd.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>d;
	FOR(i,1,m){
		int x,y;
		cin>>x>>y;
		v[x].PB(y);
	}
	FOR(i,1,n){
		rep(j,0,d){
			char c;
			cin>>c;
			a[i][j]=c-'0';
		}
	}
	FOR(i,1,n)if(!dfn[i])dfs(i);
	FILL(in,0);
	FOR(x,1,n)for(auto u:v[x])if(col[x]==col[u]){
		g[x].PB(MP(u,1));
		g[u].PB(MP(x,d-1));
	}else{
		to[col[u]].PB(col[x]);
		in[col[x]]++;
		ed[col[x]].PB(MP(x,u));
	}
	FOR(i,1,n)node[col[i]].PB(i);
	FOR(i,1,cntcol){
		val[i]=d;
		rt[i]=node[i].back();
		dfs(i,rt[i],-1);
		for(auto u:node[i]){
			rep(j,0,val[i]){
				bool now=0;
				for(int k=j;k<d;k+=val[i]){
					if(a[u][k]){
						now=1;break;
					}
				}
				if(now)hav[i][(j-dep[u]+d)%val[i]]++;
			}
		}
	}
	queue<int> q;
	FOR(i,1,cntcol)if(!in[i]){
		q.emplace(i);
	}
	while(!q.empty()){
		int now=q.front();q.pop();
		for(auto u:to[now])if(--in[u]==0)q.emplace(u);
		rep(i,0,val[now])dp[now][i]=hav[now][i];
		rep(i,0,val[now]){
			int mx=0;
			for(auto u:ed[now]){
				int t=i+dep[u.F]-dep[u.S]+1;
				t=(t%d+d)%val[now];
				for(int j=t;j<d;j+=val[now]){
					gmax(mx,dp[col[u.S]][j%val[col[u.S]]]);
				}
			}
			dp[now][i]+=mx;
		}
	}
	int t=(d-dep[1])%val[col[1]];
	cout<<dp[col[1]][t];
	RE 0;
}