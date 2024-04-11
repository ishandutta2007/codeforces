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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>num(20);
	for (auto i : v) {
		for (int j = 0; j < 20; j++) {
			if ((i >> j) & 1)num[j]++;
		}
	}
	vector<long long int>w(N);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < num[i]; j++) {
			w[j] |= 1LL << i;
		}
	}
	long long int ans = 0;
	for (auto i : w)ans += i * i;
	cout << ans << endl;
}