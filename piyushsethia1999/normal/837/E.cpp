#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int x; cin >> x;
	int y; cin >> y;
	if (x == 1) {cout << y;return 0;} 
	std::vector<int> px;
	std::vector<int> cx;
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			int cn = 0;
			while (x % i == 0) {
				x /= i;
				cn++;
			} 
			px.pb(i);
			cx.pb(cn);
		} 
	}
	if (x > 1) {
		px.pb(x);
		cx.pb(1);
	}
	int cn = 0;
	while (y > 1) {
		int mi = 10000000000000ll;
		for (int i = 0; i < px.size(); ++i) {
			int p = px[i];
			if (cx[i]) {
				mi = min(mi, y % p);
			}
		}
		if (mi == 10000000000000ll) {
			cn += y;
			y = 0;
			break;
		}
		cn += mi;
		y -= mi;
		int yn = 1;
		for (int i = 0; i < px.size(); ++i) {
			int p = px[i];
			if (cx[i]) {
				if (y % p == 0) 
					yn *= p, cx[i]--;
			}
		}
		y /= yn;
	} 
	if (y) cn++;
	cout << cn;
}