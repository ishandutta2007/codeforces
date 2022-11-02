#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	long long l = 1, r = 1000000000;
	int n; cin >> n;

	function<bool(int, int)> Q = [&](int x, int y) {
		cout << x << ' ' << y << endl;
		fflush(stdout);
		string s;
		cin >> s;
		return (s[0] == 'b');
	};

	bool col = Q(0, 1);
	if(n == 1) { cout << "1 0 2 0\n"; fflush(stdout); return 0; }
	while(--n) {
		long long mid = l + r >> 1;
		while(mid - l < r - mid) ++mid;
		while(mid - l > r - mid) --mid;
		bool f = (Q(mid, 1) == col);
		if(f) l = mid + 1;
		else r = mid - 1;
	}
	if(l == r + 1) {
		cout << r << " 2 " << l << " 0\n"; fflush(stdout); return 0;
	}
	assert(l <= r);
	cout << l << " 0 " << l << " 1\n";
	fflush(stdout);
	return 0;
}