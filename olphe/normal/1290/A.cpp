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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		cin >> N >> M >> K;
		K = min(K, M - 1);
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>w;
		for (int i = N - M; i < N; i++) {
			w.push_back(max(v[i], v[i - N + M]));
		}
		int ret = 0;
		for (int i = 0; i + M - K - 1 < w.size(); i++) {
			int box = MOD;
			for (int j = 0; j < M - K; j++) {
				box = min(box, w[i+j]);
			}
			ret = max(ret, box);
		}
		cout << ret << endl;
	}
	return 0;
}