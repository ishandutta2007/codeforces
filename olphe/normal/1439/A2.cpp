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

	cin >> T;
	while (T--) {
		cin >> H >> W;
		vector<string>s(H);
		for (auto &i : s) {
			cin >> i;
			for (auto &j : i)j -= '0';
		}
		vector<vector<int>>ans;
		for (int i = 0; i + 2 < H; i++) {
			for (int j = 0; j + 2 < W; j++) {
				if (s[i][j] == 1) {
					s[i][j] ^= 1;
					s[i + 1][j] ^= 1;
					s[i][j + 1] ^= 1;
					vector<int>add;
					add.push_back(i);
					add.push_back(j);
					add.push_back(i + 1);
					add.push_back(j);
					add.push_back(i);
					add.push_back(j + 1);
					ans.push_back(add);
				}
			}
		}
		for (int i = 0; i + 2 < H; i++) {
			if (s[i][W - 2] || s[i][W - 1]) {
				vector<int>add;
				if (s[i][W - 2]) {
					s[i][W - 2] ^= 1;
					add.push_back(i);
					add.push_back(W - 2);
				}
				if (s[i][W - 1]) {
					s[i][W - 1] ^= 1;
					add.push_back(i);
					add.push_back(W - 1);
				}
				s[i + 1][W - 2] ^= 1;
				add.push_back(i + 1);
				add.push_back(W - 2);
				if (add.size() < 6) {
					s[i + 1][W - 1] ^= 1;
					add.push_back(i + 1);
					add.push_back(W - 1);
				}
				ans.push_back(add);
			}
		}
		for (int j = 0; j + 2 < W; j++) {
			if (s[H - 2][j] || s[H - 1][j]) {
				vector<int>add;
				if (s[H - 2][j]) {
					s[H - 2][j] ^= 1;
					add.push_back(H - 2);
					add.push_back(j);
				}
				if (s[H - 1][j]) {
					s[H - 1][j] ^= 1;
					add.push_back(H - 1);
					add.push_back(j);
				}
				s[H - 2][j + 1] ^= 1;
				add.push_back(H - 2);
				add.push_back(j + 1);
				if (add.size() < 6) {
					s[H - 1][j + 1] ^= 1;
					add.push_back(H - 1);
					add.push_back(j + 1);
				}
				ans.push_back(add);
			}
		}
		while (1) {
			int num = 0;
			vector<pair<int, int>>on;
			vector<pair<int, int>>off;
			for (int i = H - 2; i < H; i++) {
				for (int j = W - 2; j < W; j++) {
					if (s[i][j])on.push_back({ i, j });
					else off.push_back({ i, j });
				}
			}
			num = on.size();
			if (num == 0)break;
			vector<int>add;
			if (num == 1) {
				s[on[0].first][on[0].second] ^= 1;
				add.push_back(on[0].first);
				add.push_back(on[0].second);
				for (int k = 0; k < 2; k++) {
					s[off[k].first][off[k].second] ^= 1;
					add.push_back(off[k].first);
					add.push_back(off[k].second);
				}
			}
			else if (num == 2) {
				s[on[0].first][on[0].second] ^= 1;
				add.push_back(on[0].first);
				add.push_back(on[0].second);
				for (int k = 0; k < 2; k++) {
					s[off[k].first][off[k].second] ^= 1;
					add.push_back(off[k].first);
					add.push_back(off[k].second);
				}
			}
			else if (num == 3) {
				for (int k = 0; k < 3; k++) {
					s[on[k].first][on[k].second] ^= 1;
					add.push_back(on[k].first);
					add.push_back(on[k].second);
				}				   
			}
			else if (num == 4) {
				for (int k = 0; k < 3; k++) {
					s[on[k].first][on[k].second] ^= 1;
					add.push_back(on[k].first);
					add.push_back(on[k].second);
				}
			}
			ans.push_back(add);
		}
		cout << ans.size() << endl;
		for (auto i : ans) {
			for (auto j : i)cout << j + 1 << " ";
			cout << endl;
		}
	}

}