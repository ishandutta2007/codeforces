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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<bitset<7>>bs(N);
	for (int i = 0; i < N; i++)cin >> bs[i];
	vector<vector<int>>dp(N + 1, vector<int>(K + 1));
	dp[0][0] = 1;
	reverse(bs.begin(), bs.end());
	vector<bitset<7>>num(10);
	num[0] = 0b1110111;
	num[1] = 0b0010010;
	num[2] = 0b1011101;
	num[3] = 0b1011011;
	num[4] = 0b0111010;
	num[5] = 0b1101011;
	num[6] = 0b1101111;
	num[7] = 0b1010010;
	num[8] = 0b1111111;
	num[9] = 0b1111011;
	//for (auto i : num)cout << i << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			if (!dp[i][j])continue;
			for (int k = 0; k < 10; k++) {
				if ((bs[i] & num[k]) != bs[i])continue;
				int add = num[k].count() - bs[i].count();
				if (j + add > K)continue;
				dp[i + 1][j + add] = 1;
			}
		}
	}
	if (dp.back().back() == 0) {
		cout << -1 << endl;
		return 0;
	}
	int place = K;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 9; j >=0; j--) {
			if ((bs[i] & num[j]) != bs[i])continue;
			int add = num[j].count() - bs[i].count();
			if (add > place)continue;
			if (dp[i][place - add]) {
				place -= add;
				cout << j;
				break;
			}
		}
	}
	cout << endl;
}