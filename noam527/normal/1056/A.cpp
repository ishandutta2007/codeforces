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
int a[200] = {};

int main() {
	fast;
	cin >> n;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x;
		while (x--) {
			cin >> y;
			a[y]++;
		}
	}
	for (int i = 0; i < 200; i++) if (a[i] == n) cout << i << " ";
}