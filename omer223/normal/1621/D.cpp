#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (ll i = k; i < n; i++)
#define ford(i, k, n) for (ll i = k; i >= n; i--)
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
typedef pair<ll, ll> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

ll foo(vector<vector<ll>> a) {
	ll n = a.size();
	vector<vector<ll>> down(n, vector<ll>(n, 0)), up = down;
	ll bst = 1e18;
	foru(i, 0, n) {
		foru(j, 0, n)up[i][j] = a[i][j] + (i ? up[i - 1][j] : 0);
	}
	ford(i, n - 1, 0) {
		vector<ll> p(n, 0), s(n, 0);
		foru(j, 0, n)p[j] = (a[i][j] + (j ? p[j - 1] : 0));
		ford(j, n - 1, 0)s[j] = (a[i][j] + (j == n - 1 ? 0 : s[j + 1]));
		foru(j, 0, n)down[i][j] = a[i][j] + (i == n - 1 ? 0 : down[i + 1][j]);
		foru(j, 0, n) {
			vector<ll> hori{ p[j],s[j] }, vert{ up[i][j],down[i][j] };
			for (ll x : hori) {
				for (ll y : vert) {
					bst = min(bst, x + y - a[i][j]);
				}
			}
		}
	}
	return bst;
}

void solve() {
	ll n;
	cin >> n;
	vector<vector<ll>> board(2 * n, vector<ll>(2 * n, 0));
	foru(i, 0, 2 * n) {
		foru(j, 0, 2 * n) {
			cin >> board[i][j];
		}
	}
	ll ans = 0;
	foru(i, 0, 2*n) {
		foru(j, 0, 2*n) {
			if ((i < n) == (j < n))ans += board[i][j];
		}
	}
	ans += min({ board[0][n],board[0][2 * n - 1],board[n - 1][n],board[n - 1][2 * n - 1],board[n][0],board[n][n - 1],board[2 * n - 1][0],board[2 * n - 1][n - 1] });
	cout << ans << '\n';
}

int main() {
	fast;
	ll t;
	cin >> t;
	while (t--)solve();
	return 0;
}