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

	cin >> M;
	while(M--){
		cin >> N >> K;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>ans(2 * K + 2);
		for (int i = 0; i < N / 2; i++) {
			ans[2] += 2;
			ans[min(v[i], v[N - 1 - i]) + 1]--;
			ans[v[i] + v[N - 1 - i]]--;
			ans[v[i] + v[N - 1 - i] + 1]++;
			ans[max(v[i], v[N - 1 - i]) + K + 1]++;
		}
		for (int i = 2; i <= K * 2; i++)ans[i] += ans[i - 1];
		ans[0] = ans[1] = MOD;
		ans.back() = MOD;
		cout << *min_element(ans.begin(), ans.end()) << endl;
	}
}