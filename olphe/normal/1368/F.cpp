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

/*
int func(vector<int>&dp, vector<int>&used,int node = 0) {
	if (used[node])return dp[node];
	used[node] = 1;
	int num = 0;
	for (int i = 0; i < N; i++) {
		if ((node >> i) & 1)num++;
	}
	int ans = 0;
	for (int i = 0; i < 1 << N; i++) {
		if (node&i)continue;
		int cans = MOD;
		int b = 0;
		for (int j = 0; j < N; j++) {
			if ((i >> j) & 1)b++;
		}
		for (int j = 0; j < N; j++) {
			int add = 1 << N;
			add--;
			for (int k = 0; k < b; k++) {
				int idx = j + k;
				idx %= N;
				add ^= 1 << idx;
			}
			int box = (node | i) & add;
			int c = 0;
			for (int k = 0; k < N; k++) {
				if ((box >> k) & 1)c++;
			}
			if(c>num)cans = min(cans, func(dp,used, box));
			else cans = num;
		}
		//cans %= MOD;
		ans = max(ans, cans);
	}
	ans %= MOD;
	dp[node] = max(dp[node], ans);
	return dp[node];
}
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	cin >> N;
	if (N < 4) {
		cout << 0 << endl;
		return 0;
	}
	K = 0;
	vector<int>num(N + 1);
	vector<int>bef(N + 1);
	vector<int>ans(N + 1);
	vector<int>len(N + 1);
	for (int i = 4; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			if (i%j == 0) {
				if (ans[i] < (j - 1)*(i / j - 1)) {
					ans[i] = max(ans[i], (j - 1)*(i / j - 1));
					len[i] = j;
				}
			}
			else {
				if (ans[i] < (j - 1)*(i / j) - (j - i % j)) {
					len[i] = j;
					ans[i] = max(ans[i], (j - 1)*(i / j) - (j - i % j));
				}
			}
		}
	}
	vector<int>fin(N + 1);
	if (N%len[N] == 0) {
		for (int i = 1; i <= N; i++) {
			if (i%len[N])fin[i] = 1;
		}
	}
	else {
		vector<int>box(N / len[N], len[N]);
		for (int i = 0; i < N%len[N]; i++)box[i]++;
		int cnt = 1;
		for (auto i : box) {
			for (int j = 0; j < i-1; j++) {
				fin[cnt++] = 1;
			}
			cnt++;
		}
	}
	do  {
		bef = num;
		vector<int>v;
		for (int i = 1; i <= N; i++) {
			if (!num[i] && fin[i]) {
				v.push_back(i);
				num[i] = 1;
			}
		}
		cout << v.size() << endl;
		for (auto i : v)cout << i << " ";
		cout << endl;
		//M = 1;
		cin >> M;
		for (int i = M; i < M + v.size(); i++) {
			int idx = i;
			if (idx > N)idx -= N;
			num[idx] = 0;
		}
	} while (num != bef);
	for (int i = 1; i <= N; i++) {
		if (fin[i] == 0) {
			swap(fin[i], fin[i - 1]);
			break;
		}
	}
	vector<int>v;
	for (int i = 1; i <= N; i++) {
		if (!num[i] && fin[i]) {
			v.push_back(i);
			num[i] = 1;
		}
	}
	cout << v.size() << endl;
	for (auto i : v)cout << i << " ";
	cout << endl;
	//M = 1;
	cin >> M;
	for (int i = M; i < M + v.size(); i++) {
		int idx = i;
		if (idx > N)idx -= N;
		num[idx] = 0;
	}
	cout << 0 << endl;
//	cout << accumulate(num.begin(), num.end(), 0) << endl;
//	cout << ans[N] << endl;
	/*
	cin >> N;
	vector<int>dp(1 << N);
	vector<int>used(1 << N);
	for (int i = 0; i < 1 << N; i++) {
		int num = 0;
		for (int j = 0; j < N; j++) {
			if ((i >> j) & 1)dp[i]++;
		}
	}
	cout << func(dp,used) << endl;
	//for (auto i : dp)cout << i << endl;
	*/
}