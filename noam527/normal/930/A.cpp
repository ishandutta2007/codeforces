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

int n, d[100010] = {}, c[100010] = {};

int main() {
	fast;
	cin >> n;
	d[1] = 1;
	for (int i = 2, x; i <= n; i++) {
		cin >> x;
		d[i] = 1 + d[x];
	}
	for (int i = 1; i <= n; i++) c[d[i]] ^= 1;
	int ans = 0;
	for (int i = 0; i < 100010; i++) ans += c[i];
	cout << ans << endl;
}