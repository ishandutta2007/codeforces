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
constexpr long double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<long long int, long long int>>v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first;
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i].second;	
	}
	map<int, vector<int>>mp;
	for (int i = 0; i < N; i++)mp[v[i].first].push_back(v[i].second);
	long long int ans = 0;
	priority_queue<int>PQ;
	long long int sum = 0;
	int bef = 0;
	for (auto i : mp) {
		while (bef < i.first && !PQ.empty()) {
			sum -= PQ.top();
			PQ.pop();
			ans += sum;
			bef++;
		}
		for (auto j : i.second) {
			PQ.push(j);
			sum += j;
		}
		bef = i.first;
	}
	while (!PQ.empty()) {
		sum -= PQ.top();
		PQ.pop();
		ans += sum;
	}
	cout << ans << endl;
	return 0;
}