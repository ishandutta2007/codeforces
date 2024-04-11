#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int n, d, h;
	cin >> n >> d >> h;
	if (d + 1 > n || h > d || h * 2 < d || d == 1 && n > 2) cout << -1;
	else {
		for (int i = 1; i <= h; ++i) cout << i << ' ' << i + 1 << '\n';
		for (int i = h + 2; i <= d + 1; ++i) 
			if (i == h + 2) cout << 1 << ' ' << i << '\n';
			else cout << i - 1 << ' ' << i << '\n';
		for (int i = d + 2; i <= n; ++i) cout << h << ' ' << i << '\n';
	}
    return 0;
}