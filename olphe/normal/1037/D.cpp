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
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>edge(N + 1);
	vector<int>dis(N + 1, MOD);
	vector<int>parent(N + 1);
	dis[1] = 0;
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	queue<int>Q;
	Q.push(1);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (dis[i] > dis[cn] + 1) {
				dis[i] = dis[cn] + 1;
				parent[i] = cn;
				Q.push(i);
			}
		}
	}
	vector<int>v(N);
	vector<int>order(N + 1);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		order[v[i]] = i;
	}
	if (v[0] != 1) {
		cout << "No\n";
		return 0;
	}
	for (int i = 1; i < N; i++) {
		if (dis[v[i]] < dis[v[i - 1]]) {
			cout << "No\n";
			return 0;
		}
	}
	for (int i = 2; i < N; i++) {
		if (order[parent[v[i]]] < order[parent[v[i - 1]]]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}