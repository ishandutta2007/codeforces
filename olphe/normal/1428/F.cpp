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
	string s;
	cin >> s;
	vector<int>sum(N + 2);
	vector<vector<int>>lbox(N + 1);
	vector<vector<int>>rbox(N + 1);
	vector<int>p;
	vector<vector<int>>pbox(N + 1);
	for (int i = 0; i < N; i++) {
		sum[i + 1] = s[i] == '1';
		sum[i + 1] = sum[i + 1] * sum[i] + sum[i + 1];
		rbox[sum[i + 1]].push_back(i + 1);
	}
	for (int i = 1; i <= N; i++) {
		if (sum[i] && sum[i + 1] == 0) {
			pbox[sum[i]].push_back(i);
		}
	}
	int bef = 0;
	for (int i = N + 1; i > 0; i--) {
		if (sum[i] == 0) {
			bef = 0;
			continue;
		}
		if (bef == 0)bef = sum[i];
		lbox[bef - sum[i] + 1].push_back(i);
	}
	set<int>lst;
	set<int>rst;
	lst.insert(N + 1);
	rst.insert(N + 1);
	lst.insert(0);
	rst.insert(0);
	long long int ans = 0;
	for (int i = N; i > 0; i--) {
		for (auto j : lbox[i]) {
			lst.insert(j);
		}
		for (auto j : pbox[i])p.push_back(j);
		for (auto j : p) {
			if (sum[j] == i) {
				int rp = j - sum[j] + 1;
				auto rit = prev(lst.lower_bound(rp));
				int lp = j;
				auto lit = rst.upper_bound(lp);
				ans += 1LL * (rp - *rit)*(*lit - lp)*i;
			}
			else if (sum[j] > i) {
				ans += 1LL * (sum[j] - i - 1)*i;
				int rp = j - sum[j] + 1;
				auto it = prev(lst.lower_bound(rp));
				ans += 1LL * (rp - *it)*i;
				int lp = j;
				it = rst.upper_bound(lp);
				ans += 1LL * (*it - lp)*i;
			}
		}
		for (auto j : rbox[i]) {
			rst.insert(j);
		}
	//	cout << i << " " << ans << endl;
	}
	cout << ans << endl;
}