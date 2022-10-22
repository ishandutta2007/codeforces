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
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>ans;
		long long int sum = 0;
		for (int i = 0; i < N; i++) {
			if (sum + v[i] <= M) {
				sum += v[i];
				ans.push_back(i);
			}
			else if (v[i] * 2 >= M && v[i] <= M) {
				ans.clear();
				ans.push_back(i);
				sum = v[i];
				break;
			}
		}
		if (sum * 2 >= M) {
			cout << ans.size() << endl;
			for (auto i : ans)cout << i + 1 << " ";
			cout << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
}