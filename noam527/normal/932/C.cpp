#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <random>
#include <fstream>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, a, b, c1 = 0, c2 = 0;

int main() {
	fast;
	cin >> n >> a >> b;
	while (n >= 0 && n % a != 0) {
		c2++;
		n -= b;
	}
	if (n < 0 || n % a != 0) finish(-1);
	c1 = n / a;

	int p = 1;
	while (c1--) {
		for (int x = 1; x <= a; x++) cout << p + x % a << " ";
		p += a;
	}
	while (c2--) {
		for (int x = 1; x <= b; x++) cout << p + x % b << " ";
		p += b;
	}

}