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

	cin >> K;
	while (K--) {
		string s;
		cin >> s;
		N = s.size();
		vector<int>sum(N + 1);
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i];
			if (s[i] == '+')sum[i + 1]++;
			else sum[i + 1]--;
		}
		map<int, int>mp;
		for (int i = N; i > 0; i--) {
			mp[sum[i]] = i;
		}
		long long int ans = N;
		for (auto i : mp) {
			if (i.first >= 0)break;
			ans += i.second;
		}
		cout << ans << endl;
	}
}