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
	vector<vector<long long int>>by(N, vector<long long int>(N));
	for (int i = 1; i < N; i++) {
		for (int j = 0; j + 1 < N; j++) {
			by[i][j] = by[i - 1][j + 1] ^ 1;
		}
	}
	vector<vector<long long int>>field(N, vector<long long int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			field[i][j] = by[i][j] << (i + j);
		}
	}
	for (auto i : field) {
		for (auto j : i)cout << j << " ";
		cout << endl;
	}
	cin >> T;
	while (T--) {
		cin >> M;
		vector<pair<int, int>>ans;
		ans.push_back({ 0,0 });
		int cy = 0, cx = 0;
		while (cy + 1 < N || cx + 1 < N) {
			if (cy + 1 == N) {
				cx++;
			}
			else if (cx + 1 == N) {
				cy++;
			}
			else {
				if ((M >> (cx + cy + 1)) & 1) {
					if (by[cy][cx + 1]) {
						cx++;
					}
					else {
						cy++;
					}
				}
				else {
					if (by[cy][cx + 1]) {
						cy++;
					}
					else {
						cx++;
					}
				}
			}
			ans.push_back({ cy,cx });
		}
		for (auto i : ans)cout << i.first + 1 << " " << i.second + 1 << endl;
	}
}