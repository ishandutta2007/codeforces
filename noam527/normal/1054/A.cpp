#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int x, y, z, t1, t2, t3;

int main() {
	fast;
	cin >> x >> y >> z >> t1 >> t2 >> t3;

	int f, e;
	f = abs(x - y) * t1;
	e = abs(x - z) * t2 + t3 + t3 + abs(x - y) * t2 + t3;
	if (e <= f) finish("YES");
	finish("NO");
}