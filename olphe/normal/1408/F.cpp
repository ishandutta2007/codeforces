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

	cin >> N;
	if (N <= 2) {
		cout << 0 << endl;
		return 0;
	}
	int num = 1;
	int turn = 0;
	while (num * 2 <= N) {
		num *= 2;
		turn++;
	}
	vector<pair<int, int>>ans;
	for (int loop = 0; loop < turn; loop++) {
		for (int i = 0; i < num; i++) {
			if ((i >> loop) & 1)continue;
			ans.push_back({ i,i + (1 << loop) });
		}
	}
	for (int loop = 0; loop < turn; loop++) {
		for (int i = 0; i < num; i++) {
			if ((i >> loop) & 1)continue;
			ans.push_back({ i + N - num,i + (1 << loop) + N - num });
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i.first + 1 << " " << i.second + 1 << endl;
}