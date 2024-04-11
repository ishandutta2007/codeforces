#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

int anc[100000][17];
vector<int> ppl[100000][17];
vector<int> adj[100000];
int vis[100000];
int h[100000];

void merge(vector<int> &a, vector<int> &b) {
	if (a.empty()) {
		a = b;
		return;
	}
	else if (b.empty()) return;
	vector<int> tmp;
	int sz1 = a.size(); int sz2 = b.size();
	int i1 = 0; int i2 = 0;
	while (1) {
		if (a[i1] < b[i2]) {
			tmp.push_back(a[i1]);
			i1++;
			if (i1 + i2 == 10) {
				a = tmp;
				return;
			}
			if (i1 == sz1) {
				for (; i2 < sz2 && i1 + i2 <= 10; i2++) {
					tmp.push_back(b[i2]);
				}
				a = tmp;
				return;
			}
		}
		else {
			tmp.push_back(b[i2]);
			i2++;
			if (i1 + i2 == 10) {
				a = tmp;
				return;
			}
			if (i2 == sz2) {
				for (; i1 < sz1 && i1 + i2 <= 10; i1++) {
					tmp.push_back(a[i1]);
				}
				a = tmp;
				return;
			}
		}
	}
	return;

}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n,m,q;
	scanf("%d %d %d", &n,&m,&q);
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m; i++) {
		int c;
		scanf("%d", &c);
		c--;
		ppl[c][0].push_back(i + 1);
	}
	queue<int> bfsq;
	memset(vis, 0, sizeof(vis));
	anc[0][0] = -1;
	vis[0] = 1;
	h[0] = 0;
	bfsq.push(0);
	while (!bfsq.empty()) {
		int x = bfsq.front(); bfsq.pop();
		for (auto &v : adj[x]) {
			if (vis[v]) continue;
			vis[v] = 1;
			anc[v][0] = x;
			h[v] = h[x] + 1;
			bfsq.push(v);
		}
	}
	for (int i = 1; i < 17; i++) {
		for (int j = 0; j < n; j++) {
			int a = anc[j][i - 1];
			if (a == -1) {
				anc[j][i] = -1;
			}
			else {
				anc[j][i] = anc[a][i - 1];
				ppl[j][i] = ppl[j][i - 1];
				merge(ppl[j][i], ppl[a][i - 1]);
			}
		}
	}
	for (int i = 0; i < q; i++) {
		int u, v, a;
		scanf("%d %d %d", &u, &v, &a);
		u--; v--;
		if (h[u] < h[v]) swap(u, v);
		int dif = h[u] - h[v];
		int M = 16;
		vector<int> tmp;
		while (M >= 0) {
			if (dif >= (1 << M)) {
				merge(tmp, ppl[u][M]);
				u = anc[u][M];
				dif -= (1 << M);
			}
			M--;
		}
		if (u != v) {
			M = 16;
			while (M >= 0) {
				if (anc[u][M] != anc[v][M]) {
					merge(tmp, ppl[u][M]);
					merge(tmp, ppl[v][M]);
					u = anc[u][M];
					v = anc[v][M];
				}
				M--;
			}
			merge(tmp, ppl[u][0]);
			merge(tmp, ppl[v][0]);
			u = anc[u][0];
			v = anc[v][0];
		}
		merge(tmp, ppl[u][0]);
		if (tmp.size() > a) tmp.resize(a);
		printf("%d ", tmp.size());
		for (auto &x : tmp) printf("%d ", x);
		printf("\n");
	}
	
}