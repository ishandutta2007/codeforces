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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	vector<int>p(N + 1);
	for (auto& i : v)cin >> i;
	for (int i = 0; i < N; i++) {
		p[v[i]] = i;
	}
	int lst = N;
	vector<int>ans;
	for (int i = N; i > 0; i--) {
		if (p[i] < lst) {
			for (int j = p[i]; j < lst; j++) {
				ans.push_back(v[j]);
			}
			lst = p[i];
		}
	}
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}