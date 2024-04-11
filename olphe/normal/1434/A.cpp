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

	vector<int>v(6);
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end());
	cin >> N;
	vector<int>w(N);
	for (auto &i : w)cin >> i;
	sort(w.begin(), w.end());
	int ans = MOD;
	priority_queue<pair<int, pair<int, int>>>PQ;
	int m = MOD;
	for (int i = 0; i < N; i++) {
		PQ.push({ w[i] - v.front(),{i,0} });
		m = min(m, w[i] - v.front());
	}
	ans = PQ.top().first - m;
	while (1) {
		auto box = PQ.top();
		PQ.pop();
		if (box.second.second == 5) {
			break;
		}
		box.second.second++;
		box.first = w[box.second.first] - v[box.second.second];
		m = min(m, box.first);
		PQ.push(box);
		ans = min(ans, PQ.top().first - m);
	}
	cout << ans << endl;
}