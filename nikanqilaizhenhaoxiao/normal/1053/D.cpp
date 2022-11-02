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

const int maxn = 2e5 + 10, maxm = 2e6 + 10, mod = 1e9 + 7;

int n, p[maxn], m, pme[maxm], p_n, rem[maxm], cnt[maxm], foo[maxm];
pair<int, int> a[maxn];
bool isp[maxm];
vector<int> all;

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

void M(int x) {
	all.push_back(x);
	while(x > 1) {
		int y = rem[x], z = 0;
		while(x % y == 0) ++z, x /= y;
		if(z > cnt[y]) {
			foo[y] = 0;
			cnt[y] = z;
		}
		if(cnt[y] == z) ++foo[y];
	}
	return;
}

int F(int x) {
	while(x > 1) {
		int y = rem[x], z = 0;
		while(x % y == 0) ++z, x /= y;
		if(z == cnt[y] && foo[y] == 1) return 0;
	}
	return 1;
}

int main() {
	pre();
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", p + i);
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while(j + 1 <= n && p[j + 1] == p[i]) ++j;
		a[m++] = make_pair(p[i], j - i + 1);
		i = j;
	}
	sort(a, a + m, [&](pair<int, int> u, pair<int, int> v) { return u.second == v.second ? u.first > v.first : u.second > v.second; });
	bool fuck = 0;
	for (int i = 0; i < m; ++i) {
		int x = a[i].first, y = a[i].second;
		if(cnt[x]) --x;
		M(x); --y;
		if(y) {
			if(cnt[x]) --x;
			M(x); --y;
			if(y) {
				fuck = 1;
			}
		}
	}
	int lcm = 1;
	for (int x = 2; x < maxm; ++x) {
		for (int j = 0; j < cnt[x]; ++j) lcm = (long long) lcm * x % mod;
	}
	if(fuck) { printf("%d\n", (lcm + 1) % mod); return 0; }
	for (int x: all) {
		if(F(x)) { printf("%d\n", (lcm + 1) % mod); return 0; }
	}
	printf("%d\n", lcm);
	return 0;
}