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

long long int power(long long int x, long long int n, long long int M) {
	long long int ret = 1;
	long long int by = x;
	while (n) {
		if (n & 1) {
			ret *= by;
			ret %= M;
		}
		by *= by;
		by %= M;
		n >>= 1;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		if (M == 1) {
			cout << (N & 1) << endl;
			continue;
		}
		sort(v.rbegin(), v.rend());
		int num = 0;
		long long int ans = 0;
		map<int, long long int>dig;
		bool ov = false;
		for (auto i : v) {
			if (num == 0) {
				ans += power(M, i, MOD);
				ans %= MOD;
				num++;
				dig[i]++;
			}
			else {
				if (ov) {
					ans += MOD - power(M, i, MOD);
					ans %= MOD;
				}
				else if (dig.find(i) != dig.end()) {
					dig[i]--;
					ans += MOD - power(M, i, MOD);
					ans %= MOD;
					if (dig[i] == 0) {
						dig.erase(i);
						num--;
					}
				}
				else {
					auto it = dig.upper_bound(i);
					while (it->first != i && !ov) {
						if (dig.find(it->first - 1) == dig.end())num++;
						dig[it->first - 1] += M * it->second;
						if (dig[it->first - 1] > 1000000) {
							ov = true;
							break;
						}
						dig.erase(it->first);
						num--;
						it = dig.lower_bound(i);
					}
					if (ov) {
						ans += MOD - power(M, i, MOD);
						ans %= MOD;
					}
					else {
						dig[i]--;
						ans += MOD - power(M, i, MOD);
						ans %= MOD;
						if (dig[i] == 0) {
							num--;
							dig.erase(i);
						}
					}
				}
			}
		//	cout << i << " " << ans << endl;
		}
	//	cout << ov << endl;
		cout << ans << endl;
	}
}