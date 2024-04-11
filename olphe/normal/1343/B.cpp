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
constexpr long double EPS = 1e-8;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while(K--){
		cin >> N;
		if (N % 4) {
			cout << "NO\n";
		}
		else {
			M = 0;
			cout << "YES\n";
			for (int i = 1; i <= N / 2; i++) {
				cout << i * 2 << " ";
				M += i * 2;
			}
			for (int i = 1; i < N / 2; i++) {
				cout << i * 2 - 1 << " ";
				M -= i * 2 - 1;
			}
			cout << M << endl;
		}
	}
}