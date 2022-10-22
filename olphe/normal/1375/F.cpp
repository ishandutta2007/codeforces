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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	cin >> N >> M >> K;
	cout << "First" << endl;
	long long int fst = 1000000000;
	cout << fst << endl;
	cin >> L;
	long long int snd = 0;
	if (L == 1) {
		N += fst;
		snd = 2 * N - M - K;
	}
	if (L == 2) {
		M += fst;
		snd = 2 * M - N - K;
	}
	if (L == 3) {
		K += fst;
		snd = 2 * K - N - M;
	}
	cout << snd << endl;
	cin >> L;
	if (L == 1) {
		N += snd;
	}
	if (L == 2) {
		M += snd;
	}
	if (L == 3) {
		K += snd;
	}
	cout << (max({ N,K,M }) - min({ N,K,M })) / 2 << endl;
	cin >> L;
	return 0;
}