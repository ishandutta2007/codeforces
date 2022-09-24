#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>

using namespace std;

typedef long long LL;
const LL MOD = 1000000007 ;

typedef vector<vector<int> > Mat;

struct SCC {
    vector<int>scc;
    int cnt;
    SCC() {}
    SCC(const Mat&G, const Mat&R) {
	int n=G.size(); cnt=0;
	vector<int> v;
	scc=vector<int>(n);
	for (int i=0; i<n; i++) {
	    if (!scc[i]) dfs1(G, i, v);
	}
	scc=vector<int>(n, -1);
	for (int i=n-1; i>=0; i--) {
	    if (scc[v[i]]<0) dfs2(R, v[i], cnt++);
	}
    }
    void dfs1(const Mat&G, int p, vector<int>&v) {
	if (scc[p]) return;
	scc[p]=1;
	for (int i=0; i<int(G[p].size()); i++)
	    dfs1(G, G[p][i], v);
	v.push_back(p);
    }
    void dfs2(const Mat&R, int p, int cnt) {
	if (scc[p]>=0) return;
	scc[p]=cnt;
	for (int i=0; i<int(R[p].size()); i++)
	    dfs2(R, R[p][i], cnt);
    }
};

int N, M;
int cost[100010];
int cn[100010], mi[100010];
int main() {
    scanf("%d", &N);
    for (int i=0; i<N; i++) scanf("%d", cost+i);
    Mat G(N), R(N);
    scanf("%d", &M);
    for (int i=0; i<M; i++) {
	int u, v;
	scanf("%d%d", &u, &v);
	u--; v--;
	G[u].push_back(v);
	R[v].push_back(u);
    }

    SCC scc(G, R);

    for (int i=0; i<N; i++) mi[i] = MOD;
    for (int i=0; i<N; i++) mi[scc.scc[i]] = min(mi[scc.scc[i]], cost[i]);
    for (int i=0; i<N; i++) if (cost[i] == mi[scc.scc[i]]) cn[scc.scc[i]]++;
    LL sum = 0;
    LL ans = 1;
    for (int i=0; i<N; i++) {
	if (cn[i]) {
	    sum += mi[i];
	    ans = ans * cn[i] % MOD;
	}
    }

    printf("%lld %lld\n", sum, ans);
    return 0;
}