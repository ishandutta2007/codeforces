#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, q, reg=1;
bool b[100000][2];

bool ok(int i) {
	return i>=0&&i<n;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	while(q--) {
		int x, y; cin >> y >> x, --x, --y;
		int sign=b[x][y]?-1:1;
		for (int i: {-1, 0, 1}) {
			if (ok(x+i)&&b[x+i][y^1])
				reg+=sign;
		}
		b[x][y]^=1;
		cout << (reg==1?"Yes":"No") << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/