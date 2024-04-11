#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
 
const int N=1e6+5;
int n,m,mx;
int a[N],cnt[N];
int ans[N];
vector<pii> vec[N];

int head[N],nxt[N<<1],to[N<<1],tot;
void add_edge(int u,int v) {
	nxt[++tot]=head[u]; head[u]=tot; to[tot]=v;
}

struct bittree { 
	int sum[N],tot;
	int lowbit(int x) {return x&(-x);}
	void update(int x,int k) {
		int p=cnt[x];
		if (p) {
			while (p<=n) {
				sum[p]--;
				p+=lowbit(p);
			}
		}
		cnt[x]+=k;
		// debug(cnt[x]);
		p=cnt[x];
		if (p) {
			while (p<=n) {
				sum[p]++;
				p+=lowbit(p);
			}
		}
	}
	int query(int x) {
		if (x>=n) return 0;
		int res1=0;
		while (x) {
			res1+=sum[x];
			x-=lowbit(x);
		}
		int res2=0;
		x=n;
		while (x) {
			res2+=sum[x];
			x-=lowbit(x);
		}
		return res2-res1;
	}
}bit;

int siz[N],son[N];

void getson(int u,int f) {
	siz[u]=1; son[u]=0;
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==f) continue;
		getson(v,u);
		siz[u]+=siz[v];
		if (siz[v]>siz[son[u]]) son[u]=v;
	}
}
void add(int u,int f,int op) {
	bit.update(a[u],op);
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==f) continue;
		add(v,u,op);
	}
}
void DSU(int u,int f) {
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==f||v==son[u]) continue;
		DSU(v,u);
		add(v,u,-1);
	}
	if (son[u]) DSU(son[u],u);
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==f||v==son[u]) continue;
		add(v,u,1);
	}
	bit.update(a[u],1);
	// debug(u);
	// rep(i,1,mx+1) printf("%d ",cnt[i]);
	// puts("\n---");
	rep(i,0,SZ(vec[u])) {
		pii que=vec[u][i];
		// bug(que.fi),debug(que.se);
		ans[que.se]=bit.query(que.fi-1);
	}
}
 
int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",&a[i]),mx=max(mx,a[i]);
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	rep(i,1,m+1) {
		int v,k;
		scanf("%d%d",&v,&k);
		vec[v].pb(mp(k,i));
	}
	getson(1,0);
	DSU(1,0);
	rep(i,1,m+1) printf("%d\n",ans[i]);
	return 0;
}