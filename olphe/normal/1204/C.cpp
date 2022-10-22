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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>v(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '0')v[i][j] = MOD;
			else v[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++)v[i][i] = 0;
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
			}
		}
	}
	cin >> M;
	vector<int>w(M);
	for (auto &i : w)cin >> i;
	vector<int>ans;
	ans.push_back(w[0]);
	int bef = 0;
	int lst = 1;
	for (int i = 2; i < M; i++) {
		//cout << bef << " " << lst << endl;
		//cout << w[bef] << " " << w[i] << endl;
		//cout << v[w[bef]-1][w[lst]-1] + v[w[lst]-1][w[i]-1] << " " << v[w[bef]-1][w[i]-1] << endl;
		if (v[w[bef]-1][w[lst]-1] + v[w[lst]-1][w[i]-1] != v[w[bef]-1][w[i]-1]) {
			ans.push_back(w[lst]);
			bef = lst;
		}
		lst = i;
	}
	ans.push_back(w.back());
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
}