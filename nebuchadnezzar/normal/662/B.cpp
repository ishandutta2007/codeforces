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
vector<int> now;
int ofthat[2];
bool used[MAXN];
int color[MAXN];

bool flag_bad = false;

int dfs(int v, int c, int ce) {
	now.puba(v);
 	used[v] = true;
 	color[v] = c;
 	ofthat[c]++;
 	for (auto p: graph[v]) {
 	 	if (!used[p.ff]) {
 	 	 	dfs(p.ff, p.ss == ce ? 1 - c : c, ce);
 	 	}
 	 	if (p.ss == ce) {
 	 	 	if (color[v] == color[p.ff]) {
 	 	 	 	//cerr << v << " -> " << p.ff << endl;
 	 	 	 	flag_bad = true;
 	 	 	}
 	 	} else {
 	 	 	if (color[v] != color[p.ff]) {
 	 	 	 	flag_bad = true;
 	 	 	}
 	 	}
 	}
 	return 0;
}

vector<int> solve(int c) {
 	memset(color, -1, sizeof color);
 	memset(used, 0, sizeof used);
 	vector<int> ret;
 	flag_bad = false;

 	for (int i = 0; i < n; ++i) {
 	 	if (!used[i]) {
 	 		memset(ofthat, 0, sizeof ofthat);
 	 		now.clear();
 	 	 	dfs(i, 0, c);
 	 	 	int good = 0;
 	 	 	if (ofthat[1] < ofthat[0]) {
 	 	 	 	good = 1;
 	 	 	}

 	 	 	for (int v: now) {
 	 	 	 	if (color[v] == good) {
 	 	 	 	 	ret.puba(v);
 	 	 	 	}
 	 	 	}
 	 	}
 	}
	/*
 	for (int i = 0; i < n; ++i) {
 	 	cerr << color[i] << " ";
 	}
 	cerr << endl;*/
 	return ret;
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);

	for (int i = 0; i < m; ++i) {
	 	int a, b;
	 	char c;
	 	scanf("%d%d %c", &a, &b, &c);
	 	--a; --b;

	 	graph[a].puba({b, c == 'R'});
	 	graph[b].puba({a, c == 'R'});
	}

	vector<int> tmp1 = solve(0);
	bool tmpflag1 = flag_bad;

	vector<int> tmp2 = solve(1);
	bool tmpflag2 = flag_bad;


	if (tmpflag1 && tmpflag2) {
	 	cout << "-1\n";
	 	return 0;
	}

	if ((!tmpflag2 && szof(tmp1) > szof(tmp2)) || tmpflag1) {
	 	swap(tmp1, tmp2);
	}

	cout << szof(tmp1) << "\n";

	for (int v: tmp1) {
	 	cout << v + 1 << " ";
	}
	cout << "\n";

	return 0;
}