#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 505;

int n, m;
int graph[MAXN][MAXN];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < n; ++j) {
	 	 	graph[i][j] = 1;
	 	}
	 	graph[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
	 	int a, b;
	 	scanf("%d%d", &a, &b);
	 	--a; --b;
		graph[a][b] = graph[b][a] = 0;
	}

	vector<char> ans;
	ans.resize(n);
	set<vector<int>> have;

	for (int i = 0; i < n; ++i) {
	 	vector<int> v;
	 	for (int j = 0; j < n; ++j) {
	 	 	if (graph[i][j]) {
	 	 	 	v.puba(j);
	 	 	}
	 	}
	 	if (!szof(v)) {
	 	 	ans[i] = 'b';
	 	} else {
	 	 	have.insert(v);
	 	}
	}

	if (szof(have) > 2) {
	 	cout << "No\n";
	 	return 0;
	}

	for (int i = 0; i < n; ++i) {
	 	vector<int> v;
	 	for (int j = 0; j < n; ++j) {
	 	 	if (graph[i][j]) {
	 	 	 	v.puba(j);
	 	 	}
	 	}
	 	if (szof(v)) {
	 	 	if (*have.begin() == v) {
	 	 	 	ans[i] = 'a';
	 	 	} else {
	 	 	 	ans[i] = 'c';
	 	 	}
	 	}
	}


	cout << "Yes\n";
	for (char c: ans) {
	 	cout << c;
	}
	cout << "\n";
	return 0;
}