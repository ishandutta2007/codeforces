#define _CRT_SECURE_NO_WARNINGS
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
#include <bitset>
#include <queue>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll n, k, l;

inline ll calcWheel(ll x) {
	ll delt = l - x;
	if (delt < 0)return 0;
	else if (delt < k)return delt + 1;
	else return -1;
}

bool solve() {
	bool bad = 0, free = 1;
	ll x = -1, tmp;
	cin >> n >> k >> l;
	while (n--) {
		cin >> tmp;
		ll wheel = calcWheel(tmp);
		if (wheel == -1)free = 1;
		else if (wheel == 0)bad = 1;
		else {
			if (free) x = -(wheel - 1);
			else {
				if (x < 0) x = max(x + 1, -(wheel - 1));
				else {
					x++;
					if (x >= wheel)bad = 1;
				}
			}
			free = 0;
		}
	}
	return !bad;
}


int main() {
	fast;
	int t;
	cin >> t;
	while (t--) {
		if (solve())cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}