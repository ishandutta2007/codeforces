#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 200100;
int n,m,cnt,cntb;
vector<int> edge[V];
vector<int> belong[V];
int bel[V];
int instack[V];
int dfn[V];
int low[V];
stack<int> s;

void Tarjan(int u) {
	++cnt;
	dfn[u]=low[u]=cnt;
	s.push(u);
	instack[u]=1;
	for(int i=0;i<edge[u].size();++i) {
		int v=edge[u][i];
		if(!dfn[v]) {
			Tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(instack[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u]) {
		++cntb;
		int node;
		do {
			node=s.top();
			s.pop();
			instack[node]=0;
			bel[node] = cntb;
			belong[cntb].push_back(node);
		}while(node!=u);
	}
	//printf("U %d %d %d\n", u, dfn[u], low[u]);
}

LL gcd(LL x, LL y) {
    if (!x) return y;
    if (!y) return x;
    return gcd(y, x % y);
}

vector<PII> g[V];
LL d[V], r[V], gd[V];

void dfs2(int u) {
	instack[u]=1;
    dfn[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].fi;
        /*
        if (instack[v]) {
            gd[bel[u]] = gcd(gd[bel[u]], d[u] - d[v] + g[u][i].se);
        }*/
        if (!dfn[v]) {
            d[v] = d[u] + g[u][i].se;
            dfs2(v);
        }
        /*
        if (r[v] != -1) {
            r[u] = r[v] + g[u][i].se;
            gd[bel[u]] = gcd(gd[bel[u]], d[u] + r[v] + g[u][i].se);
        }*/
    }
	instack[u]=0;
}

void dfs3(int u) {
	instack[u]=1;
    dfn[u] = 1;
    for (int i = 0; i < g[u].size(); ++i) {
        int v = g[u][i].fi;
        /*
        if (instack[v]) {
            gd[bel[u]] = gcd(gd[bel[u]], d[u] - d[v] + g[u][i].se);
        }*/
        if (!dfn[v]) {
            r[v] = r[u] + g[u][i].se;
            dfs3(v);
        }
        /*
        if (r[v] != -1) {
            r[u] = r[v] + g[u][i].se;
            gd[bel[u]] = gcd(gd[bel[u]], d[u] + r[v] + g[u][i].se);
        }*/
    }
	instack[u]=0;
}


int u[V], v[V], w[V], Q, x, y, z;
int main() {
    while (~scanf("%d%d", &n, &m)) {
        for (int i = 1; i <= n; ++i) edge[i].clear(), belong[i].clear(), g[i].clear();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d",&u[i], &v[i], &w[i]);
            edge[u[i]].PB(v[i]);
        }
        cnt = cntb = 0;
        memset(instack, 0, sizeof(instack));
        memset(dfn, 0, sizeof(dfn));
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) Tarjan(i);
        }
        memset(instack, 0, sizeof(instack));
        for (int i = 0; i < m; ++i) {
            if (bel[u[i]] == bel[v[i]]) g[u[i]].PB({v[i], w[i]});
        }
        for (int i = 1; i <= cntb; ++i) gd[i] = 0;
        memset(r, -1, sizeof(r));
        memset(dfn, 0, sizeof(dfn));
        memset(instack, 0, sizeof(instack));
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {d[i] = r[i] = 0, dfs2(i);}
        }

        for (int i = 1; i <= n; ++i) g[i].clear();
        for (int i = 0; i < m; ++i) {
            if (bel[u[i]] == bel[v[i]]) g[v[i]].PB({u[i], w[i]});
        }
        memset(dfn, 0, sizeof(dfn));
        memset(instack, 0, sizeof(instack));
        for (int i = 1; i <= n; ++i) {
            if (!dfn[i]) {r[i] = 0, dfs3(i);}
        }

        for (int i = 1; i <= n; ++i) {
            gd[bel[i]] = gcd(gd[bel[i]], r[i] + d[i]);
        }
        for (int i = 0; i < m; ++i) {
            if (bel[u[i]] == bel[v[i]]) gd[bel[u[i]]] = gcd(gd[bel[u[i]]], d[u[i]] + r[v[i]] + w[i]);
        }
        //for (int i = 1; i <= n; ++i) printf("%d ", bel[i]); puts("");
        //for (int i = 1; i <= cntb; ++i) printf("%lld ", gd[i]); puts("");
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d%d%d", &x, &y, &z);
            if (y == 0 || (z - y) % gcd(z, gd[bel[x]]) == 0) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}

/*
4 4
1 2 1
2 3 1
3 1 2
1 4 3
4
1 1 3
1 2 4
4 0 1
4 1 2

4 5
1 2 1
2 3 1
3 1 2
1 4 1
4 3 2
2
1 2 4
4 3 5
*/