#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define ni(x) scanf("%d", &(x))
#define mp make_pair

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int adj[500][500];
vector<int> adj2[500];
int cc[500];
int ccn = 0;
int vis[500];
int vis2[500];
char ans[500];
vector<int> ccs[2];

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; ni(n);
	int m; ni(m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--; v--;
		adj[u][v] = adj[v][u] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			if (!adj[i][j]) {
				adj2[i].push_back(j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (adj2[i].size() == 0) {
			ans[i] = 'b';
			vis[i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (vis[i]) continue;
		for (auto &x : adj2[i]) {
			ccs[0].push_back(x);
			vis2[x] = 1;
			ans[x] = 'a';
		}
		break;
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i] && !vis2[i]) {
			ccs[1].push_back(i);
			ans[i] = 'c';
		}
	}
	int sz1 = ccs[0].size();
	int sz2 = ccs[1].size();
	for (int i = 0; i < sz1; i++) {
		for (int j = 0; j < sz2; j++) {
			if (adj[ccs[0][i]][ccs[1][j]]) {
				puts("No");
				return 0;
			}
		}
		for (int k = 0; k < i; k++) {
			if (!adj[ccs[0][i]][ccs[0][k]]) {
				puts("No");
				return 0;
			}
		}
	}
	for (int j = 0; j < sz2; j++) {
		for (int i = 0; i < j; i++) {
			if (!adj[ccs[1][i]][ccs[1][j]]) {
				puts("No");
				return 0;
			}
		}
	}
	puts("Yes");
	printf("%s", ans);
	

	return 0;
}