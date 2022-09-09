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
const int MAXN = 1e5 + 5;

int n, m;
vector<pii> graph[MAXN];
int t;
vector<int> order;
bool used[MAXN];

int dfs(int v) {
 	used[v] = true;
 	for (auto to: graph[v]) {
 	 	if (!used[to.ff]) {
 	 	 	dfs(to.ff);
 	 	}
 	}
 	order.puba(v);

 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i) {
	 	int u, v;
	 	scanf("%d%d", &u, &v);
	 	--u; --v;
	 	graph[u].puba({v, i + 1});
	}

	for (int i = 0; i < n; ++i) {
	 	if (!used[i]) {
	 	 	dfs(i);
	 	}
	}

	reverse(bend(order));

	int l = 0, r = m + 1;

	while (r - l > 1) {
	 	int mid = (r + l) / 2;
	 	bool flag = true;
	 	for (int i = 0; i < n - 1; ++i) {
	 		bool tflag = false;
	 	 	for (auto to: graph[order[i]]) {
	 	 	 	if (to.ss <= mid) {
	 	 	 	 	if (to.ff == order[i + 1]) {
	 	 	 	 	 	tflag = true;
	 	 	 	 	 	break;
	 	 	 	 	}
	 	 	 	}
	 	 	}
	 	 	if (!tflag) {
	 	 	 	flag = false;
	 	 	 	break;
	 	 	}
	 	}
	 	if (flag) {
	 	 	r = mid;
	 	} else {
	 	 	l = mid;
	 	}
	}

	if (r == m + 1) {
	 	cout << -1 << "\n";
	} else {
	 	cout << r << "\n";
	}
	return 0;
}