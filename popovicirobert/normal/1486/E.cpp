#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "
 
 
using namespace std;


struct State {
	int node;
	long long totalCost;
	int edgeCost;

	bool operator<(const State& other) const {
		return totalCost > other.totalCost;
	}
};



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    int n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

	cin >> n >> m;
	vector<vector<pair<int, int>>> graph(n + 1);
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		graph[x].push_back({y, z});
		graph[y].push_back({x, z});
	}

	const int MAXVAL = 50;
	const long long INF = 1e18;
	vector<vector<long long>> dp(n + 1, vector<long long>(MAXVAL + 1, INF));
	vector<vector<bool>> visited(n + 1, vector<bool>(MAXVAL + 1, false));

	priority_queue<State> heap;
	heap.push({1, 0, 0});
	dp[1][0] = 0;

	while (heap.size()) {
		auto current = heap.top();
		heap.pop();

		if (visited[current.node][current.edgeCost])
			continue;

		dp[current.node][current.edgeCost] = current.totalCost;
		visited[current.node][current.edgeCost] = true;

		for (auto& edge : graph[current.node]) {

			auto updateHeap = [&dp, &heap](int node, int edgeCost, long long totalCost) {
				if (dp[node][edgeCost] > totalCost) {
					dp[node][edgeCost] = totalCost;
					heap.push({node, totalCost, edgeCost});
				}
			};

			if (current.edgeCost == 0) {
				updateHeap(edge.first, edge.second, current.totalCost);
			}
			else {
				updateHeap(edge.first, 0, current.totalCost + 1LL * (current.edgeCost + edge.second) *
																	(current.edgeCost + edge.second));
			}
		}
	}

	for (int node = 1; node <= n; node++) {
		long long answer = -1;
		if (dp[node][0] != INF) {
			answer = dp[node][0];
		}
		cout << answer << " ";
	}

    return 0;
}