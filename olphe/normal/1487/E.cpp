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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void func(vector<long long int>& a, vector<long long int>& b) {
	cin >> K;
	vector<vector<int>>ng(b.size());
	for (int i = 0; i < K; i++) {
		cin >> L >> R;
		L--, R--;
		ng[R].push_back(L);
	}
	multiset<long long int>st;
	for (auto i : a)st.insert(i);
	for (int i = 0; i < b.size(); i++) {
		for (auto j : ng[i]) {
			st.erase(st.find(a[j]));
		}
		if (st.empty()) {
			b[i] = MOD * MOD;
		}
		else {
			b[i] += *st.begin();
		}
		for (auto j : ng[i]) {
			st.insert(a[j]);
		}
	}
}

void Solve() {
	vector<int>num(4);
	for (auto& i : num)cin >> i;
	vector<vector<long long int>>box(4);
	for (int i = 0; i < 4; i++) {
		box[i].resize(num[i]);
		for (auto& j : box[i])cin >> j;
	}
	for (int i = 1; i < 4; i++) {
		func(box[i - 1], box[i]);
	}
	long long int ans = *min_element(box[3].begin(), box[3].end());
	if (ans >= MOD * MOD)ans = -1;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}