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

	cin >> N >> M;
	vector<int>v(M);
	for (auto &i : v)cin >> i;
	if (accumulate(v.begin(), v.end(), 0LL) < N) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < M; i++) {
		if (N - v[i] < i) {
			cout << -1 << endl;
			return 0;
		}
	}
	vector<int>ans;
	R = 0;
	for (int i = M - 1; i >= 0; i--) {
		int box = min(R + 1, N - i - v[i] + 1);
		ans.push_back(box);
		R = box+v[i]-1;
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans)cout << i << " ";
	cout << endl;
}