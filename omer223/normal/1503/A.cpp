#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

void solve() {
	int n;
	string s;
	cin >> n >> s;
	int z = 0, o;
	for (char c : s) {
		if (c == '0')z++;
	}
	if (z & 1) {
		cout << "NO\n";
		return;
	}
	o = n - z;
	vector<char> a(n), b(n);
	int onecnt = 0, zcnt = 0;
	int ca = 0, cb = 0;
	foru(i, 0, n) {
		if (s[i] == '1') {
			onecnt++;
			if (onecnt <= o / 2)a[i] = b[i] = '(';
			else a[i] = b[i] = ')';
		}
		else {
			zcnt++;
			if (zcnt & 1)a[i] = '(', b[i] = ')';
			else a[i] = ')', b[i] = '(';
		}
		if (a[i] == '(')ca++;
		else ca--;
		if (b[i] == '(')cb++;
		else cb--;
		if (ca < 0 || cb < 0) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	foru(i, 0, n)cout << a[i];
	cout << '\n';
	foru(i, 0, n)cout << b[i];
	cout << '\n';
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}