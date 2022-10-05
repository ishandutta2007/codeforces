#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, x, a[1005] = {};

int main() {
	fast;
	cin >> n;
	while (n--) cin >> x, a[x]++;
	for (int i = 0; i < 1003; i++)
		if (a[i] && a[i + 1] && a[i + 2]) finish("YES");
	finish("NO");
}