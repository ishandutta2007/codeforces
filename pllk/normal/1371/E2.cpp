#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int n, p;
ll a[101010];

int check(ll x) {
	int j = 1;
	int c = 0;
	int t = 1;
	for (int i = 0; i < n; i++) {
		while (j <= n && a[j] <= x+i) {c++; j++;}
		if (c == 0) {t = 0; break;}
		if (c >= p) {t = 2; break;}
		c--;
	}
	return t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> p;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	ll x1 = 0, x2 = 0;
	for (ll b = 1e9; b >= 1; b /= 2) {
		while (check(x1+b) == 0) x1 += b;
		while (check(x2+b) <= 1) x2 += b;
	}
	cout << x2-x1 << "\n";
	for (ll x = x1+1; x <= x2; x++) cout << x << " ";
	cout << "\n";
}