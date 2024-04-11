#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if(n > m) swap(n, m);
	if(n == 1) {
		int x = m / 6, ans = x * 6;
		m %= 6;
		if(m >= 4) ans += (m - 3) * 2;
		cout << ans << endl;
		return 0;
	}
	if(n == 2) {
		static const int ans[] = {0, 0, 0, 4, 8, 10, 12, 12, 16, 18, 20};
		if(m <= 9) cout << ans[m] << endl;
		else cout << m * 2 << endl;
		return 0;
	}
	long long x = (long long) n * m;
	if(x & 1) --x;
	cout << x << endl;
	return 0;
}