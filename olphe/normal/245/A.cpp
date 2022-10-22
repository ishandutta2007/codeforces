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

//const long long int MOD = 1000000007;
const long long  int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K >> L >> R;
		if (K == 1) {
			H += L;
			M++;
		}
		else W += L;
	}
	if (M * 10 / 2 <= H)cout << "LIVE\n";
	else cout << "DEAD\n";
	if ((N - M) * 10 / 2 <= W)cout << "LIVE\n";
	else cout << "DEAD\n";
	return 0;
}