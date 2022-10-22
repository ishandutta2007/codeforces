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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	int lst[200001] = {};
	for (int i = 2; i <= 200000; i++) {
		if (lst[i] == 0) {
			lst[i] = i;
		}
		else {
			continue;
		}
		for (int j = i * 2; j <= 200000; j += i) {
			lst[j] = i;
		}
	}
	vector<map<int, int>>mp(200001);
	vector<map<int, int>>num(200001);
	for (int i = 2; i <= 200000; i++) {
		if (lst[i] == i) {
			num[i][0] = N;
		}
	}
	long long int ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> K;
		while (K > 1) {
			num[lst[K]][mp[lst[K]][i]]--;
			if (num[lst[K]].begin()->second == 0) {
				num[lst[K]].erase(num[lst[K]].begin());
				ans *= lst[K];
				ans %= MOD;
			}
			mp[lst[K]][i]++;
			num[lst[K]][mp[lst[K]][i]]++;
			K /= lst[K];
		}
	}
	while (M--) {
		int i;
		cin >> i >> K;
		i--;
		while (K > 1) {
			num[lst[K]][mp[lst[K]][i]]--;
			if (num[lst[K]].begin()->second == 0) {
				num[lst[K]].erase(num[lst[K]].begin());
				ans *= lst[K];
				ans %= MOD;
			}
			mp[lst[K]][i]++;
			num[lst[K]][mp[lst[K]][i]]++;
			K /= lst[K];
		}
		cout << ans << endl;
	}
}