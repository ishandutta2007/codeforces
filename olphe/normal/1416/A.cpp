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
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		vector<vector<int>>box(N + 1, vector<int>(1, -1));
		for (int i = 0; i < N; i++) {
			box[v[i]].push_back(i);
		}
		for (auto &i : box)i.push_back(N);
		vector<int>ans(N + 1, MOD);
		for (int i = 1; i <= N; i++) {
			int cnt = 0;
			for (int j = 1; j < box[i].size(); j++) {
				cnt = max(cnt, box[i][j] - box[i][j - 1]);
			}
			while (cnt <= N) {
				if (ans[cnt] > i) {
					ans[cnt] = i;
					cnt++;
				}
				else break;
			}
		}
		for (auto &i : ans)if (i == MOD)i = -1;
		for (int i = 1; i <= N; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}