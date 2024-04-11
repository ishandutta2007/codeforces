#pragma warning(disable:4996)
#pragma comment(linker,"/STACK:1073741824")

#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>
#define mp(a,b) make_pair(a,b)

using namespace std;

typedef pair<int, char> pic;
typedef pair<pic, int> pici;

const int MN = 300000;

pici quu[MN];
int lp = 0, up = -1;

vector<int> adj[MN];

int dif[MN];
int c[MN];
char vtc[MN+1];
int anc[MN][19];
int h[MN];
int tp[MN];
int stk[MN];
int sp = -1;
int vis[MN];
int subt[MN];
int parch[MN][26];

inline void push(int l, int m, int n) {
	quu[++up] = mp(mp(l, m), n);
}

int lca(int m, int n) {
	if (h[m] < h[n]) return lca(n, m);
	int dif = h[m] - h[n];
	int maxlg = 18;
	while (maxlg>=0) {
		if (dif == 0) break;
		if ((1 << maxlg) > dif) {
			maxlg--; continue;
		}
		dif -= (1 << maxlg);
		m = anc[m][maxlg];
		maxlg--;
	}
	if (m == n) return m;
	maxlg = 18;
	while (maxlg >= 0) {
		if (anc[m][maxlg] == anc[n][maxlg]) {
			maxlg--;
			continue;
		}
		m = anc[m][maxlg];
		n = anc[n][maxlg];
		maxlg--;
	}
	return anc[m][0];
}

void dfs(int u) {
	int cnt = 1;
	vis[u] = 1;
	for (auto &v : adj[u]) {
		if (vis[v]) continue;
		dfs(v);
		cnt += dif[v];
	}
	cnt -= subt[u];
	dif[u] = cnt;
}

int main() {
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d ", c + i);
	scanf(" %s ", vtc);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v); adj[v].push_back(u);
	}

	memset(vis, 0, sizeof(vis));
	stk[++sp] = 0; anc[0][0] = -1; h[0] = 0;
	while (sp >= 0) {
		int u = stk[sp--];
		vis[u] = 1;
		for (auto &v : adj[u]) {
			if (vis[v]) continue;
			anc[v][0] = u;
			h[v] = h[u] + 1;
			stk[++sp] = v;
		}
	}
	
	for (int i = 1; i <= 18; i++) {
		for (int j = 0; j < n; j++) {
			int a = anc[j][i - 1];
			if (a == -1) anc[j][i] = -1;
			else anc[j][i] = anc[a][i - 1];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			parch[i][j] = -1;
		}
	}

	memset(vis, 0, sizeof(vis));
	memset(subt, 0, sizeof(subt));
	vis[0] = 1; int avtp = 0; tp[0] = 0;
	for (auto &v : adj[0]) {
		push(tp[0], vtc[v], v);
	}
	while (lp <= up) {
		int upsv = up;
		for (int i = lp; i <= upsv; i++) {
			auto x = quu[i];
			vis[x.second] = 1;
			if (parch[x.first.first][x.first.second - 'a'] != -1) {
				int a = lca(x.second, parch[x.first.first][x.first.second - 'a']);
				tp[x.second] = tp[parch[x.first.first][x.first.second - 'a']];
				subt[a]++;
			}
			else {
				tp[x.second] = ++avtp;
			}

			parch[x.first.first][x.first.second - 'a'] = x.second;
			for (auto &v : adj[x.second]) {
				if (vis[v])continue;
				push(tp[x.second], vtc[v], v);
			}
		}
		lp = upsv + 1;
	}

	memset(vis, 0, sizeof(vis));
	dfs(0);
	int maxval = -1;
	int maxcnt = 0;
	for (int i = 0; i < n; i++) {
		if (maxval < dif[i] + c[i]) {
			maxcnt = 1;
			maxval = dif[i] + c[i];
		}
		else if(maxval==dif[i]+c[i]) {
			maxcnt++;
		}

	}

	printf("%d\n%d", maxval, maxcnt);
}