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
		cin >> N >> M;
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		string ans;
		int cnt = 0;
		if (s[0] == s[M - 1]) {
			ans.push_back(s[0]);
		}
		else {
			cout << s[M - 1] << endl;
			continue;
		}
		cnt = M;
		if (N == M) {
			cout << ans << endl;
			continue;
		}
		if (s[cnt] == s.back()) {
			ans += string((s.size() - M + M - 1) / M, s[cnt]);
			cout << ans << endl;
			continue;
		}
		ans += s.substr(M, s.size() - M);
		cout << ans << endl;

	}
}