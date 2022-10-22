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
constexpr long double EPS = 1e-12;

long long int N, M, K, L, R, H, W;
//int N, M, K, L, R, H, W;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int X, Y, L, D, R, U;
		cin >> X >> Y >> L >> D >> R >> U;
		L -= X, R -= X, D -= Y, U -= Y;
		if (L <= -a + b && -a + b <= R && D <= -c + d && -c + d <= U) {
			bool flag = true;
			if (a + b && L == R)flag = false;
			if (c + d && D == U)flag = false;
			if (flag)cout << "YES\n";
			else cout << "NO\n";
		}
		else cout << "NO\n";
	}
}