#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;
const int inf = 1e9 + 7;



signed main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

 	cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
		int a, b, c, d, x, y, x1, y1, x2, y2;
    	cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    	x += b - a;
    	y += d - c;
    	bool bad = !(x >= x1 && x <= x2 && y >= y1 && y <= y2);
    	bad |= (x == x1 && x == x2 && a + b > 0) | (y == y1 && y == y2 && c + d > 0);
    	if (!bad) cout << "Yes";
    	else cout << "No";
    	cout << '\n';
	}
}