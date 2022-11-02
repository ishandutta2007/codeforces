#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <long long, int> pii;

vector <pii> factor(long long x) {
	vector <pii> f;
	for (long long i = 2; i * i <= x; i++) {
		if (x % i) continue;
		f.push_back(mp(i, 0));
		while (x % i == 0) x /= i, f.back().se++;
	}
	if (x > 1) f.push_back(mp(x, 1));
	return f;
}

long long sum(long long x, vector <long long> all, long long a) {
	x /= a;
	long long ans = 0;
	for (int mask = 0; mask < (1 << all.size()); mask++) {
		long long lcm = 1;
		int cnt = 0;
		for (int i = 0; i < all.size(); i++) {
			if (mask >> i & 1) lcm *= all[i], cnt++;
		}
		ans += (cnt & 1 ? -1 : 1) * x / lcm;
	}
	return ans;
}

int main () {
	int T; cin >> T;
	while (T--) {
		long long x, y; cin >> x >> y;
		vector <pii> f1 = factor(x), f2 = factor(y);
		set <long long> s;
		vector <long long> all;
		long long a = 1, b = 1;
		for (int i = 0; i < f1.size(); i++) {
			long long p = f1[i].fi;
			if (s.count(p)) continue;
			s.insert(p);
			int t1 = 0; long long xx = x; int t2 = 0; long long yy = y;
			while (xx % p == 0) xx /= p, t1++;
			while (yy % p == 0) yy /= p, t2++;
			if (t1 < t2) a *= x / xx, all.push_back(p);
			else b *= y / yy;
		}
		for (int i = 0; i < f2.size(); i++) {
			long long p = f2[i].fi;
			if (s.count(p)) continue;
			s.insert(p);
			int t1 = 0; long long xx = x; int t2 = 0; long long yy = y;
			while (xx % p == 0) xx /= p, t1++;
			while (yy % p == 0) yy /= p, t2++;
			if (t1 < t2) a *= x / xx, all.push_back(p);
			else b *= y / yy;
		}
		long long l = (x + b - 1) / b, r = (x + y - 1) / b;
		printf("%I64d\n", sum(r, all, a) - sum(l - 1, all, a));
	}
	return 0;
}