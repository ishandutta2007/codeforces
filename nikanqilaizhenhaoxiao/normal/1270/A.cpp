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
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		string ans;
		while(k1--) {
			int x;
			cin >> x;
			if(x == n) ans = "YES";
		}
		while(k2--) {
			int x;
			cin >> x;
			if(x == n) ans = "NO";
		}
		cout << ans << endl;
	}
	return 0;
}