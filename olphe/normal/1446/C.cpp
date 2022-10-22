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

	cin >> N;
	vector<int>v(N);
	//	for (int i = 0; i < N; i++)v[i] = i * 5000;
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end());
	vector<map<int, int>>sz(31);
	for (int i = 0; i < N; i++) {
		sz[0][v[i]]++;
	}
	int ans = 0;
	for (int i = 1; i <= 30; i++) {
		int bef = -1;
		for (int k = 0; k < N; k++) {
			int j = v[k] >> i;
			if (bef == j)continue;
			bef = j;
			int a = 0;
			int b = 0;
			if (sz[i - 1].find(j * 2) != sz[i - 1].end()) {
				a = sz[i - 1][j * 2];
			}
			if (sz[i - 1].find(j * 2 + 1) != sz[i - 1].end()) {
				b = sz[i - 1][j * 2 + 1];
			}
			if (min(a, b) <= 1) {
				sz[i][j] = a + b;
			}
			else {
				sz[i][j] = max(a, b) + 1;
				ans += min(a, b) - 1;
			}
		}
	}
	cout << ans << endl;
}