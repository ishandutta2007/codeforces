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

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<vector<int>>v(4);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> M;
		v[M].push_back(i + 1);
	}
	K = min({ v[1].size(), v[2].size(), v[3].size() });
	cout << K << endl;
	for (int i = 0; i < K; i++) {
		cout << v[1][i] << " " << v[2][i] << " " << v[3][i] << endl;
	}
	return 0;
}