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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	sort(v.rbegin(), v.rend());
	vector<int>w(M);
	for (auto &i : w)cin >> i;
	vector<pair<int, int>>ans(N);
	for (int i = 0; i < N; i++) {
		ans[i].second = v[i];
	}
	multiset<int>ms;
	for (int i = 0; i < N; i++)ms.insert(0);
	int cnt = 0;
	for (auto i : v) {
		auto it = ms.upper_bound(-w[i - 1]);
		ans[cnt++].first = -(*it - 1);
		ms.insert(*it - 1);
		ms.erase(it);
	}
	sort(ans.begin(), ans.end());
	vector<vector<int>>ret(N);
	vector<int>num(N + 1);
	for (auto i : ans) {
		ret[num[i.first]++].push_back(i.second);
	}
	while (ret.back().empty())ret.pop_back();
	cout << ret.size() << endl;
	for (auto i : ret) {
		cout << i.size();
		for (auto j : i)cout << " " << j;
		cout << endl;
	}
}