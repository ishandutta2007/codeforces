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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	map<int, long long int>m;
	for (int i = 1; i <= M; i++) {
		m[(i*i) % M] += N / M;
	}
	for (int i = 1; i <= N % M; i++) {
		m[(i*i) % M] ++;
	}
	long long int ans = 0;
	for (int i = 1; i < M; i++) {
		ans += m[i] * m[M - i];
	}
	ans += m[0] * m[0];
	cout << ans << endl;
}