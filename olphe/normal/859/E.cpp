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



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>l(N);
	vector<int>r(N);
	vector<vector<int>>to(N * 2 + 1);
	vector<int>from(N * 2 + 1);
	vector<long long int>dp(N * 2 + 1, 1);
	long long int ans = 1;
	vector<bool>flag(N * 2 + 1, false);
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i];
		to[l[i]].push_back(r[i]);
		from[r[i]]++;
		flag[l[i]] = true;
		flag[r[i]] = true;
	}
	queue<int>Q;
	for (int i = 1; i <= N * 2; i++) {
		if (!from[i]) {
			Q.push(i);
		}
	}
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		flag[cn] = false;
		if (to[cn].empty()) {
			ans *= dp[cn];
			ans %= MOD;
			continue;
		}
		for (auto i : to[cn]) {
			dp[i] += dp[cn];
			from[i]--;
			if (!from[i]) {
				Q.push(i);
			}
		}
	}
	for (int i = 1; i <= N * 2; i++) {
		if (flag[i]) {
			int box = -1;
			Q.push(i);
			while (!Q.empty()) {
				box++;
				int cn = Q.front();
				Q.pop();
				flag[cn] = false;
				for (auto j : to[cn]) {
					if (flag[j]) {
						Q.push(j);
					}
				}
			}
			if (box) {
				ans *= 2;
				ans %= MOD;
			}
		}
	}
	cout << ans << endl;
	return 0;
}