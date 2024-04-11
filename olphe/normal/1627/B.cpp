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

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> H >> W;
	vector<int>ans;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int dis = 0;
			dis = max(dis, i + j);
			dis = max(dis, (int)H - 1 - i + j);
			dis = max(dis, (int)H - 1 - i + (int)W - 1 - j);
			dis = max(dis, i + (int)W - 1 - j);
			ans.push_back(dis);
		}
	}
	sort(ans.begin(), ans.end());
	for (auto i : ans)cout << i << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}