#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string.h>
#define mp(a,b) make_pair((a),(b))
#define nextInt(n) scanf("%d",&(n))
#define F(i,n) for(int (i) = 0; (i) < n; (i)++)

using namespace std;
typedef long long ll;

int val[200000];
int confirm[200000];
int vis[200000];
vector<pair<int, int> > clausepv[200000];
vector<pair<int, int> > clause[200000];
vector<pair<int, pair<int, int> > > adj[200000];
int tmpvis[200000];
int stk[200000];
int sp = -1;

vector<int> cyc;
int xx;
int cnt;

int dfs(int i, pair<int, int> edge) {
	tmpvis[i] = 1;
	cnt++;
	for (auto &x : adj[i]) {
		if (x.second == edge) continue;
		if (tmpvis[x.first]) {
			xx = x.first;
			val[x.second.first] = (x.second.second + 1) / 2;
			confirm[x.second.first] = 1;
			vis[x.first] = 1;
			cyc.push_back(i);
			if (i == xx) return 0;
			else return 1;
		}
		else {
			if (dfs(x.first, mp(x.second.first, -x.second.second))) {
				val[x.second.first] = (x.second.second + 1) / 2;
				confirm[x.second.first] = 1;
				vis[x.first] = 1;
				cyc.push_back(i);
				if (i == xx) return 0;
				else return 1;
			}
			else if (cyc.size() > 0) return 0;
		}
	}
	return 0;
}

void dfs2(int i) {
	vis[i] = 1;
	for (auto &x : adj[i]) {
		if (vis[x.first]) continue;
		vis[x.first] = 1;
		if (x.second.second == 1) {
			val[x.second.first] = 0;
		}
		else val[x.second.first] = 1;
		confirm[x.second.first] = 1;
		dfs2(x.first);
	}
}

void solve(int i) {
	cyc.clear();
	cnt = 0;
	dfs(i, mp(-1, -1));
	if (cyc.empty() && cnt>1) {
		printf("NO");
		fflush(stdout);
		exit(0);
	}
	for (auto &x : cyc) {
		dfs2(x);
	}
}

void destroy_cl(int k) {
	for (auto &x : clause[k]) {
		int v = x.first;
		if (clausepv[v].size() == 1) {
			clausepv[v].pop_back();
		}
		else {
			if (clausepv[v][0] == mp(k, x.second)) {
				swap(clausepv[v][0], clausepv[v][1]);
				clausepv[v].pop_back();
			}
			else {
				clausepv[v].pop_back();
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	nextInt(n); nextInt(m);
	F(i, n) {
		int k;
		nextInt(k);
		F(j, k) {
			int tp = 1;
			int v;
			nextInt(v);
			if (v < 0) {
				tp = -1; v = -v;
			}
			v--;
			clausepv[v].push_back(mp(i, tp));
			clause[i].push_back(mp(v, tp));
		}
	}
	F(i, m) {
		if (clausepv[i].size() != 2) continue;
		if (clausepv[i][0].second == clausepv[i][1].second) {
			int tp = clausepv[i][0].second;
			if (tp == 1) val[i] = 1;
			confirm[i] = 1;
			destroy_cl(clausepv[i][1].first);
			destroy_cl(clausepv[i][0].first);
		}
	}
	F(i, m) {
		if (confirm[i]) continue;
		if (clausepv[i].size() == 0) {
			val[i] = 1;
			confirm[i] = 1;
		}
		else if (clausepv[i].size() == 1) {
			int v = clausepv[i][0].first;
			int tp = clausepv[i][0].second;
			adj[v].push_back(mp(v, mp(i, tp)));
		}
		else {
			int u = clausepv[i][0].first;
			int tp = clausepv[i][0].second;
			int v = clausepv[i][1].first;
			adj[u].push_back(mp(v, mp(i, tp)));
			adj[v].push_back(mp(u, mp(i, -tp)));
		}
	}
	F(i, n) {
		if (vis[i]) continue;
		solve(i);
	}
	puts("YES");
	F(i, m) {
		printf("%d", val[i]);
	}
	return 0;
}