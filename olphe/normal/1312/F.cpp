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
constexpr long double EPS = 1e-12;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	/*
	vector<int>v(3);
	for (auto &i : v)cin >> i;
	vector<vector<int>>grundy(301, vector<int>(3));
	for (int i = 1; i < 301; i++) {
		for (int j = 0; j < 3; j++) {
			set<int>s;
			for (int k = 0; k < 3; k++) {
				if (j&&j == k)continue;
				s.insert(grundy[max(0, i - v[j])][k]);
			}
			for (auto k : s) {
				if (grundy[i][j] == k)grundy[i][j]++;
			}
			cout << i << " " << j << " " << grundy[i][j] << endl;
		}
	}
	*/

	vector<vector<vector<vector<vector<int>>>>>grundy(6, vector<vector<vector<vector<int>>>>(6, vector<vector<vector<int>>>(6, vector<vector<int>>(301, vector<int>(3)))));
	vector<vector<vector<int>>>md(6, vector<vector<int>>(6, vector<int>(6)));
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			for (int k = 1; k <= 5; k++) {
				for (int l = 1; l < 301; l++) {
					vector<int>v({ i,j,k });
					for (int m = 0; m < 3; m++) {
						set<int>st;
						for (int n = 0; n < 3; n++) {
							if (m&&m == n)continue;
							st.insert(grundy[i][j][k][max(0, l - v[n])][n]);
						}
						for (auto n : st) {
							if (grundy[i][j][k][l][m] == n)grundy[i][j][k][l][m]++;
						}
					}
				}
				for (int l = 1; l <= 300; l++) {
					bool flag = true;
					for (int m = l+100; m <= 300; m++) {
						flag &= grundy[i][j][k][m] == grundy[i][j][k][m - l];
					}
					if (flag) {
						md[i][j][k] = l;
						break;
					}
				}
			}
		}
	}

	int K;
	cin >> K;
	while (K--) {
		int M, a, b, c;
		cin >> M >> a >> b >> c;
	//	cout << md[a][b][c] << endl;
		int x = 0;
		vector<long long int>v(M);
		for (auto &i : v) {
			cin >> i;
			if (i <= 100)x ^= grundy[a][b][c][i][0];
			else {
				int id = i % md[a][b][c];
				while (id < 100)id += md[a][b][c];
				x ^= grundy[a][b][c][id][0];
			}
		}
		if (x == 0) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
//		cout << "x " << x << endl;
		for (auto i : v) {
			if (i <= 100) {
				int bef = grundy[a][b][c][i][0];
	//			cout << "bef " << bef << endl;
				int nx = grundy[a][b][c][max(0LL, (i - a))][0];
	//			cout << "nx " << nx << endl;
				if ((x^bef^nx) == 0)ans++;
				nx = grundy[a][b][c][max(0LL, (i - b))][1];
				if ((x^bef^nx) == 0)ans++;
				nx = grundy[a][b][c][max(0LL, (i - c))][2];
				if ((x^bef^nx) == 0)ans++;
			}
			else {
				int id = i % md[a][b][c];
				while (id < 100)id += md[a][b][c];
				int bef= grundy[a][b][c][id][0];
				id = (i - a) % md[a][b][c];
				while (id < 100)id += md[a][b][c];
				int nx = grundy[a][b][c][id][0];
				if ((x^bef^nx) == 0)ans++;

				id = (i - b) % md[a][b][c];
				while (id < 100)id += md[a][b][c];
				nx = grundy[a][b][c][id][1];
				if ((x^bef^nx) == 0)ans++;
				
				id = (i - c) % md[a][b][c];
				while (id < 100)id += md[a][b][c];
				nx = grundy[a][b][c][id][2];
				if ((x^bef^nx) == 0)ans++;
			}
		}
		cout << ans << endl;
	}
}