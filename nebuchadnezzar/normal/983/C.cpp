#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

int encode(int i, int lvl, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int ret = i * 10 + lvl;
	for (int j = 0; j < 4; ++j) {
		if (j < szof(arr)) {
			ret = ret * 10 + arr[j];
		} else {
			ret = ret * 10 + 9;
		}
	}
	return ret;
}

tuple<int, int, vector<int>> decode(int num) {
	vector<int> arr;
	for (int i = 0; i < 4; ++i) {
		if (num % 10 != 9) {
			arr.push_back(num % 10);
		}
		num /= 10;
	}
	sort(arr.begin(), arr.end());

	int lvl = num % 10;
	num /= 10;
	return {num, lvl, arr};
}

void solve() {
	int n;
	cin >> n;
	//vector<vector<pii>> lvl(9);
	vector<pii> inp;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		//lvl[a].push_back({b, i});
		inp.push_back({a, b});
	}

	unordered_map<int, int> dist;
	int st = encode(n, 0, {});
	dist[st] = 0;
	queue<int> q;
	q.push(st);
	while (szof(q)) {
		int cur = q.front();
		q.pop();
		int left, lvl;
		vector<int> arr;
		tie(left, lvl, arr) = decode(cur);

		if (!left && !szof(arr)) {
			cout << dist[cur] << "\n";
			return;
		}

		auto it = find(arr.begin(), arr.end(), lvl);
		if (it != arr.end()) {
			arr.erase(it);
			int to = encode(left, lvl, arr);
			if (!dist.count(to)) {
				dist[to] = dist[cur] + 1;
				q.push(to);
			}
			continue;
		}

		if (left && szof(arr) < 4 && inp[n - left].ff == lvl) {
			arr.push_back(inp[n - left].ss);
			int to = encode(left - 1, lvl, arr);
			if (!dist.count(to)) {
				dist[to] = dist[cur] + 1;
				q.push(to);
			}
			continue;
		}

		if (lvl) {
			int to = encode(left, lvl - 1, arr);
			if (!dist.count(to)) {
				dist[to] = dist[cur] + 1;
				q.push(to);
			}
		}

		if (lvl < 8) {
			int to = encode(left, lvl + 1, arr);
			if (!dist.count(to)) {
				dist[to] = dist[cur] + 1;
				q.push(to);
			}
		}
	}
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}