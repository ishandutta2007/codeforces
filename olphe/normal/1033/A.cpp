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

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int ax, ay, bx, by, cx, cy;
	cin >> bx >> by >> ax >> ay >> cx >> cy;
	int a, b, c, d;
	a = b = c = d = 0;
	if (ax < bx)a = 1;
	if (ay < by)b = 1;
	if (cx < bx)c = 1;
	if (cy < by)d = 1;
//	cout << a << b << c << d << endl;
	if (a == c && b == d) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	return 0;
}