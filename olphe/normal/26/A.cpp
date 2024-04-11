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

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int ans = 0;
	for (int i = 6; i <= N; i++) {
		int box = i;
		int cnt = 0;
		for (int j = 2; j <= i; j++) {
			if (box%j == 0)cnt++;
			while (box%j == 0)box /= j;
		}
		ans += cnt == 2;
	}
	cout << ans << endl;
	return 0;
}