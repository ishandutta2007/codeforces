#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int cnt[20], a[20];

int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) ++cnt[s[i] - '0'];
	for (int t = cnt[8]; ~t; --t) {
		int x = n - t;
		if(x >= t * 10) { cout << t ; return 0; }
	}
	return 0;
}