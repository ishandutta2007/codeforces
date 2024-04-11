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

const int maxn = 2e5 + 10;

int n, a[maxn], s;
long long m;
multiset<int> l, r;

int main() {
	scanf("%d%d", &n, &s);
	for (int x, i = 0; i < n; ++i) {
		scanf("%d", &x);
		if(x < s) l.insert(x);
		if(x > s) r.insert(x);
	}
	while(l.size() > (n / 2)) {
		m += (s - *l.rbegin());
		auto it = l.end();
		--it;
		l.erase(it);
	}
	while(r.size() > (n / 2)) {
		m += (*r.begin() - s);
		r.erase(r.begin());
	}
	cout << m << endl;
	return 0;
}