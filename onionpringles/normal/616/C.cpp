#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <tuple>

#define mp make_pair
#define mtp make_tuple
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;

char buf[1000][1001];
char ansbuf[1000][1001];

vector<int> adj[1000000];
int ccn = 0;
int cc[1000000];
int vis[1000000];
int cccnt[1000000];

void dfs(int i) {
	vis[i] = 1;
	cc[i] = ccn;
	cccnt[ccn]++;
	for (auto &x : adj[i]) {
		if (vis[x]) continue;
		dfs(x);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	nii(n, m);

	auto ind = [&m](int i, int j)->int {return m*i + j; };

	for (int i = 0; i < n; i++) {
		scanf("%s", buf[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (buf[i][j] == '*') {
				vis[ind(i, j)] = 1;
				continue;
			}
			if (i < n - 1 && buf[i+1][j] == '.') {
				adj[ind(i, j)].push_back(ind(i + 1, j));
				adj[ind(i + 1, j)].push_back(ind(i, j));
			}
			if (j < m - 1 && buf[i][j + 1] == '.') {
				adj[ind(i, j)].push_back(ind(i, j + 1));
				adj[ind(i, j + 1)].push_back(ind(i, j));
			}
		}
	}

	for (int i = 0; i < n*m; i++) {
		if (vis[i]) continue;
		dfs(i);
		ccn++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (buf[i][j] == '.') {
				ansbuf[i][j] = '.';
				continue;
			}
			set<int> tmp;
			if (i > 0 && buf[i - 1][j] == '.') tmp.insert(cc[ind(i - 1, j)]);
			if (j > 0 && buf[i][j - 1] == '.') tmp.insert(cc[ind(i, j - 1)]);
			if (i < n - 1 && buf[i + 1][j] == '.') tmp.insert(cc[ind(i + 1, j)]);
			if (j < m - 1 && buf[i][j + 1] == '.') tmp.insert(cc[ind(i, j + 1)]);
			int ans = 1;
			for (auto &x : tmp) {
				ans += cccnt[x];
			}
			ans %= 10;
			ansbuf[i][j] = '0' + ans;
		}
		printf("%s\n", ansbuf[i]);
	}

	return 0;
}