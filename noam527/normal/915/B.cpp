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
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, p, l, r;

int main() {
	fast;
	cin >> n >> p >> l >> r;
	if (l == 1) {
		if (r >= n) finish(0);
		finish(abs(p - r) + 1);
	}
	if (r >= n) finish(abs(p - l) + 1);
	if (abs(p - l) < abs(p - r)) finish(abs(p - l) + 1 + r - l + 1);
	finish(abs(p - r) + 1 + r - l + 1);
}