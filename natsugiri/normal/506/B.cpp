
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

typedef vector<vector<int> > Adj;

Adj G, R;
VI vs, rvs;
vector<int>scc;
int cnt;

void dfs1(int p, vector<int>&v) {
    if (scc[p]) return;
    scc[p] = 1;
    for (int i=0; i<int(G[vs[p]].size()); i++)
	dfs1(rvs[G[vs[p]][i]], v);
    v.push_back(p);
}
void dfs2(int p, int cnt) {
    if (scc[p] >= 0) return;
    scc[p] = cnt;
    for (int i=0; i<int(R[vs[p]].size()); i++)
	dfs2(rvs[R[vs[p]][i]], cnt);
}
void SCC() {
    int n = vs.size();
    cnt = 0;
    vector<int> v;
    scc.assign(n, 0);
    for (int i=0; i<n; i++) {
	if (!scc[i]) dfs1(i, v);
    }
    scc.assign(n, -1);
    for (int i=n-1; i>=0; i--) {
	if (scc[v[i]]<0) dfs2(v[i], cnt++);
    }
}

Adj B;;
int N, M;
bool use[100011];

void dfs(int v, int p) {
    if (use[v]) return;
    use[v] = true;
    rvs[v] = vs.size();
    vs.push_back(v);
    EACH (e, B[v]) {
	if (*e == p) continue;
	dfs(*e, v);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    rvs.assign(N, 0);
    G = R = Adj(N);
    B = Adj(N);
    REP (i, M) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--;b--;
	G[a].push_back(b);
	R[b].push_back(a);
	
	B[a].push_back(b);
	B[b].push_back(a);
    }

    int ans = 0;
    REP (i, N) {
	if (use[i]) continue;
	vs.clear();
	dfs(i, -1);
	if (vs.size() == 0u) continue;
	
	SCC();
	if (cnt == (int)vs.size()) ans += vs.size()-1; // DAG
	else ans += vs.size();
    }
    
    printf("%d\n", ans);

    return 0;
}