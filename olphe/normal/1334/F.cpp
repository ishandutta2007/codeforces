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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>cost(N);
	long long int ans = 0;
	for (auto &i : cost) {
		cin >> i;
		ans += i;
	}
	cin >> M;
	vector<int>w(1, 0);
	for (int i = 0; i < M; i++) {
		cin >> K;
		w.push_back(K);
	}
	for (int i = 1; i < M; i++) {
		if (w[i] <= w[i - 1]) {
			cout << "NO\n";
			return 0;
		}
	}
	map<int, int>converter;
	for (int i = 0; i <= M; i++) {
		converter[w[i]] = i;
	}
	int cnt = 1;
	for (int i = 0; i < N; i++) {
		if (v[i] == w[cnt])cnt++;
		if (cnt == M+1)break;
	}
	if (cnt < M+1) {
		cout << "NO\n";
		return 0;
	}
	map<int, long long int>minus;
	map<int, long long int>ret;
	for (int i = 0; i <= w.size(); i++)ret[i]=MOD*MOD;
	ret[w.size()] = ans;
	for (int i = N - 1; i >= 0; i--) {
		auto it = lower_bound(w.begin(), w.end(), v[i]) - w.begin();
		if (converter.find(v[i]) == converter.end()) {
			minus[it - 1] += max(0LL,cost[i]);
			continue;
		}
		ret[it] = min(ret[it], ret[it + 1] - minus[it - 1]-cost[i]);
		minus[it - 1] += max(cost[i], 0LL);
	}
	cout << "YES\n";
	cout << ret[1] << endl;
}