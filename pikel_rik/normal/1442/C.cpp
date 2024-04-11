#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 998244353;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m, two[N];
vector<int> g[N][2];

struct number {
	int val, exp;
	number(): val(), exp(N - 1) {}
	number(int val, int exp): val(val), exp(exp) {}

	int value() const {
		return (val + two[exp]) % mod;
	}
	bool operator<(const number &num) const {
		if (exp == num.exp)
			return val < num.val;
		if (exp > 20 || num.exp > 20)
			return exp < num.exp;
		return val + two[exp] < num.val + two[num.exp];
	}
	bool operator>(const number &num) const {
		if (exp == num.exp)
			return val > num.val;
		if (exp > 20 || num.exp > 20)
			return exp > num.exp;
		return val + two[exp] > num.val + two[num.exp];
	}
};

number lvl[N][20];

void dijkstra() {
	priority_queue<pair<number, pair<int, int>>, vector<pair<number, pair<int, int>>>, greater<>> q;
	lvl[0][0] = {0, 0};
	q.emplace(lvl[0][0], make_pair(0, 0));

	while (!q.empty()) {
		auto [x, y] = q.top().second;
		q.pop();
		for (int i : g[x][y % 2]) {
			number new_lvl(1 + lvl[x][y].val, lvl[x][y].exp);
			if (new_lvl < lvl[i][y]) {
				lvl[i][y] = new_lvl;
				q.emplace(lvl[i][y], make_pair(i, y));
			}
		}
		number new_lvl(lvl[x][y].val, lvl[x][y].exp + 1);
		if (1 + y < 20 && new_lvl < lvl[x][1 + y]) {
			lvl[x][1 + y] = new_lvl;
			q.emplace(lvl[x][1 + y], make_pair(x, 1 + y));
		}
	}
}

number dist[N][2];

void dijkstra1() {
	priority_queue<pair<number, pair<int, int>>, vector<pair<number, pair<int, int>>>, greater<>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 20; j++) {
			if (lvl[i][j] < dist[i][j % 2]) {
				dist[i][j % 2] = lvl[i][j];
			}
		}
		if (dist[i][0].exp != N - 1) {
			q.emplace(dist[i][0], make_pair(i, 0));
	 	}
		if (dist[i][1].exp != N - 1) {
			q.emplace(dist[i][1], make_pair(i, 1));
		}
	}

	while (!q.empty()) {
		auto [x, y] = q.top().second;
		q.pop();

		for (int i : g[x][y]) {
			number new_dist(1 + dist[x][y].val, dist[x][y].exp);
			if (new_dist < dist[i][y]) {
				dist[i][y] = new_dist;
				q.emplace(dist[i][y], make_pair(i, y));
			}
		}
		number new_dist(dist[x][y].val, dist[x][y].exp + 1);
		if (1 + y < 20 && new_dist < dist[x][1 - y]) {
			dist[x][1 - y] = new_dist;
			q.emplace(dist[x][1 - y], make_pair(x, 1 - y));
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	two[1] = 1;
	for (int i = 2; i < N; i++) {
		two[i] = (2 * two[i - 1] + 1) % mod;
	}

	cin >> n >> m;
	for (int i = 0, u, v; i < m; i++) {
		cin >> u >> v;
		--u; --v;
		g[u][0].push_back(v);
		g[v][1].push_back(u);
	}

	dijkstra();
	dijkstra1();
	cout << min(dist[n - 1][0], dist[n - 1][1]).value() << '\n';
	return 0;
}