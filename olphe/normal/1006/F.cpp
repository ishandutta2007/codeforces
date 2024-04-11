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
#include "ctime"
#include "complex"
using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> H >> W >> K;
	vector<vector<long long int>>v(H, vector<long long int>(W));
	for (auto &i : v) {
		for (auto &j : i)cin >> j;
	}
	if (H == 1 && W == 1 && K == v[0][0]) {
		cout << 1 << endl;
		return 0;
	}
	if (H == 1 && W == 1) {
		cout << 0 << endl;
		return 0;
	}
	vector<map<long long int, long long int>>mh(H);
	vector<map<long long int, long long int>>mw(H);
	for (int i = 0; i < 1 << (H - 1); i++) {
		long long int box = v.front().front();
		int y = 0, x = 0;
		for (int j = 0; j < H - 1; j++) {
			if ((i >> j) & 1)y++;
			else x++;
			if (x >= W)break;
			if (y >= H)break;
			box ^= v[y][x];
		}
		if (x < W&&y < H) {
			mh[y][box]++;
		}
	}
	if (W == 1) {
		mw[H-1][0] = 1;
	}
	for (int i = 0; i < 1 << (W - 2); i++) {
		long long int box = v.back().back();
		int y = H - 1, x = W - 1;
		for (int j = 0; j < W - 2; j++) {
			if ((i >> j) & 1)y--;
			else x--;
			if (x < 0)break;
			if (y < 0)break;
			box ^= v[y][x];
		}
		if (x >= 0 && y >= 0)mw[y][box]++;
	}
	long long int ans = 0;
	for (int j = 0; j < H; j++) {
		for (auto i : mh[j]) {
			ans += i.second*mw[j][i.first^K];
			if (j + 1 < H)ans += i.second*mw[j + 1][i.first^K];
		}
	}
	cout << ans << endl;
	return 0;
}