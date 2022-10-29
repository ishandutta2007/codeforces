#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl 
mt19937 mrand(time(0)); 

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=998244353,inf=1<<30;
// head
const db eps=1e-7;
const int N=1e5+5;
int n,m,q;
int good[N];

struct ftype {
	int fa[N];
	bool great[N];
	void init(int n) { rep(i,0,n+1) fa[i]=i; }
	int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);} 
	void unite(int x,int y) {
		x=find(x),y=find(y);
		if (x==y) return;
		fa[x]=y;	
	}
	bool same(int u,int v) {return find(u)==find(v);}
	void mark(int u) {
		u=find(u);
		great[u]=true;	
	}
	bool check(int u) {
		u=find(u);
		return great[u];
	}
}f[32];

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,31) f[i].init(n);
	rep(i,1,m+1) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (~w&1) good[u]=good[v]=1;
		rep(i,0,31) if (w>>i&1) f[i].unite(u,v);
	}
	rep(i,1,n+1) if (good[i]) {
		rep(j,0,31) f[j].mark(i);
	}
	scanf("%d",&q);
	while (q--) {
		int u,v,ans=2;
		scanf("%d%d",&u,&v);
		bool ok=0;
		rep(i,0,31) if (f[i].same(u,v)) { ok=1; break; }
		if (ok) ans=0;
		else {
			rep(i,1,31) if (f[i].check(u)) {
				ok=true;
				// debug(i);
				break;
			}
			ans=ok?1:2;
		}
		printf("%d\n",ans);
	}	
	
	return 0;	
}