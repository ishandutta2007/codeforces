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

int n, x;

int main() {
	fast;
	cin >> n;
	int mx = -1;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (mx + 1 == x) {
			mx++;
		}
		else if (mx + 1 < x) {
			finish(i + 1);
		}
	}
	finish(-1);
}