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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<pair<long long int,int>>>cost(N + 1);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cost[a].push_back({ b,i + 1 });
	}
	for (int i = 0; i <= N; i++) {
		sort(cost[i].begin(), cost[i].end());
	}
	L = 0;
	R = N + 1;
	vector <pair<long long int,int>>ans;
	while (R - L > 1) {
		int mid = (R + L + 1) / 2;
		vector<pair<long long int,int>>v;
		for (int i = mid; i <= N; i++) {
			for (auto j : cost[i]) {
				v.push_back({ j.first,j.second });
			}
		}
		sort(v.begin(), v.end());
		long long int box = 0;
		if (v.size() < mid) {
			R = mid;
			continue;
		}
		for (int i = 0; i < mid; i++) {
			box += v[i].first;
		}
		if (box <= M) {
			L = mid;
			v.resize(mid);
			ans = v;
		}
		else {
			R = mid;
		}
	}
	cout << L << endl;
	cout << L << endl;
	for (auto i : ans) {
		cout << i.second;
		if (i != ans.back()) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}