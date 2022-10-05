#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, d[100005] = {};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for (int i = 0, u, v; i < n - 1; i++) {
		cin >> u >> v;
		d[u]++, d[v]++;
	}
	for (int i = 1; i <= n; i++)
		if (d[i] == 2) finish("NO");
	finish("YES");
}