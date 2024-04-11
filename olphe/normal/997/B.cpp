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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ans[] = { 0,4,10,20,35,56,83,116,155,198,244,292,341,390 ,439 };
	cin >> N;
	if (N < 15)cout << ans[N] << endl;
	else cout << (N-14) * 49 + ans[14] << endl;
	return 0;
}