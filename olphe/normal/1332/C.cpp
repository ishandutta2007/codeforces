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

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> M;
	while (M--) {
		cin >> N >> K;
		string s;
		cin >> s;
		vector<vector<int>>v((K + 1) / 2, vector<int>(26));
		for (int i = 0; i < N; i++) {
			int j = i % K;
			j = min(j, (int)K - 1 - j);
			v[j][s[i] - 'a']++;
		}
		int ans = 0;
		for (auto i : v) {
			ans += accumulate(i.begin(), i.end(), 0) - *max_element(i.begin(), i.end());
		}
		cout << ans << endl;
	}
}