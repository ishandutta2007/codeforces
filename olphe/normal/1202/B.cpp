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
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<vector<int>>ans(10, vector<int>(10));
	vector<vector<vector<int>>>step(10, vector<vector<int>>(10, vector<int>(10, MOD)));
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			step[i][j][i] = 1;
			step[i][j][j] = 1;
			queue<int>Q;
			Q.push(i);
			Q.push(j);
			while (!Q.empty()) {
				int cn = Q.front();
				Q.pop();
				if (step[i][j][(cn + i) % 10] > step[i][j][cn]+1) {
					step[i][j][(cn + i) % 10] = step[i][j][cn] + 1;
					Q.push((cn + i) % 10);
				}
				if (step[i][j][(cn + j) % 10] > step[i][j][cn] + 1) {
					step[i][j][(cn + j) % 10] = step[i][j][cn] + 1;
					Q.push((cn + j) % 10);
				}
			}
			for (int k = 1; k < s.size(); k++) {
				int num = 10 + s[k] - s[k - 1];
				num %= 10;
				ans[i][j] += step[i][j][num];
				ans[i][j] = min(ans[i][j], MOD);
			}
			if (ans[i][j] == MOD)ans[i][j] = -1;
			else ans[i][j] -= s.size() - 1;
		}
	}
	for (auto i : ans) {
		for (auto j : i)cout << j << " ";
		cout << endl;
	}
}