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

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>v(N * 2 + 1, vector<int>(N * 2 + 1));
	for (int i = 0; i < N*2+1; i++) {
		for (int j = 0; j < N*2+1; j++) {
			v[i][j] = N - abs(i - N) - abs(j - N);
		}
	}
	for (int i = 0; i < N*2+1; i++) {
		for (int j = 0; j < N*2+1; j++) {
			if (j)cout << " ";
			if (v[i][j] >= 0)cout << v[i][j];
			else cout << " ";
			if (v[i][j] == 0 && j >= N)break;
		}
		cout << endl;
	}
}