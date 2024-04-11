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
		vector<int>v(N+1);
		vector<vector<int>>p(201);
		vector<vector<int>>sum(201, vector<int>(N + 1));
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
			p[v[i]].push_back(i);
			sum[v[i]][i]++;
			for (int j = 0; j <= 200; j++) {
				sum[j][i] += sum[j][i - 1];
			}
		}
		int ans = 0;
		for (int i = 1; i <= 200; i++) {
			ans = max(ans, (int)p[i].size());
			for (int j = 1; j <= p[i].size() / 2; j++) {
				int l = p[i][j - 1];
				int r = p[i][p[i].size() - j] - 1;
				for (int k = 0; k <= 200; k++) {
					ans = max(ans, j * 2 + (sum[k][r] - sum[k][l]));
				}
			}
		}
		cout << ans << endl;
	}
}