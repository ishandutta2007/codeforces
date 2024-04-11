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
	if (N <= 2) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	if (N == 3) {
		cout << "2\n1 3\n";
		return 0;
	}
	cout << N << endl;
	for (int i = 2; i <= N; i += 2)cout << i << " ";
	for (int i = 1; i <= N; i += 2)cout << i << " ";
	cout << endl;
}