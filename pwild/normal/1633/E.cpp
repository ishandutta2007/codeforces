#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct dsu {
	int n;
	vector<int> p, h;

	dsu(int n): n(n), p(n), h(n) {
		iota(begin(p), end(p), 0);
	}
	
	int find(int x) {
		if (x == p[x]) return x;
		return p[x] = find(p[x]);
	}

	bool unite(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return false;
		
		if (h[x] < h[y]) swap(x,y);
		if (h[x] == h[y]) h[x]++;
		p[y] = x;
		return true;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	
	vector<tuple<int,int,int>> edges(m);
	for (auto &[c,a,b]: edges) {
		cin >> a >> b >> c;
		a--, b--;
	}
	
	vector<double> weights;
	for (int i = 0; i < m; i++) {
		int v = get<0>(edges[i]);
		weights.push_back(v);
		for (int j = 0; j < i; j++) {
			int w = get<0>(edges[j]);
			weights.push_back(0.5*(v+w));
		}
	}
	weights.push_back(-1);
	weights.push_back(1e8+1);

	sort(begin(weights), end(weights));
	weights.erase(unique(begin(weights), end(weights)), end(weights));

	auto mst = [&](double x) {
		vector<tuple<double,bool,int,int>> nedges;
		for (auto [c,a,b]: edges) {
			nedges.emplace_back(abs(c-x), c < x, a, b);
		}
		sort(begin(nedges), end(nedges));

		dsu D(n);
		i64 count = 0;
		double sum = 0;
		for (auto [c,neg,a,b]: nedges) {
			if (!D.unite(a,b)) continue;
			sum += c, count += neg;
		}
		return make_pair(sum, count);
	};

	vector<pair<double,i64>> lines;
	for (int i = 0; i+1 < ssize(weights); i++) {
		double x = (weights[i] + weights[i+1]) / 2;
		lines.push_back(mst(x));
	}

	auto solve = [&](int y) -> i64 {
		int i = upper_bound(begin(weights), end(weights), y) - begin(weights) - 1;
		double x = (weights[i] + weights[i+1]) / 2;
		auto [sum,count] = lines[i];
		double res = count*(y-x) + sum + (n-1-count)*(x-y);
		// cerr << res << endl;
		return llround(res);
	};
	
	int p, k, a, b, c;
	cin >> p >> k >> a >> b >> c;

	i64 res = 0;

	int x;
	for (int i = 0; i < k; i++) {
		if (i < p) cin >> x;
		else x = (i64(x)*a + b) % c;
		// cerr << x << " ";
		res ^= solve(x);
	}
	cout << res << '\n';
}