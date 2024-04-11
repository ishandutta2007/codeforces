#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n;
vector<int> a;
int ans = 0;

int main() {
	fast;
	cin >> n;
	a.resize(2 * n);
	for (auto &i : a) cin >> i;
	for (int i = 0; i < 2 * n; i += 2) {
		int at = i + 1;
		while (a[at] != a[i]) at++;
		while (at > i + 1) {
			swap(a[at - 1], a[at]);
			ans++;
			at--;
		}
	}
	finish(ans);
}