#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <math.h>
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

void solve() {
	int n, k;
	cin >> n >> k;
	if (k > (n + 1) / 2) {
		cout << -1 << '\n';
		return;
	}
	int rem = k;
	foru(i, 0, n) {
		foru(j, 0, n) {
			if (i == j && ((i & 1) == 0) && (rem > 0)) {
				cout << 'R';
				rem--;
			}
			else cout << '.';
		}
		cout << '\n';
	}
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}