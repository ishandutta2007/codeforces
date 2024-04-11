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

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W;
	if (H == 1 && W == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<string>s(H);
	for (int i = 0; i < H; i++)cin >> s[i];
	vector<vector<int>>w(H, vector<int>(W));
	vector<vector<int>>h(H, vector<int>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			h[i][j] = w[i][j] = s[i][j] == 'R';
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = W - 2; j >= 0; j--)w[i][j] += w[i][j + 1];
	}
	for (int i = H - 2; i >= 0; i--) {
		for (int j = 0; j < W; j++)h[i][j] += h[i + 1][j];
	}
	vector<vector<long long int>>wdp(H+1, vector<long long int>(W+1));
	vector<vector<long long int>>hdp(H+1, vector<long long int>(W+1));
	hdp[0][0] = 1;
	wdp[0][0] = 1;
	vector<vector<long long int>>wsum(H+1, vector<long long int>(W+1));
	vector<vector<long long int>>hsum(H+1, vector<long long int>(W+1));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (i){
				hsum[i][j] += hsum[i - 1][j];
				hdp[i][j] = hsum[i][j];
				hdp[i][j] %= MOD;
			}
			if (j) {
				wsum[i][j] += wsum[i][j - 1];
				wdp[i][j] = wsum[i][j];
				wdp[i][j] %= MOD;
			}
			if (j + 1 < W) {
				wsum[i][j + 1] += hdp[i][j];
				wsum[i][W - w[i][j + 1]] -= hdp[i][j];
			}
			if (i + 1 < H) {
				hsum[i + 1][j] += wdp[i][j];
				hsum[H - h[i + 1][j]][j] -= wdp[i][j];
			}
		}
	}
	cout << (hdp[H - 1][W - 1] + wdp[H - 1][W - 1]) % MOD << endl;
}