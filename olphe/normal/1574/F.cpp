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
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;

	vector<long long>dp(M + 1);
	int amari = K;
	vector<vector<int>>v(N);
	vector<set<int>>edge(K + 1);
	for (auto& i : v) {
		int sz;
		cin >> sz;
		i.resize(sz);
		for (auto& j : i)cin >> j;
		for (int j = 1; j < i.size(); j++) {
			edge[i[j - 1]].insert(i[j]);
		}
	}
	map<int, int>mp;
	vector<int>dir(K + 1);
	for (int i = 1; i <= K; i++) {
		for (auto j : edge[i]) {
			dir[j]++;
		}
	}
	vector<int>used(K + 1);
	for (int i = 1; i <= K; i++) {
		if (dir[i]) continue;
		int add = 1;
		int cn = i;
		bool ok = true;
		while (edge[cn].size()) {
			if (used[cn]) {
				ok = false;
				break;
			}
			used[cn] = 1;
			if (edge[cn].size() == 1) {
				cn = *edge[cn].begin();
				add++;
			}
			else {
				ok = false;
				break;
			}
			if (dir[cn] > 1) {
				ok = false;
				break;
			}
		}
		if (ok) {
			mp[add]++;
		}
	}
	dp[0] = 1;
	for (int i = 0; i < M; i++) {
		for (auto j : mp) {
			if (i + j.first <= M) {
				dp[i + j.first] += dp[i] * j.second;
				dp[i + j.first] %= MOD;
			}
		}
	}
	cout << dp.back() << endl;
}