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
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;



int main() {
	fast;
	ll n, k;
	cin >> n >> k;
	ll crtot = (n * (n + 1)) / 2;
	if (k < crtot){
		cout << -1;
		return 0;
	}
	vector<int> vals(n + 1, 0);
	for (int i = n; 2 * i > n + 1 && crtot < k; i--) {
		int lhs = n - i + 1;
		if (i - lhs + crtot > k) lhs = i - (k - crtot);
		crtot += (i - lhs);
		vals[i] = 1;
		vals[lhs] = -1;
	}
	vector<int> p1(n), p2(n);
	int oi = 0, ni = 0, neui = n - 1;
	for (int i = n; i >= 1; i--) {
		switch (vals[i]) {
		case 1:
			p1[oi++] = i;
			p2[oi++] = i;
			break;
		case -1:
			p2[ni++] = i;
			p1[ni++] = i;
			break;
		case 0:
			p1[neui] = i;
			p2[neui] = i;
			neui--;
			break;
		}
	}
	cout << crtot << '\n';
	for (int x : p1)cout << x << ' ';
	cout << '\n';
	for (int x : p2)cout << x << ' ';
	cout << '\n';
	return 0;
}