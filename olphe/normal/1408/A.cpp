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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>a(N);
		vector<int>b(N);
		vector<int>c(N);
		for (auto &i : a)cin >> i;
		for (auto &i : b)cin >> i;
		for (auto &i : c)cin >> i;
		vector<int>ans(N);
		ans[0] = a[0];
		for (int i = 1; i < N - 1; i++) {
			if (ans[i - 1] != a[i])ans[i] = a[i];
			else ans[i] = b[i];
		}
		if (ans[0] != a.back() && ans[N - 2] != a.back())ans.back() = a.back();
		if (ans[0] != b.back() && ans[N - 2] != b.back())ans.back() = b.back();
		if (ans[0] != c.back() && ans[N - 2] != c.back())ans.back() = c.back();
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}