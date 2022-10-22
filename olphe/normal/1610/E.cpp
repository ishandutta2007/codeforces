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
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (i&&v[i] == v[i - 1])continue;
		int num = 0;
		int sum = 0;
		{
			auto it = lower_bound(v.begin(), v.end(), v[i]);
			auto nx = upper_bound(v.begin(), v.end(), v[i]);
			num += nx - it;
			if (nx == v.end()) {
				ans = max(ans, num);
				continue;
			}
			num++;
			sum = (*nx) - v[i];
		}
		while (1) {
			auto it = lower_bound(v.begin(), v.end(), v[i] + sum * 2);
			if (it == v.end())break;
			num++;
			sum = (*it) - v[i];
		}
		ans = max(ans, num);
	}
	ans = N - ans;
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}

}