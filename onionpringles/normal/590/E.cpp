#pragma warning(disable:4996)

#include <stdio.h>
#include <queue>
#include <stdlib.h>
#include <set>
#include <string.h>
#include <vector>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

const int ML = 10000001;
const int Mn = 5000;
const int inf_dist = 1000000000;
const int inf_flow = 1000000000;

int trans[ML][2];
int long_prefix[ML];
int exact_match[ML];
int suffix_match[ML];
int len[750];

int avk = 0;

char buf[ML];
char* sv[750];

inline int create_node() {
	trans[avk][0] = trans[avk][1] = long_prefix[avk] = exact_match[avk] = suffix_match[avk] = -1;
	avk++;
	return avk - 1;
}

inline int get_longer(int i, int j) {
	if (i == -1) return j;
	if (j == -1) return i;
	if (len[i] > len[j]) return i;
	else return j;
}
class Bad_Dinic {
	class Edge {
	public:
		int u, v, rev, f, c;
		Edge(int _u, int _v, int _rev, int _c) :u(_u), v(_v), rev(_rev), c(_c) { f = 0; }
	};
public:
	int s, t, vn;
	vector<Edge> adj[Mn];
	int dist[Mn];
	int vis[Mn];
	int it[Mn];
	void print() {
		for (int i = 0; i < vn; i++) {
			printf("%d: ", i);
			for (auto &x : adj[i]) printf("%d ", x.v);
			printf("\n");
		}
	}
	void init(int _s, int _t, int _vn) {
		for (int i = 0; i<_vn; i++) adj[i].clear();
		s = _s; t = _t; vn = _vn;
	}
	void addEdge(int u, int v, int c) {
		int usz = adj[u].size();
		int vsz = adj[v].size();

		adj[u].push_back(Edge(u, v, vsz, c));
		adj[v].push_back(Edge(v, u, usz, 0));
	}

	int bfs() {
		memset(vis, 0, vn*sizeof(*vis));
		for (int i = 0; i<vn; i++) dist[i] = inf_dist;
		queue<int> quu;
		quu.push(s);
		vis[s] = 1;
		dist[s] = 0;
		while (!quu.empty()) {
			int x = quu.front(); quu.pop();
			for (auto &e : adj[x]) {
				if (vis[e.v]) continue;
				if (e.f == e.c) continue;
				vis[e.v] = 1;
				dist[e.v] = dist[x] + 1;
				quu.push(e.v);
			}
		}
		return dist[t]<inf_dist;
	}
	int dfs(int u, int fl) {
		if (u == t) return fl;
		int cur_flow = 0;
		for (; it[u]<adj[u].size(); it[u]++) {
			int i = it[u];
			int v = adj[u][i].v;
			if (dist[v] != dist[u] + 1) continue;
			if (adj[u][i].f == adj[u][i].c) continue;
			int av_flow = dfs(v, min(fl - cur_flow, adj[u][i].c - adj[u][i].f));
			adj[u][i].f += av_flow;
			adj[v][adj[u][i].rev].f -= av_flow;
			cur_flow += av_flow;
			if (fl == cur_flow) break;
		}
		return cur_flow;
	}
	int maxflow() {
		int cur_flow = 0;
		while (bfs()) {
			memset(it, 0, vn*sizeof(*it));
			int f = dfs(s, inf_flow);
			if (!f)break;
			cur_flow += f;
		}
		return cur_flow;
	}
	void print_antichain() {
		int n = (vn - 2) / 2;
		for (int i = 0; i < n; i++) {
			if (dist[i] < inf_dist && dist[n + i] == inf_dist) {
				printf("%d ", i + 1);
			}
		}
	}
}dn;


int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt","w",stdout);
	int n;
	scanf("%d", &n);
	dn.init(2 * n, 2 * n + 1, 2 * n + 2);
	create_node(); //0: root
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		len[i] = strlen(buf);
		sv[i] = (char*)malloc(len[i] * sizeof(char));
		memcpy(sv[i], buf, len[i]);
		int cur = 0;
		for (int j = 0; j < len[i]; j++) {
			int c = buf[j] - 'a';
			if (trans[cur][c] == -1) {
				cur = trans[cur][c] = create_node();
			}
			else {
				cur = trans[cur][c];
			}
		}
		exact_match[cur] = i;
	}
	long_prefix[0] = 0;
	queue<pii> bfsq;
	for (int i = 0; i < 2; i++) {
		if (trans[0][i] != -1) bfsq.push(mp(0, i));
	}
	while (!bfsq.empty()) {
		pii x = bfsq.front(); bfsq.pop();
		int par = x.first; int ch = x.second; int nxt = trans[x.first][ch];
		int cur = long_prefix[par];
		while (cur != 0 && trans[cur][ch] == -1) {
			cur = long_prefix[cur];
		}
		if (par != 0 && trans[cur][ch] != -1) {
			long_prefix[nxt] = trans[cur][ch];
			cur = long_prefix[nxt];
			suffix_match[nxt] = get_longer(suffix_match[nxt], exact_match[cur]);
			suffix_match[nxt] = get_longer(suffix_match[nxt], suffix_match[cur]);
		}
		else {
			long_prefix[nxt] = 0;
		}
		for (int i = 0; i < 2; i++) {
			if (trans[nxt][i] != -1) bfsq.push(mp(nxt, i));
		}
	}
	for (int i = 0; i < n; i++) {
		int cur = 0;
		set<int> hehe;
		for (int j = 0; j < len[i]; j++) {
			int ch = sv[i][j] - 'a';
			cur = trans[cur][ch];
			if (j<len[i] - 1 && exact_match[cur] != -1) {
				hehe.insert(exact_match[cur]);
			}
			if (suffix_match[cur] != -1) {
				hehe.insert(suffix_match[cur]);
			}
		}
		for (auto &x : hehe) {
			dn.addEdge(x, n + i, 1);
		}
	}
	for (int i = 0; i < n; i++) {
		dn.addEdge(2 * n, i, 1);
		dn.addEdge(n + i, 2 * n + 1, 1);
	}
	//dn.print();
	printf("%d\n", n - dn.maxflow());
	dn.print_antichain();
}