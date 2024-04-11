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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>dp(1000001);
	dp[0] = 1;
	for (auto i : v) {
		int box = sqrt(i);
		list<int>l;
		if (box*box == i) {
			l.push_back(box);
			box--;
		}
		for (int j = box; j >= 1; j--) {
			if (i%j == 0) {
				l.push_back(j);
				l.push_front(i / j);
			}
		}
		for (auto j : l) {
			dp[j] += dp[j - 1];
			dp[j] %= MOD;
		}
	}
	cout << (accumulate(dp.begin(), dp.end(), 0LL) + MOD - 1) % MOD << endl;
}