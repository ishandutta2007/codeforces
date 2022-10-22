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
#include "complex"
using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	long double l = 0, r = MOD;
	for (int i = 0; i < 100; i++) {
		long double mid = (r + l) / 2;
		long double box = mid + K;
		long double angle = acos((box*box * 2 - mid * mid * 4) / (box*box * 2));
		if (angle*N <= 3.1415926535 * 2)l = mid;
		else r = mid;
	}
	cout <<setprecision(20)<< l << endl;
	return 0;
}