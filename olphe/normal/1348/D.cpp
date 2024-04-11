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
		L = 1, R = 1;
		vector<int>ans;
		while (L < N) {
			if (L + R * 4 <= N) {
				ans.push_back(R);
			}
			else if (L + R * 2 >= N) {
				ans.push_back(min(R, N - L - R * 1));
			}
			else {
				ans.push_back(min(R, max(0LL, (N - L) / 2 - R)));
			}
			R += ans.back();
			L += R;
		}
		cout << ans.size() << endl;
		for (auto i : ans)cout << i << " ";
		cout << endl;
	}
}