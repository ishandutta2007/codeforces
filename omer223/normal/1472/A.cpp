#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <bitset>
#include <queue>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;



void solve() {
	int n, w, h;
	cin >> w >> h >> n;
	ll cnt = 1;
	while (w % 2 == 0) {
		cnt *= 2;
		w >>= 1;
	}
	while (h % 2 == 0) {
		cnt *= 2;
		h >>= 1;
	}
	cout << ((n <=cnt) ? "YES\n" : "NO\n");
}

int main() {
	fast;
	int t;
	cin >> t;
	while (t--)solve();
	return 0;
}