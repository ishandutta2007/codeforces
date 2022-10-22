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


void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	int ans = 0;
	int st = 0;
	map<int, int>mp;
	for (int i = 1; i < N; i++) {
		if (v[i] == v[i - 1]) {
			ans++;
			mp[v[st]]++;
			mp[v[i - 1]]++;
			st = i;
		}
	}
	mp[v[st]]++;
	mp[v.back()]++;
	int sum = 0;
	int idx = 0;
	for (auto i : mp) {
		sum += i.second;
		if (mp[idx] < i.second) {
			idx = i.first;
		}
	}
	for (int i = 1; i < N; i++) {
		if (v[i] != v[i - 1] && v[i] != idx && v[i - 1] != idx && mp[idx] * 2 - 2 > sum) {
			ans++;
			sum += 2;
		}
	}
	if (mp[idx] * 2 - 2 > sum) {
		cout << -1 << endl;
		return;
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}