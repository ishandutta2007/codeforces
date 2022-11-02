#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	long long la, ra, ta, lb, rb, tb;
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	auto F = [&](long long la, long long ra, long long ta, long long lb, long long rb, long long tb) {
		long long d = __gcd(ta, tb);
		long long x = lb - la;
		long long y = (x / d - 10) * d;
		while(y <= x) y += d;
		y -= d;
		y += ra - lb;
		return min(y, rb - lb);
	};
	cout << max(max(F(la, ra, ta, lb, rb, tb), F(lb, rb, tb, la, ra, ta)) + 1, 0ll) << endl;
	return 0;
}