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
#include <bitset>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;


void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int z = 0, d = 0;
	foru(i, 0, n)z += (s[i] == '0');
	foru(i, 0, n / 2)d += (s[i] != s[n - 1 - i]);
	int awin = 0;
	if (d != 0) {
		if (d > 1) {
			awin += (d - 1);
			z -= (d - 1);
			d = 1;
		}
		//option 1 = alice reverses
		int o1 = awin, z1 = z;
		o1++;
		z1--;
		if (z1 == 0) {
			z1 += 0;
		}
		else if (z1 % 2 == 0) {
			o1 -= 2;
		}
		else {
			if (z1 == 1)o1 -= 1;
			else o1 += 1;
		}
		//option 2 = alice takes
		int o2 = awin, z2 = z;
		o2--;
		z2--;
		if (z2 == 0) {
			z2 += 0;
		}
		else if (z2 % 2 == 0) {
			o1 += 2;
		}
		else {
			if (z2 == 1)o2 += 1;
			else o2 -= 1;
		}
		awin = max(o1, o2);
	}
	//alice turn
	else {
		if (z == 0) {
			z += 0;
		}
		else if (z % 2 == 0) {
			awin -= 2;
		}
		else {
			if (z == 1)awin -= 1;
			else awin += 1;
		}
	}
	if (awin > 0)cout << "ALICE\n";
	else if (awin < 0)cout << "BOB\n";
	else cout << "DRAW\n";
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}