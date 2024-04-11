#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define rbend(_x) (_x).rbegin(), (_x).rend()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 2e5 + 5;

int n, x, y;
vector<int> graph[MAXN];
int d[2][MAXN];

int dfs(int v, int p) {
	int sum = 0;
 	for (int to: graph[v]) {
 	 	if (p != to) {
 	 	 	dfs(to, v);
 	 	 	sum += d[1][to];
 	 	}
 	}
 	//cerr << v << " " << sum << endl;
 	d[0][v] = sum;
 	vector<int> best;
 	for (int to: graph[v]) {
 	 	if (p != to) {
 	 	 	d[0][v] = max(d[0][v], sum - d[1][to] + d[0][to] + 1);
 	 	 	best.puba(d[0][to] - d[1][to] + 1);
 	 	}
 	}
 	if (szof(best) >= 2) {
    	sort(rbend(best));
    	d[1][v] = sum + best[0] + best[1];
 	}
 	d[1][v] = max(d[1][v], d[0][v]);
 	//cerr << v << " " << d[0][v] << " " << d[1][v] << endl;
 	return 0;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d%d", &n, &x, &y);

	for (int i = 0; i < n - 1; ++i) {
	 	int a, b;
	 	scanf("%d%d", &a, &b);
	 	--a; --b;
	 	graph[a].puba(b);
	 	graph[b].puba(a);
	}

	if (x > y) {
		bool flag = false;
	 	for (int i = 0; i < n; ++i) {
	 	 	if (szof(graph[i]) == n - 1) {
	 	 	 	flag = true;
	 	 	 	break;
	 	 	}
	 	}
	 	if (flag) {
	 	 	cout << (ll) y * (n - 2) + x << "\n";
	 	} else {
	 	 	cout << (ll) y * (n - 1) << "\n";
	 	}
	 	return 0;
	}

	dfs(0, 0);

	cout << (ll) (n - max(d[0][0], d[1][0]) - 1) * y + (ll) max(d[0][0], d[1][0]) * x << "\n";

	return 0;
}