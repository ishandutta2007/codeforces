#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n;

int gcd(int x, int y) {
	return y == 0 ? x : gcd(y, x % y);
}

int main() {
	fast;
	cin >> n;
	int a = (n - 1) / 2, b = n - a;
	while (a >= 0 && gcd(a, b) != 1) a--, b++;
	cout << a << " " << b << endl;
}