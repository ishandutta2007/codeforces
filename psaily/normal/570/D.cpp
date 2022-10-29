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

const int N=5e5+5;
int n,m;
int head[N],nxt[N<<1],to[N<<1],tot;
int ans[N];
char str[N];
vector<int> e[N];
int cnt[N];
map<int,int> mmap[N];
vector<pii> vec[N];

void add_edge(int u,int v) {
	nxt[++tot]=head[u]; head[u]=tot; to[tot]=v;	
}

int son[N],siz[N],dep[N];
void getson(int u) {
	siz[u]=1; son[u]=0;
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		dep[v]=dep[u]+1;
		getson(v);
		siz[u]+=siz[v];
		if (siz[v]>siz[son[u]]) son[u]=v;
	}
}
// void init() {
// 	for (int i=1;i<=n;i++) for (int j=1;j<=n;j+) scanf("%d",&a[i][j]);
// 		for (int =i1;i<=n;i++) for (int j=1;j<=n;j++) scnaf("%d",&b[i][j]);
	
		
// }
void add(int x) {
	// puts("in");
	// debug(x);
	// rep(i,1,4) printf("%d ",cnt[i]); puts("");
	if (mmap[dep[x]][str[x]]==0) mmap[dep[x]][str[x]]=1,cnt[dep[x]]++;
	else mmap[dep[x]][str[x]]=0,cnt[dep[x]]--;
	// rep(i,1,4) printf("%d ",cnt[i]); puts("");
	// puts("out");
}
void change(int u) {
	add(u);
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		change(v);
	}
}
void DSU(int u) {
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==son[u]) continue;
		DSU(v);
		change(v);
	}
	if (son[u]) DSU(son[u]);
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==son[u]) continue;
		change(v);
	}
	add(u);
	// debug(u);
	// rep(i,1,4) printf("%d ",cnt[i]); puts("");
	rep(i,0,SZ(vec[u])) {
		pii q=vec[u][i];
		ans[q.se]=(cnt[q.fi]>1)?0:1;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,2,n+1) {
		int x;
		scanf("%d",&x);
		add_edge(x,i);
	}
	scanf("%s",str+1);
	rep(i,1,m+1) {
		int v,k;
		scanf("%d%d",&v,&k);
		vec[v].pb(mp(k,i));
	}
	dep[1]=1;
	getson(1);
	DSU(1);
	// DSU(3);
	rep(i,1,m+1) {
		if (ans[i]) puts("Yes");
		else puts("No");
	}
	return 0;	
}