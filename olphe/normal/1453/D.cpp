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
//constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	if (N & 1) {
		cout << -1 << endl;
		return;
	}
	vector<int>ans;
	N >>= 1;
	while (N) {
		for (int i = 59; i > 0; i--) {
			if ((1LL << i) - 1 <= N) {
				N -= (1LL << i) - 1;
				ans.push_back(1);
				for (int j = 1; j < i; j++)ans.push_back(0);
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}