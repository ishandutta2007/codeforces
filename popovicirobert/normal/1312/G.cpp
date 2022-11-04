#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int INF = (int) 1e9;
const int MAXN = (int) 1e6;

struct Node {
	int mn, lazy, cnt;
	Node(int _mn = INF, int _lazy = INF) : mn(_mn), lazy(_lazy), cnt(0) {}
}aint[1 << 21];

inline void prop(int nod, int left, int right) {
	if(left != right) {
		aint[2 * nod].lazy = min(aint[2 * nod].lazy, aint[nod].lazy);
		aint[2 * nod + 1].lazy = min(aint[2 * nod + 1].lazy, aint[nod].lazy + aint[2 * nod].cnt);
	}
	aint[nod].mn = min(aint[nod].mn, aint[nod].lazy);
	aint[nod].lazy = INF;
}

bool leaf[MAXN + 1];

void build(int nod, int left, int right) {
	if(left == right) {
		aint[nod].cnt = leaf[left];
	}
	else {
		int mid = (left + right) / 2;
		build(2 * nod, left, mid);
		build(2 * nod + 1, mid + 1, right);
		aint[nod].cnt = aint[2 * nod].cnt + aint[2 * nod + 1].cnt;
	}
}

void update(int nod, int left, int right, int l, int r, int &cur) {
	prop(nod, left, right);
	if(l > right || r < left) return ;
	if(l <= left && right <= r) {
		aint[nod].lazy = cur;
		prop(nod, left, right);
		cur += aint[nod].cnt;
		return ;
	}
	int mid = (left + right) / 2;
	update(2 * nod, left, mid, l, r, cur);
	update(2 * nod + 1, mid + 1, right, l, r, cur);
}

int query(int nod, int left, int right, int pos) {
	prop(nod, left, right);
	if(left == right) {
		return aint[nod].mn;
	}
	int mid = (left + right) / 2;
	return (pos <= mid ? query(2 * nod, left, mid, pos) : query(2 * nod + 1, mid + 1, right, pos));
}

vector <pair <int, char>> g[MAXN + 1];
int idl[MAXN + 1], idr[MAXN + 1], id;
int pat[MAXN + 1];

void dfs(int nod) {
	idl[nod] = ++id;
	for(auto &it : g[nod]) {
		dfs(it.first);
	}
	idr[nod] = id;
}

int dp[MAXN + 1], n;

void solve(int nod) {
	if(leaf[idl[nod]]) {
		dp[nod] = min(dp[nod], query(1, 1, n + 1, idl[nod]));
	}
	int cur = dp[nod] + 1;
	update(1, 1, n + 1, idl[nod], idr[nod], cur);
	for(auto &it : g[nod]) {
		dp[it.first] = min(dp[it.first], dp[nod] + 1);
		solve(it.first);
	}
}

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int i;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for(i = 1; i <= n; i++) {
		int par; cin >> par;
		char ch; cin >> ch;
		g[par].push_back({i, ch});
	}
	for(i = 0; i <= n; i++) {
		sort(g[i].begin(), g[i].end(), [&](const pair <int, char> &x, const pair <int, char> &y) {
			return x.second < y.second;
		});
	}

	dfs(0);
	int k; cin >> k;
	for(i = 1; i <= k; i++) {
		cin >> pat[i];
		leaf[idl[pat[i]]] = 1;
	}

	build(1, 1, n + 1);

	fill(dp + 1, dp + n + 1, INF);
	solve(0);
	for(i = 1; i <= k; i++) {
		cout << dp[pat[i]] << " ";
	}

	return 0;
}