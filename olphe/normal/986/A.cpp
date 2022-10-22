#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"

using namespace std;

const long long int MOD = 1000000007;


long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> L >> R;
	vector<int>goods(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> goods[i];
	}
	vector<vector<int>>edge(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> H >> W;
		edge[H].push_back(W);
		edge[W].push_back(H);
	}
	vector<vector<int>>dis(N + 1, vector<int>(L + 1, MOD));
	vector<vector<int>>box(L + 1);
	for (int i = 1; i <= N; i++) {
		dis[i][goods[i]] = 0;
		box[goods[i]].push_back(i);
	}
	for (int i = 1; i <= L; i++) {
		queue<int>Q;
		for (auto j : box[i]) {
			Q.push(j);
		}
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto j : edge[cn]) {
				if (dis[j][i] > dis[cn][i] + 1) {
					dis[j][i] = dis[cn][i] + 1;
					Q.push(j);
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		sort(dis[i].begin(), dis[i].end());
		long long int ans = 0;
		for (int j = 0; j < R; j++) {
			ans += dis[i][j];
		}
		cout << ans << " ";
	}
	cout << endl;
	return 0;
}