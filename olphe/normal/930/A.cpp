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

	cin >> N;
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> M;
		M--;
		edge[M].push_back(i);
	}
	vector<int>dis(N, INT_MAX);
	vector<int>num(N, 0);
	queue<int>Q;
	dis[0] = 0;
	Q.push(0);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (int i : edge[cn]) {
			dis[i] = dis[cn] + 1;
			Q.push(i);
		}
	}
	for (int i = 0; i < N; i++) {
		num[dis[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += num[i] % 2;
	}
	cout << ans << endl;
	return 0;
}