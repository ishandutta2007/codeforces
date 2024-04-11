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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> K;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end());
	vector<long long int>sum(N + 1);
	for (int i = 0; i < N; i++) {
		sum[i + 1] = sum[i] + v[i];
	}
	queue<pair<int, int>>Q;
	Q.emplace(0, N);
	set<long long int>st;
	while (!Q.empty()) {
		auto box = Q.front();
		Q.pop();
		st.insert(sum[box.second] - sum[box.first]);
		if (v[box.first] != v[box.second - 1]) {
			int mid = (v[box.first] + v[box.second - 1]) / 2;
			auto it = upper_bound(v.begin(), v.end(), mid) - v.begin();
			Q.emplace(box.first, it);
			Q.emplace(it, box.second);
		}
	}

	while (K--) {
		cin >> M;
		if (st.find(M) != st.end())cout << "Yes\n";
		else cout << "No\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}