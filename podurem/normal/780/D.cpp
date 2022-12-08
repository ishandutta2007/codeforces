#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cassert>
#include <bitset>
#include <numeric>

using namespace std;

typedef long long ll;
typedef double ld;

int solve();

int main() {
#ifdef PoDuReM
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

string A[dd][2];
vector<int> G[dd], p, Gr[dd];
int used[dd], D[dd], n, cnt, num[dd];

void top_sort(int v) {
	used[v] = 1;
	for (int i = 0; i < (int)G[v].size(); ++i)
		if (!used[G[v][i]])
			top_sort(G[v][i]);
	p.push_back(v);
}

void dfs(int v) {
	num[v] = cnt;
	int V = v;
	if (V >= n) V -= n;
	used[v] = 1;
	if (D[V] == 0) {
		if (v < n)
			D[V] = 1;
		else
			D[V] = 2;
	}
	for (int i = 0; i < (int)Gr[v].size(); ++i) if (!used[Gr[v][i]])
		dfs(Gr[v][i]);
}

int solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s, t;
		cin >> s >> t;
		A[i][0] = string(s.begin(), s.begin() + 3);
		A[i][1] = string(s.begin(), s.begin() + 2) + t[0];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (A[i][0] == A[j][0]) {
				G[i + n].push_back(j + n), G[j].push_back(i);
				G[i].push_back(j), G[j + n].push_back(i + n);
				G[i].push_back(j + n), G[j].push_back(i + n);
			}
			if (A[i][0] == A[j][1])
				G[i].push_back(j), G[j + n].push_back(i + n);
			if (A[i][1] == A[j][0])
				G[j].push_back(i), G[i + n].push_back(j + n);
			if (A[i][1] == A[j][1]) {
				G[i + n].push_back(j), G[j + n].push_back(i);
			}
		}
	}
	
	for (int i = 0; i < 2 * n; ++i) if (!used[i])
		top_sort(i);

	for (int i = 0; i < 2 * n; ++i)
		for (int j = 0; j < (int)G[i].size(); ++j)
			Gr[G[i][j]].push_back(i);

	memset(used, 0, sizeof used);
	for (int i = 2 * n - 1; i >= 0; --i) if (!used[p[i]])
		cnt++, dfs(p[i]);
	
	for (int i = 0; i < n; ++i)
		if (num[i] == num[i + n])
			return 0 * puts("NO");

	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		if (D[i] == 1)
			cout << A[i][1] << "\n";
		else
			cout << A[i][0] << "\n";
	return 0;
}