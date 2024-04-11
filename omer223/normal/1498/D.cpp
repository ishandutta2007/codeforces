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
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 2e5;
int n, m;
bitset<sz> can, bcan;
ll er[sz], howmany[sz];

ll myceil(ll a, ll b) {
	return a / b + (a%b != 0);
}

int main() {
	fast;
	scanf("%d %d", &n, &m);
	bcan[0] = 1;
	for (int i = 1; i <= m; i++)er[i] = -1;
	foru(i, 0, n) {
		int t;
		ll x, y;
		ll rx;
		scanf("%d %lld %lld", &t, &x, &y);
		foru(j, 0, m + 1)
			howmany[j] = (bcan[j] ? y : 0);
		switch (t) {
		case 1:
			rx = myceil(x, 1e5);
			for (int j = 0; j <= m; j++) {
				int nj = rx + j;
				if (howmany[j]) {
					howmany[nj] = max(howmany[nj], howmany[j] - 1);
					can[nj] = 1;
				}
			}
			break;
		case 2:
			for (int j = 0; j <= m; j++) {
				ll nj = myceil(x*j, 1e5);
				if (howmany[j] && nj >= 0 && nj <= m) {
					howmany[nj] = max(howmany[nj], howmany[j] - 1);
					can[nj] = 1;
				}
			}
			break;
		}
		foru(j, 0, m + 1) {
			if(can[j])bcan[j] = can[j];
			if (can[j] && er[j] == -1)
				er[j] = i + 1;
		}
		bcan[0] = 1;
	}
	for (int j = 1; j <= m; j++)
		printf("%d ",er[j]);
	return 0;
}