#include <bits/stdc++.h>

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) + rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

using namespace std;

const int mod = 1e9 + 7, maxn = 4e5 + 10;

int n, ans;
char opr[maxn][20];
long long a[maxn];
set<long long> l, r;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s%"LLFORMAT"d", opr + i, a + i);
	ans = 1;
	for (int i = 1; i <= n; ++i) {
		int j = i;
		while(j <= n && opr[j][1] == 'D') ++j;
		if(j > n) {
			long long x, y;
			if(l.size()) x = *l.rbegin(); else x = 0;
			if(r.size()) y = *r.begin(); else y = (1ll << 60);
			int cnt = 1;
			for (int k = i; k <= n; ++k) {
				if(a[k] >= x && a[k] <= y) {
					++cnt;
				}
			}
			ans = (long long) ans * cnt % mod;
			printf("%d\n", ans);
			return 0;
		}
		long long x = a[j];
		bool flag = 0;
		for (int k = i; k < j; ++k) if(a[k] == x) { flag = 1; break; }
		if(flag) {
			ans = (ans << 1) % mod;
			for (int k = i; k < j; ++k) {
				if(a[k] < x) l.insert(a[k]);
				if(a[k] > x) r.insert(a[k]);
			}
			if(l.size() && *l.rbegin() > x || r.size() && *r.begin() < x) { puts("0"); return 0; }
			i = j;
			continue;
		}
		if(l.find(x) != l.end()) {
			l.erase(x);
			for (int k = i; k < j; ++k) {
				if(a[k] < x) l.insert(a[k]);
				if(a[k] > x) r.insert(a[k]);
			}
			if(l.size() && *l.rbegin() > x || r.size() && *r.begin() < x) { puts("0"); return 0; }
		}
		else if(r.find(x) != r.end()) {
			r.erase(x);
			for (int k = i; k < j; ++k) {
				if(a[k] < x) l.insert(a[k]);
				if(a[k] > x) r.insert(a[k]);
			}
			if(l.size() && *l.rbegin() > x || r.size() && *r.begin() < x) { puts("0"); return 0; }
		}
		else {
			puts("0");
			return 0;
		}
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}