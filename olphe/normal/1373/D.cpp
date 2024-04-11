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
		cin >> N;
		vector<long long int>v(N + 1);
		long long int ans = 0;
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
			if (i & 1)ans += v[i];
		}
		long long int add = 0;
		long long int cnt = 0;
		long long int m = 0;
		for (int i = 1; i <= N; i++) {
			if (i & 1)cnt -= v[i];
			else {
				cnt+=v[i];
				add = max(add, cnt - m);
				m = min(m, cnt);
			}
		}
		m = 0;
		cnt = 0;
		for (int i = 2; i <= N; i++) {
			if (i & 1) {
				cnt -= v[i];
				add = max(add, cnt - m);
				m = min(m, cnt);
			}
			else {
				cnt += v[i];
			}
		}
		cout << ans + add << endl;
	}
}