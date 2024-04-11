#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 9e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
map<int, int> m[2];
ll ans = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int i = 1; i < n; i++) a[i] ^= a[i - 1];
	m[1][0]++;
	for (int i = 0; i < n; i++) {
		ans += m[i & 1][a[i]];
		m[i & 1][a[i]]++;
	}
	finish(ans);
}