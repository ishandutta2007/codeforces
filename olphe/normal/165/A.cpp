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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<int, int>>v(N);
	vector<int>d(2001,MOD);
	vector<int>u(2001,-MOD);
	vector<int>l(2001,MOD);
	vector<int>r(2001,-MOD);
	for (auto &i : v) {
		cin >> i.first >> i.second;
		i.first += 1000, i.second += 1000;
		l[i.first] = min(l[i.first], i.second);
		r[i.first] = max(r[i.first], i.second);
		u[i.second] = max(u[i.second], i.first);
		d[i.second] = min(d[i.second], i.first);
	}
	int ans = 0;
	for (auto i : v) {
		if (l[i.first]<i.second&&r[i.first]>i.second&&d[i.second]<i.first&&u[i.second]>i.first)ans++;
	}
	cout << ans << endl;
}