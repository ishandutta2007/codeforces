#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <math.h>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll myceil(ll a, ll b) {
	if (!b)return 1e15;
	return a / b + (a % b != 0);
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll sqr = sqrtl(n), mn = 1e15;
		for (int d = -3; d <= 3; d++) {
			if (sqr + d < 0)continue;
			ll amt = (sqr + d - 1) + myceil(n, sqr + d + 1);
			if (amt < mn) {
				mn = amt;
			}
		}
		cout << mn << endl;
	}
	return 0;
}