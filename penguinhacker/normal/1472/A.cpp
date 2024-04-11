#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) {
		int w, h, n; cin >> w >> h >> n;
		int a = 1, b = 1;
		while(w % 2 == 0) a <<= 1, w >>= 1;
		while(h % 2 == 0) b <<= 1, h >>= 1;
		cout << (a * b >= n ? "YES" : "NO") << "\n";
	}
	return 0;
}