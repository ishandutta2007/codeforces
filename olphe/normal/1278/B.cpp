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
	vector<long long int>sum(100001);
	for (int i = 1; i <= 100000; i++) {
		sum[i] = sum[i - 1] + i;
	}
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		if (L > R)swap(L, R);
		for (int j = 0; j <= 100000; j++) {
			if (sum[j] >= R - L && sum[j] % 2 == (R - L) % 2) {
				cout << j << endl;
				break;
			}
		}
	}
}