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

void Solve() {
	cin >> N >> M;
	vector<long long>v(N);
	for (auto& i : v) {
		cin >> i;
	}
	v.push_back(-MOD * MOD);
	v.push_back(MOD * MOD);
	sort(v.begin(), v.end());
	set<pair<long long, int>>s;
	for (int i = 0; i < N + 2; i++) {
		s.insert({ v[i],i });
	}
	vector<pair<long long, long long>>w(M);
	vector<vector<pair<long long, long long>>>cost(N + 2);
	for (auto& i : w) {
		cin >> i.first >> i.second;
		auto it = s.lower_bound({ i.first,0 });
		if (it->first <= i.second)continue;
		auto pv = prev(it);
		cost[pv->second].push_back({ i.first - pv->first,it->first - i.second });
	}
	long long ans = 0;
	vector<long long>dp(1, 0);
	vector<long long>dis(1, 0);
	for (long long i = 0; i < N + 2; i++) {
		sort(cost[i].begin(), cost[i].end());
		if (cost[i].empty()) {
			long long add = MOD * 5;
			for (long long j = 0; j < dp.size(); j++) {
				add = min(add, dp[j] + dis[j]);
			}
			ans += add;
			dp = vector<long long>(1, 0);
			dis = vector<long long>(1, 0);
			continue;
		}
		vector<long long>ndp(cost[i].size() + 1);
		vector<long long>ndis(cost[i].size() + 1);
		multiset<long long>ms;
		for (long long j = 0; j < cost[i].size(); j++) {
			ms.insert(cost[i][j].second);
		}
		ndis[0] = *ms.rbegin();
		for (long long j = 0; j < cost[i].size(); j++) {
			ms.erase(ms.find(cost[i][j].second));
			if (ms.size())ndis[j + 1] = *ms.rbegin();
			else ndis[j + 1] = 0;
		}
		vector<long long>one(dp.size());
		vector<long long>two(dp.size());
		for (long long j = 0; j < dp.size(); j++) {
			one[j] = dp[j] + dis[j];
			two[j] = dp[j] + dis[j] * 2;
			if (j)one[j] = min(one[j], one[j - 1]);
		}
		for (long long j = dp.size() - 1; j > 0; j--) {
			two[j - 1] = min(two[j - 1], two[j]);
		}
		long long idx = dp.size();
		ndp[0] = one.back();
		for (long long j = 0; j < cost[i].size(); j++) {
			while (idx - 1 >= 0 && cost[i][j].first > dis[idx-1]) {
				idx--;
			}
			ndp[j + 1] = MOD * 5;
			if (idx != dp.size()) {
				ndp[j + 1] = min(ndp[j + 1], two[idx] + cost[i][j].first);
			}
			if (idx) {
				ndp[j + 1] = min(ndp[j + 1], one[idx - 1] + cost[i][j].first * 2);
			}
		}
		dp = ndp;
		dis = ndis;
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