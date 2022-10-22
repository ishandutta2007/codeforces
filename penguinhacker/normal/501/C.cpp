#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<int, int>
const int MOD=1e9+7;

int n, degree[1<<16], xSum[1<<16];
set<pi> nodes;
vector<pi> edges;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0, x; i<n; ++i) {
		cin >> degree[i] >> xSum[i];
		if (degree[i]>0)
			nodes.insert({degree[i], i});
	}
	while (!nodes.empty()) {
		int num=nodes.begin()->second;
		int to=xSum[num];
		nodes.erase(nodes.begin());
		edges.emplace_back(num, to);
		auto it=nodes.find({degree[to],to});
		nodes.erase(it);
		degree[to]--;
		xSum[to]^=num;
		if (degree[to]>0)
			nodes.insert({degree[to],to});
	}
	cout << edges.size() << '\n';
	for (auto x:edges)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}