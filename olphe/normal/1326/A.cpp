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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int N;
	cin >> N;
	while (N--) {
		int K;
		cin >> K;
		if (K == 1)cout << -1 << "\n";
		else {
			for (int i = 1; i < K; i++)cout << 9;
			cout << 8 << "\n";
		}
	}
}