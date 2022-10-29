#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
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
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
// head

const int N=1e6+50;

int n,k,deg[N],ans;
int head[N],nxt[N<<1],to[N<<1],tot;

void add_edge(int u,int v) {
	nxt[++tot]=head[u],head[u]=tot,to[tot]=v;
}

int mix[N],lg[N],m;

void dfs(int u,int f) {
	// bug(u),debug(f);
	vi vec;
	for (int i=head[u];i;i=nxt[i]) {
		int v=to[i];
		if (v==f) continue;
		dfs(v,u);
		vec.pb(mix[v]+1);
	}
	sort(all(vec));
	mix[u]=0;
	if (deg[u]==1) ans++;
	if (SZ(vec)>=2) {
		int pos=1;
		m=SZ(vec);
		rep(i,1,m+1) lg[i]=vec[i-1];
		// debug(u);
		// rep(i,1,m+1) printf("%d ",lg[i]);
		per(i,m+1,1) {
			if (lg[i]+lg[i-1]>k) ;
			else {pos=i; break;}
		}
		ans-=(pos-1);
		mix[u]=lg[pos];
	}else if (SZ(vec)==1) mix[u]=vec[0];
}

int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n) {
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
		deg[u]++,deg[v]++;
	}
	rep(i,1,n+1) if (deg[i]>1) {dfs(i,0); break;}
	printf("%d\n",ans);
	return 0;
}