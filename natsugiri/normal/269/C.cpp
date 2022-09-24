#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;


typedef long long LL;
typedef LL Flow;
const LL INF=1LL<<55;
struct Edge {
    int src, dst;
    Flow cap;
    int rev;
    int id, dir;
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef pair<Flow, int> V;
void add_edge(Graph&G, int u, int v, Flow c, int id) {
    G[u].push_back((Edge){ u, v, c, int(G[v].size()), id, -1 });
    G[v].push_back((Edge){ v, u, c, int(G[u].size())-1, -1, -1 });
}

int N, M;
Flow out[200010];
bool use[200010];

int main() {
    scanf("%d%d", &N, &M);
    Graph G(N);
    for (int i=0; i<M; i++) {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	a--; b--;
	out[a]+=c; out[b]+=c;
	add_edge(G, a, b, c, i);
    }
    out[N-1]=INF;
    queue<int>qu; qu.push(0);
    vector<int>ans(M);
    for (;!qu.empty();) {
	int v=qu.front(); qu.pop();
	if (use[v]) continue;
	use[v]=1;
	for (int j=0; j<int(G[v].size()); j++) {
	    Edge &e=G[v][j];
	    if (e.dir!=-1) continue;
	    out[e.dst]-=e.cap*2;
	    e.dir=0;
	    G[e.dst][e.rev].dir=1;
	    if (e.id!=-1) ans[e.id]=0;
	    else ans[G[e.dst][e.rev].id]=1;
	    if (out[e.dst]==0) {
		qu.push(e.dst);
	    }
	}
    }

    for (int i=0; i<M; i++) printf("%d\n", ans[i]);

    return 0;
}