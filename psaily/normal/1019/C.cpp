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

const int N=1e6+5;

int n,m;
vi e[N];
int dg[N],chos[N],vis[N];
int ans[N],at;

void dfs(int u) {
	chos[u]=1;
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		vis[v]=1;
	}
}
void gao(int u) {
	rep(i,0,SZ(e[u])) {
		int v=e[u][i];
		if (chos[v]) chos[v]=0;
	}
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		int u,v;
		scanf("%d%d",&u,&v);	
		e[u].pb(v);
	}
	rep(i,1,n+1) if (!vis[i]) dfs(i);
	per(i,n+1,1) if (chos[i]) gao(i);
	rep(i,1,n+1) if (chos[i]) ans[++at]=i;
	sort(ans+1,ans+1+at);
	printf("%d\n",at);
	rep(i,1,at+1) printf("%d ",ans[i]);
	return 0;
}