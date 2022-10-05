#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<ll> a;
ll s = 0;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, s += i;
	sort(a.begin(), a.end());
	int cnt = 0;
	for (int i = 1; i < n; i++)
		if (a[i - 1] == a[i]) cnt++;
	bool something = false;
	if (n >= 2 && a[1] == 0) something = true;
	if (cnt > 1 || something) {
		cout << "cslnb\n";
		return 0;
	}
	for (int i = 2; i < n; i++)
		if (a[i - 1] == a[i] && a[i - 2] + 1 == a[i - 1]) {
			cout << "cslnb\n";
			return 0;
		}
	a[0] = 0;
	for (int i = 1; i < n; i++)
		a[i] = min(a[i], 1 + a[i - 1]);
	ll s2 = 0;
	for (auto &i : a) s2 += i;
	if (s % 2 != s2 % 2) cout << "sjfnb\n";
	else cout << "cslnb\n";
}