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

const int maxn = 3e5 + 10, maxm = 2e7 + 10;

int a[maxn], n, d, pme[maxm], p_n, rem[maxm], cnt[maxm];
bool isp[maxm];

void pre() {
	int N = maxm - 10;
	for (int i = 2; i <= N; ++i) isp[i] = 1;
	for (int i = 2; i <= N; ++i) {
		if(isp[i]) pme[p_n++] = i, rem[i] = i;
		for (int j = 0; j < p_n; ++j) {
			int p = pme[j], x = p * i;
			if(x > N) break;
			isp[x] = 0; rem[x] = p;
			if(i % p == 0) break;
		}
	}
	return;
}

int main() {
	pre();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", a + i), d = (i == 1 ? a[i] : __gcd(d, a[i]));
	for (int i = 1; i <= n; ++i) a[i] /= d;
	for (int i = 1; i <= n; ++i) {
		vector<int> y;
		for (int x = a[i]; x > 1; x /= rem[x]) {
			y.push_back(rem[x]);
		}
		sort(y.begin(), y.end());
		y.resize(unique(y.begin(), y.end()) - y.begin());
		for (int x: y) ++cnt[x];
	}
	int mx = 0;
	for (int i = 2; i <= 20000000; ++i) if(cnt[i] > mx) mx = cnt[i];
	if(mx == 0) puts("-1");
	else printf("%d\n", n - mx);
	return 0;
}