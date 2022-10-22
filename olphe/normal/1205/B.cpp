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
#include "functional"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>w;
	for (auto i : v)if (i)w.push_back(i);
	N = w.size();
	v = w;
	if (N > 130) {
		cout << 3 << endl;
		return 0;
	}
	int ans = 1000;
	for (int i = 0; i < N; i++) {
		vector<vector<int>>dis(N, vector<int>(N, MOD));
		queue<pair<int, int>>Q;
		for (int j = 0; j < N; j++) {
			if (i == j)continue;
			if (v[i] & v[j]) {
				dis[i][j] = 1;
				Q.push({ i,j });
			}
		}
		while (!Q.empty()) {
			int pn = Q.front().first;
			int cn = Q.front().second;
			//cout << pn << " " << cn << endl;
			Q.pop();
			for (int j = 0; j < N; j++) {
				if (j == pn || j == cn)continue;
				if (v[cn] & v[j]) {
					if (dis[cn][j] > dis[pn][cn] + 1) {
						dis[cn][j] = dis[pn][cn] + 1;
						Q.push({ cn,j });
					}
				}
			}
		}
		for (int j = 0; j < N; j++) {
			ans = min(ans, dis[j][i]);
		}
	}
	if (ans == 1000)ans = -1;
	cout << ans << endl;
}