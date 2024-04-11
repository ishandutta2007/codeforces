#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		long long s = 0, x = 0;
		for (int i = 0; i < n; ++i) {
			long long y;
			cin >> y;
			s += y;
			x ^= y;
		}
		cout << 2 << endl;
		cout << x << ' ' << s + x << endl;
	}
	return 0;
}