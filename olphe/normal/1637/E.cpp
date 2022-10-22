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
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void func(map<int, int>& mp, map<int, vector<int>>& num,set<pair<int,int>>&s, long long &val) {
	for (auto& i : mp) {
		for (auto& j : num) {
			for (auto& k : j.second) {
				if (i.first == k)continue;
				if (s.find(minmax(i.first, k)) != s.end())continue;
				long long c = 1LL * (i.first + k) * (i.second + j.first);
				val = max(val, c);
				if (c <= val)break;
			}
		}
	}
}

void Solve() {
	cin >> N >> M;
	vector<int>v(N);
	map<int, int>mp;
	for (auto& i : v) {
		cin >> i;
		mp[i]++;
	}
	map<int, vector<int>>num;
	for (auto &i : mp) {
		num[i.second].push_back(i.first);
	}
	for (auto& i : num)reverse(i.second.begin(), i.second.end());
	set<pair<int, int>>s;
	for (int i = 0; i < M; i++) {
		cin >> L >> R;
		s.insert(minmax(L, R));
	}
	long long ans = 0;
	func(mp, num, s, ans);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}