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
const int MAXN = 3005;

int n, m;
vector<int> graph[MAXN];
bool used[MAXN];
int dist[MAXN][MAXN];

vector<pii> bfs(int start)  {
 	queue<pii> q;
 	q.push({start, 0});
 	vector<pii> ret;
 	used[start] = true;
 	while (szof(q)) {
 	 	pii p = q.front();
 	 	q.pop();
 	 	//cerr << p.ff << " " << p.ss << endl;
 	 	ret.puba(p);
 	 	for (int to: graph[p.ff]) {
 	 	 	if (!used[to]) {
 	 	 	 	used[to] = true;
 	 	 	 	q.push({to, p.ss + 1});
 	 	 	}
 	 	}
 	}
 	return ret;
}

set<pii> rows[MAXN], rrows[MAXN];

int main() {
	//freopen("inp", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i) {
	 	int a, b;
	 	scanf("%d%d", &a, &b);
	 	--a; --b;
	 	graph[a].puba(b);
	}


	memset(dist, -1, sizeof dist);
	for (int i = 0; i < n; ++i) {
	 	vector<pii> tmp = bfs(i);
		for (auto p: tmp) {
		 	used[p.ff] = false;
		 	dist[i][p.ff] = p.ss;
		}
	}

	/*
	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < n; ++j) {
	 	 	cerr << dist[i][j] << " ";
	 	}
	 	cerr << endl;
	}*/

	int best = 0;
	vector<int> ans = {-1, -1, -1, -1};

	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < n; ++j) {
	 	 	if (dist[i][j] != -1) {
	 	 	 	rows[i].insert({dist[i][j], j});
	 	 	 	if (szof(rows[i]) > 4) {
	 	 	 	 	rows[i].erase(rows[i].begin());
	 	 	 	}
	 	 	}
	 	 	if (dist[j][i] != -1) {
	 	 	 	rrows[i].insert({dist[j][i], j});
	 	 	 	if (szof(rrows[i]) > 4) {
	 	 	 	 	rrows[i].erase(rrows[i].begin());
	 	 	 	}
	 	 	}
	 	}
	}

	for (int i = 0; i < n; ++i) {
	 	for (int j = 0; j < n; ++j) {
	 	 	if (dist[i][j] == -1 || i == j) {
	 	 	 	continue;
	 	 	}
	 	 	auto tmp1 = rows[j].end();
	 	 	--tmp1;
	 	 	for (int i1 = 0; i1 < 4; ++i1) {
	 	 		auto tmp2 = rrows[i].end();
	 	 		--tmp2;
	 	 	 	for (int i2 = 0; i2 < 4; ++i2) {
	 	 	 	 	if (tmp2 -> ss != i && tmp2 -> ss != j && tmp1 -> ss != i && tmp1 -> ss != j && tmp1 -> ss != tmp2 -> ss) {
	 	 	 	 	 	int now = tmp1 -> ff + tmp2 -> ff + dist[i][j];
	 	 	 	 	 	if (now > best) {
	 	 	 	 	 	 	best = now;
	 	 	 	 	 	 	ans = {tmp2 -> ss, i, j, tmp1 -> ss};
	 	 	 	 	 	}
	 	 	 	 	 	break;
	 	 	 	 	}

	 	 	 		if (tmp2 == rrows[i].begin()) {
	 	 	 		 	break;
	 	 	 		}
	 	 	 		--tmp2;
	 	 	 	}

	 	 		if (tmp1 == rows[j].begin()) {
	 	 		 	break;
	 	 		}
	 	 		--tmp1;
	 	 	}
	 	}
	}

	cerr << best << endl;

	for (int num: ans) {
	 	cout << num + 1 << " ";
	}
	cout << "\n";

	return 0;
}