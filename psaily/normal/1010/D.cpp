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
int op[N];
vi e[N];
char str[10];
int lf[N],val[N];
int lt[N],rt[N],dfn[N],tim;
int sum[N];
bool mark[N];

void del(int u) {
	int l=lt[u],r=rt[u];
	sum[r+1]++,sum[l]--;
}

void dfs(int u) {
	// debug(u);
	int v[2],nod[2],ct=0;
	lt[u]=++tim,dfn[tim]=u;
	rep(i,0,SZ(e[u])) {
		int to=e[u][i];
		dfs(to);	
		v[ct]=val[to],nod[ct]=to,ct++;
	}
	rt[u]=tim;
	// debug(op[u]);
	// puts("in");
	if (op[u]==1) ;
	else if (op[u]==2) {
		if (v[0]&&v[1]) val[u]=1;
		if (v[0]&&v[1]) ;
		else if (!v[0]&&!v[1]) del(nod[0]),del(nod[1]);
		else if (!v[0]&&v[1]) del(nod[1]);
		else if (v[0]&&!v[1]) del(nod[0]);
	}else if (op[u]==3) {
		val[u]=!v[0];
	}else if (op[u]==4) {
		val[u]=v[0]^v[1];
	}else if (op[u]==5) {
		if (v[0]||v[1]) val[u]=1;
		if (v[0]&&v[1]) del(nod[0]),del(nod[1]);
		else if (!v[0]&&!v[1]) ;
		else if (!v[0]&&v[1]) del(nod[0]);
		else if (v[0]&&!v[1]) del(nod[1]);
	}
	// puts("out");
	// bug(u),debug(val[u]);
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%s",str);
		int u,v;
		if (str[0]=='I') {
			op[i]=1,lf[i]=1;
			scanf("%d",&val[i]);
		}else if (str[0]=='A') {
			op[i]=2;
			scanf("%d%d",&u,&v);
			e[i].pb(v),e[i].pb(u);
		}else if (str[0]=='N') {
			op[i]=3;
			scanf("%d",&u);
			e[i].pb(u);
		}else if (str[0]=='X') {
			op[i]=4;
			scanf("%d%d",&u,&v);
			e[i].pb(v),e[i].pb(u);
		}else if (str[0]=='O') {
			op[i]=5;
			scanf("%d%d",&u,&v);
			e[i].pb(v),e[i].pb(u);
		}
	}
	dfs(1);
	rep(i,1,n+1) {
		sum[i]+=sum[i-1];
		if (sum[i]<0) mark[dfn[i]]=1;	
	}
	rep(i,1,n+1) if (lf[i]) {
		if (mark[i]) printf("%d",val[1]);
		else printf("%d",1-val[1]);
	}
	puts("");
	return 0;	
}