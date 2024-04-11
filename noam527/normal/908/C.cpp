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

ldb n, r, a[1000], b[1000];

ldb calc(int i) {
	ldb mx = r / 2;
	for (int x = i - 1; x >= 0; x--) {
		mx = max(mx, b[x] + sqrt(r * r - (a[i] - a[x]) * (a[i] - a[x])));
	}
	return mx;
}

int main() {
	fast;
	cout.precision(10);
	cin >> n >> r;
	for (int i = 0; i < n; i++) cin >> a[i];
	b[0] = r;
	r *= 2;
	for (int i = 1; i < n; i++) b[i] = calc(i);
	for (int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
}