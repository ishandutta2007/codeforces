#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

#define X first
#define Y second
#define PB push_back

using namespace std;

const int N = 1e4 + 50;
const int INF = 0x3f3f3f3f;

typedef long long ll;

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

vector < int > smece[N];
int poos[N], poc[N], bio[N];
int n, m, a[N], s[N], e1[N], e2[N];

void euler(int x){
	for(;(int)smece[x].size() > 0;){
		if(bio[smece[x].back()]){
			smece[x].pop_back(); 
			continue;
		}
		int e = smece[x].back();
		smece[x].pop_back();
		bio[e] = 1; poc[e] = x;
		euler(e1[e] == x ? e2[e] : e1[e]);
	}
}

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
    	//printf("%d = %lld => %d\n", v, u, cap);
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};




ll sm = 0, pos, neg;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", s + i);
	for(int i = 1;i <= n;i++){
		scanf("%d", a + i);
		sm += a[i];
		if(a[i] < 0) neg -= a[i];
		else pos += a[i];
	}
	sm = -sm;
	Dinic F(n + 4, 0, n + 1);
	for(int i = 0;i < m;i++){
		scanf("%d%d", e1 + i, e2 + i);
		F.add_edge(e1[i], e2[i], 1);
		F.add_edge(e2[i], e1[i], 1);
	}
	for(int i = 1;i <= n;i++){
		if(s[i]){
			if(a[i] < 0)
				F.add_edge(0, i, -a[i]);
			if(a[i] > 0)
				F.add_edge(i, n + 1, a[i]);
		}
		else{
			if(sm < 0)
				F.add_edge(n + 2, i, INF);
			if(sm > 0)	
				F.add_edge(i, n + 3, INF);	
		}
	}
	if(sm < 0){
		F.add_edge(0, n + 2, -sm);
	}
	if(sm > 0){
		F.add_edge(n + 3, n + 1, sm);
	}
	ll fin = F.flow();
	if(fin != max(pos, neg)){
		printf("NO\n");
		return 0;
	}
	int dod = m;
	for(int i = 0;i < m;i++){
		if(F.edges[4 * i].flow - F.edges[4 * i + 1].flow - F.edges[4 * i + 2].flow + F.edges[4 * i + 3].flow == 0){
			smece[e1[i]].PB(i);
			smece[e2[i]].PB(i);
			poos[i] = 1;
		}
	}
	for(int i = 1;i <= n;i++){
		if((int)smece[i].size() % 2 == 1 && s[i]){
			printf("NO\n");
			return 0;
		}
		if((int)smece[i].size() % 2 == 1){
			e1[dod] = i; e2[dod] = n + 1;
			smece[i].PB(dod);
			smece[n + 1].PB(dod);
			dod++;
		}
	}
	for(int i = 1;i <= n;i++)
		euler(i);
	printf("YES\n");
	for(int i = 0;i < m;i++){
		if(poos[i]){
			if(poc[i] == e1[i])
				printf("%d %d\n", e1[i], e2[i]);
			else
				printf("%d %d\n", e2[i], e1[i]);
			continue;
		}
		if(F.edges[4 * i].flow - F.edges[4 * i + 1].flow - F.edges[4 * i + 2].flow + F.edges[4 * i + 3].flow > 0)
			printf("%d %d\n", e1[i], e2[i]);
		else
			printf("%d %d\n", e2[i], e1[i]);
	}
	return 0;
}