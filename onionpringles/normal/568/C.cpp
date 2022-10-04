#pragma warning(disable:4996)
#include <stdio.h>
#include <vector>
#include <string.h>
#include <set>

using namespace std;

const int MN = 200;

class TwoSAT {
public:
	int n;
	vector<int> adj[2 * MN];
	vector<int> rev_adj[2 * MN];
	int scc[2 * MN];
	int clk_order[2 * MN];
	int vis[2 * MN];
	int clock = 0;
	int sccnum;

#define ban(a) ((a)<n)?((a)+n):((a)-n)
	void init(int _n) { n = _n; }
	void addImplies(int a, int b) {
		int ba = ban(a);
		int bb = ban(b);
		adj[a].push_back(b);
		rev_adj[b].push_back(a);

		adj[bb].push_back(ba);
		rev_adj[ba].push_back(bb);
	}
	void dfs(int i) {
		vis[i] = 1;
		for (auto &x : rev_adj[i]) {
			if (vis[x]) continue;
			dfs(x);
		}
		clk_order[clock++] = i;
		return;
	}
	void dfs2(int i) {
		vis[i] = 1;
		scc[i] = sccnum;
		for (auto &x : adj[i]) {
			if (vis[x]) continue;
			dfs2(x);
		}
	}
	int check() {
		memset(vis, 0, sizeof(vis));
		clock = 0;
		for (int i = 0; i < 2 * n; i++) {
			if (vis[i]) continue;
			dfs(i);
		}
		memset(vis, 0, sizeof(vis));
		sccnum = 0;
		for (int i = 2 * n - 1; i >= 0; i--) {
			if (vis[clk_order[i]]) continue;
			sccnum++;
			dfs2(clk_order[i]);
		}
		for (int i = 0; i < n; i++) {
			if (scc[i] == scc[n + i]) return 0;
		}
		return 1;
	}
} ts;

int curword[MN];
int first_c = -1;
int first_v = -1;
vector<int> hist;
int n;

void pophist() {
	int x = hist.back();
	hist.pop_back();
	ts.adj[x].pop_back();
	ts.adj[x].pop_back();
	ts.rev_adj[ban(x)].pop_back();
	ts.rev_adj[ban(x)].pop_back();
}

char buf1[27];
char buf2[MN + 1];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%s", buf1);
	int l = strlen(buf1);
	for (int i = 0; i < l; i++) {
		if (buf1[i] == 'V') {
			if (first_v == -1) first_v = i;
		}
		else {
			if (first_c == -1) first_c = i;
		}
	}
	if (first_v == -1) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int p1, p2; char t1, t2;
			scanf("%d %c %d %c", &p1, &t1, &p2, &t2);
			if (t1 == 'C' && t2 == 'V') {
				puts("-1"); return 0;
			}
		}
		scanf("%s", buf2);
		printf("%s", buf2);
		return 0;
	}
	else if (first_c == -1) {
		int n, m; scanf("%d %d", &n, &m);
		for (int i = 0; i < m; i++) {
			int p1, p2; char t1, t2;
			scanf("%d %c %d %c", &p1, &t1, &p2, &t2);
			if (t1 == 'V' && t2 == 'C') {
				puts("-1"); return 0;
			}
		}
		scanf("%s", buf2);
		printf("%s", buf2);
		return 0;
	}
	int m;
	scanf("%d %d", &n, &m);
	ts.init(n);
	for (int i = 0; i < m; i++) {
		int p1, p2; char t1, t2;
		scanf("%d %c %d %c", &p1, &t1, &p2, &t2);
		p1--; p2--;
		if (t1 == 'C') p1 += n;
		if (t2 == 'C') p2 += n;
		ts.addImplies(p1, p2);
	}
	scanf("%s", buf2);
	if (!ts.check()) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		curword[i] = buf2[i] - 'a';
	}
	int i;
	for (i = 0; i < n; i++) {
		if (buf1[curword[i]] == 'V') {
			hist.push_back(n + i);
			ts.addImplies(n + i, i);
		}
		else {
			hist.push_back(i);
			ts.addImplies(i, n + i); 
		}
		if (!ts.check()) break;
	}
	if (i == n) {
		printf("%s", buf2);
		return 0;
	}
	int double_break = 0;
	for (; i >= 0; i--) {
		pophist();
		int x = curword[i] + 1;
		for (; x < l; x++) {
			curword[i] = x;
			if (buf1[x] == 'C') {
				ts.addImplies(i, n + i);
				if (ts.check()) {
					i++;
					double_break = 1;
					break;
				}
				else {
					ts.adj[i].pop_back();
					ts.adj[i].pop_back();
					ts.rev_adj[n + i].pop_back();
					ts.rev_adj[n + i].pop_back();
				}
			}
			else {
				ts.addImplies(n + i, i);
				if (ts.check()) {
					i++;
					double_break = 1;
					break;
				}
				else {
					ts.adj[n + i].pop_back();
					ts.adj[n + i].pop_back();
					ts.rev_adj[i].pop_back();
					ts.rev_adj[i].pop_back();
				}
			}
		}
		if (double_break) break;
	}
	if (i == -1) {
		puts("-1"); return 0;
	}
	for (; i < n; i++) {
		if (buf1[0] == 'V') {
			ts.addImplies(n + i, i);
			if (ts.check()) {
				curword[i] = 0;
				continue;
			}
			ts.adj[n + i].pop_back();
			ts.adj[n + i].pop_back();
			ts.rev_adj[i].pop_back();
			ts.rev_adj[i].pop_back();
			curword[i] = first_c;
			ts.addImplies(i, n + i);
		}
		else {
			ts.addImplies(i, n + i);
			if (ts.check()) {
				curword[i] = 0;
				continue;
			}
			ts.adj[i].pop_back();
			ts.adj[i].pop_back();
			ts.rev_adj[n + i].pop_back();
			ts.rev_adj[n + i].pop_back();
			curword[i] = first_v;
			ts.addImplies(n + i, i);
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%c", curword[i] + 'a');
	}
	return 0;
}