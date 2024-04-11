#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

struct fast_io {
	fast_io() {
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout << fixed << setprecision(15);
	}
} fast_io_;

#define rep(i, x) for(int i = 0; i < (x); i++)

struct state {
	vector<int> d;
	int sum;
	state(vector<int> d_, int sum_) : d(d_), sum(sum_) {}
};
bool operator<(const state x, const state y) {
	return x.sum < y.sum;
};

int main() {
	//part.1 input
	int n;
	cin >> n;
	vector a(n, vector<int>());
	rep(i, n) {
		int c;
		cin >> c;
		a[i].resize(c);
		for(auto &v : a[i]) cin >> v;
	}

	int m;
	cin >> m;
	set<vector<int>> ban;
	rep(i, m) {
		vector<int> b(n);
		for(auto &v : b) cin >> v, --v;
		ban.insert(b);
	}

	//part.2 dijkstra

	//make max vector
	vector<int> mx;
	int tmp = 0;
	rep(i, n) {
		mx.push_back(a[i].size() - 1);
		tmp += a[i].back();
	}

	//output
	auto out = [](vector<int> res) {
		for(auto &v : res) cout << ++v << " ";
		cout << endl;
		exit(0);
	};

	if(!ban.count(mx)) {
		out(mx);
	}

	priority_queue<state> pq;
	set<vector<int>> visited;
	auto s = state(mx, tmp);
	pq.push(s);
	visited.insert(mx);

	while(pq.size()) {
		auto [nowv, nows] = pq.top();
		pq.pop();
		if(!ban.count(nowv)) {
			out(nowv);
		}
		rep(i, n) {
			if(!nowv[i]) continue;
			auto next_v = nowv;
			next_v[i]--;
			auto next_s = nows;
			next_s += a[i][next_v[i]] - a[i][nowv[i]];
			auto next_state = state(next_v, next_s);
			if(visited.count(next_v)) continue;
			visited.insert(next_v);
			pq.push(next_state);
		}
	}
}