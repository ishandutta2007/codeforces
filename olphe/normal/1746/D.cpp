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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


long long func(vector<long long>& c, vector<vector<int>>& edge, int node, int num, map<pair<int, int>, long long>& mp) {
	if (mp.find({ node,num }) != mp.end()) {
		return mp[{node, num}];
	}
	if (edge[node].empty()) {
		mp[{node, num}] = c[node] * num;
		return c[node] * num;
	}
	long long ret = 0;
	vector<long long>add;
	for (auto i : edge[node]) {
		ret += func(c, edge, i, num / edge[node].size(), mp);
		if (num % edge[node].size()) {
			add.push_back(func(c, edge, i, (num / edge[node].size()) + 1, mp) - func(c, edge, i, num / edge[node].size(), mp));
		}
	}
	sort(add.rbegin(), add.rend());
	ret += c[node] * num;
	for (int i = 0; i < num % edge[node].size(); i++) {
		ret += add[i];
	}
	mp[{node, num}] = ret;
	return ret;
}

void Solve() {
	cin >> N >> K;
	map<pair<int, int>, long long>mp;
	vector<int>p(N, -1);
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> p[i];
		p[i]--;
		edge[p[i]].push_back(i);
	}
	vector<long long>c(N);
	for (auto& i : c)cin >> i;
	cout << func(c, edge, 0, K, mp) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}