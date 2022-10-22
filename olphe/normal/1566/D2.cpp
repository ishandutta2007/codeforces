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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<int>v(N * M);
	int ans = 0;
	map<int, queue<int>>mp;
	for (int i = 0; i < N * M; i++) {
		cin >> v[i];
		mp[v[i]].push(i);
	}
	sort(v.begin(), v.end());
	vector<vector<int>>ret(N, vector<int>(M));
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int ed = j + 1;
			while (ed < M && v[i * M + ed] == v[i * M + j]) {
				ed++;
			}
			for (int k = i * M + ed - 1; k >= i * M + j; k--) {
				ret[i][k-i*M] = mp[v[i * M + j]].front();
				mp[v[k]].pop();
			}
			j = ed - 1;
		}
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < j; k++) {
				ans += ret[i][j] > ret[i][k];
			}
		}
	}
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}