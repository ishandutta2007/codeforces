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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	vector<int>w(N);
	vector<long long int>by(N + 1, 1);
	for (int i = 2; i <= N; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
	}
	long long int ans = by[N];
	vector<pair<int, int>>u(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i] >> w[i];
		u[i] = { v[i],w[i] };
	}
	map<int, int>ma;
	for (auto i : v)ma[i]++;
	long long int minus = 1;
	for (auto i : ma) {
		minus *= by[i.second];
		minus %= MOD;
	}
	ans += MOD - minus;
	ans %= MOD;
	minus = 1;
	map<int, int>mb;
	for (auto i : w)mb[i]++;
	for (auto i : mb) {
		minus *= by[i.second];
		minus %= MOD;
	}
	ans += MOD - minus;
	ans %= MOD;
	sort(u.begin(), u.end());
	for (int i = 1; i < N; i++) {
		if (u[i].second < u[i - 1].second) {
			cout << ans << endl;
			return 0;
		}
	}
	map<pair<int, int>, int>mc;
	for (auto i : u)mc[i]++;
	minus = 1;
	for (auto i : mc) {
		minus *= by[i.second];
		minus %= MOD;
	}
	ans += minus;
	ans %= MOD;
	cout << ans << endl;
}