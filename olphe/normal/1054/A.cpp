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

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	N = abs(a - b)*d;
	M = abs(a - c)*e;
	M += abs(b - a)*e;
	M += 3 * f;
	if (N >= M)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}