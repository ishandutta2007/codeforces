#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	int n;
	vector<pair<int, int> > a;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		a.push_back(make_pair(l, 1));
		a.push_back(make_pair(r, -1));
	}
	sort(a.begin(), a.end());
	long long x = 0; int s = 0, t = 0;
	long long ans = n;
	for (auto y: a) {
		if(y.second > 0) {
			++t;
			if(s) --s, --t, ans += y.first;
		}
		else {
			++s;
			if(t) --s, --t, ans += y.first;
		}
	}
	printf("%"LLFORMAT"d\n", ans);
	return 0;
}