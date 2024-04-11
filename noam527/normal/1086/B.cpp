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

int n;
ldb s;
vector<int> d;

int main() {
	fast;
	cin >> n >> s;
	d.resize(n);
	if (n == 2) finish(s);
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		d[u - 1]++;
		d[v - 1]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) if (d[i] == 1) cnt++;
	cout.precision(9);
	cout << 2 * s / cnt << endl;
}