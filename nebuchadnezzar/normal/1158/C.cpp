// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }


void solve() {
	int n;
	cin >> n;
	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}
	vector<vector<int>> graph(bpv * 2);
	for (int i = 1; i < bpv; ++i) {
		graph[i * 2].push_back(i);
		graph[i * 2 + 1].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int pos;
		cin >> pos;
		if (pos == -1) {
			continue;
		}
		--pos;
		int l = i + 1 + bpv, r = pos + bpv;
		// cerr << l << " " << r << endl;
		while (l < r) {
			if (l & 1) {
				graph[l].push_back(bpv + i);
				++l;
			}
			if (r & 1) {
				--r;
				graph[r].push_back(bpv + i);
			}
			l /= 2;
			r /= 2;
		}
		if (pos < n) {
			graph[bpv + i].push_back(bpv + pos);
		}
	}
	queue<int> qu;
	vector<int> in(szof(graph));
	for (int i = 0; i < szof(graph); ++i) {
		for (int to : graph[i]) {
			// cerr << i << " " << to << endl;
			in[to]++;
		}
	}

	for (int i = 0; i < szof(graph); ++i) {
		if (!in[i]) {
			qu.push(i);
		}
	}

	vector<int> ans(n);
	int cnt = 0;
	while (szof(qu)) {
		int v = qu.front();
		qu.pop();
		if (bpv <= v && v < bpv + n) {
			ans[v - bpv] = cnt++;
		}
		for (int to : graph[v]) {
			--in[to];
			if (!in[to]) {
				qu.push(to);
			}
		}
	}

	if (cnt < n) {
		cout << "-1\n";
		return;
	}
	for (int num : ans) {
		cout << num + 1 << " ";
	}
	cout << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}