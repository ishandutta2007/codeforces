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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

long long int num[200000] = {};
vector<vector<long long int>>dp(200000, vector<long long int>(2, LLONG_MAX));

long long int Search(int fig, int turn) {
	if (dp[fig][turn] != LLONG_MAX) {
		return dp[fig][turn];
	}
	if (turn) {
		dp[fig][turn] = min(Search(fig + 1, 0) - num[fig], Search(fig + 1, 1) + num[fig]);
	}
	else {
		dp[fig][turn] = max(Search(fig + 1, 0) - num[fig], Search(fig + 1, 1) + num[fig]);
	}
	return dp[fig][turn];
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
		M += num[i];
	}
	dp[N][0] = num[N];
	dp[N][1] = num[N]*(-1);
	K = Search(1, 0);
	cout << (M-K) / 2 << " " << (K + M) / 2 << endl;
	return 0;
}