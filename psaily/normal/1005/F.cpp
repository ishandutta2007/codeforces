#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

const int N=1e6+50;
const int mod=1e9+7;
const int M=2e6+50;

int n,m,k;
int head[N],nxt[N<<1],to[N<<1],id[N<<1],tot;

void add_edge(int u,int v,int iid) {
	nxt[++tot]=head[u]; head[u]=tot; to[tot]=v;	id[tot]=iid;
}

int que[N],l,r;
int dis[N],vis[N];
vector<pii> e[N];
vi vec[N];
int cnt;
string ans[N];

void bfs() {
	l=r=1; que[r++]=1; dis[1]=0; vis[1]=1;
	while (l<r) {
		int u=que[l++];
		vec[dis[u]].pb(u);
		for (int i=head[u];i;i=nxt[i]) {
			int v=to[i],iid=id[i];
			if (vis[v]) {
				if (dis[u]+1==dis[v]) e[v].pb(mp(u,iid));	
			}else {
				dis[v]=dis[u]+1;
				e[v].pb(mp(u,iid));
				que[r++]=v; vis[v]=1;
			}
		}
	}
	// rep(i,1,n+1) printf("dis[%d]=%d\n",i,dis[i]);
}

bool ok[N];

void dfs(int x) {
	int u=que[x];
	if (x==r) {
		++cnt;
		rep(i,1,m+1) {
			if (ok[i]) ans[cnt]+='1';
			else ans[cnt]+='0';
			// cout<<ans[cnt]<<' ';
		}
		// debug(m);
		// cout<<ans[cnt]<<endl;
		if (cnt==k) {
			printf("%d\n",cnt);
			rep(i,1,cnt+1) cout<<ans[i]<<endl;
			exit(0);
		}
	}
	rep(i,0,SZ(e[u])) {
		pii to=e[u][i];
		int iid=to.se;
		ok[iid]=1;
		dfs(x+1);
		ok[iid]=0;
	}
}

int main() {
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,m+1) {
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v,i);
		add_edge(v,u,i);
	}
	bfs();
	dfs(2);
	printf("%d\n",cnt);
	rep(i,1,cnt+1) cout<<ans[i]<<endl;
	return 0;	
}