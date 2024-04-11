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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	long long int ans = 0;
	map<long long int, int>mp;
	mp[0] = 0;
	long long int sum = 0;
	vector<long long int>l(N,-1);
	for (int i = 0; i < N; i++) {
		sum += v[i];
		if (mp.find(sum) == mp.end())mp[sum] = i+1;
		else {
			l[i] = mp[sum];
			mp[sum] = i+1;
		}
		if (i)l[i] = max(l[i], l[i - 1]);
		ans += i - l[i];
	}
	cout << ans << endl;
}