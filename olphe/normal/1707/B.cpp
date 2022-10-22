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
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<pair<int, int>>v(N);
	for (auto& i : v) {
		cin >> i.first;
		i.second = 1;
	}
	for (int loop = 1; loop < N; loop++) {
		vector<pair<int, int>>nx;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].second > 1) {
				nx.push_back({ 0,v[i].second - 1 });
			}
			if (i) {
				nx.push_back({ v[i].first - v[i - 1].first,1 });
			}
		}
		sort(nx.begin(), nx.end());
		v.clear();
		for (auto i : nx) {
			if (v.empty() || i.first != v.back().first) {
				v.push_back(i);
			}
			else {
				v.back().second += i.second;
			}
		}
	}
	cout << v[0].first << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}