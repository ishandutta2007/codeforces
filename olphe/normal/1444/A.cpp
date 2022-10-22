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

	cin >> T;
	while (T--) {
		cin >> N >> M;
		if (N%M) {
			cout << N << endl;
		}
		else {
			K = N;
			long long int ans = 1;
			map<int, long long int>mp;
			for (int i = 2; i*i <= M; i++) {
				if (M%i == 0) {
					mp[i] = 1;
					while (M%i == 0) {
						mp[i] *= i;
						M /= i;
					}
				}
			}
			if (M > 1) {
				mp[M]=M;
			}
			map<int, long long int>box;
			for (auto i : mp) {
				if (K%i.first == 0) {
					box[i.first] = 1;
					while (K%i.first == 0) {
						K /= i.first;
						box[i.first] *= i.first;
					}
				}
			}
			for (auto i : mp) {
				ans = max(ans, N / (box[i.first] / i.second) / i.first);
			}
			cout << ans << endl;
		}
	}
}