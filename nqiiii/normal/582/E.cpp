#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
const int maxn = 500, mod = 1e9 + 7;
char s[maxn + 10];
vec ans;
int a[60], b[60], res, n;

inline int add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
inline int dec(int x, int y) {
	x -= y; return x < 0 ? x + mod : x;
}

void flip(vec &a) {
	vec tmp(1 << 16);
	for (int i = 0; i < 1 << 16; ++i)
		tmp[i] = a[i ^ ((1 << 16) - 1)];
	a = tmp;
}

void fmt(vec &a) {
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 1 << 16; ++j)
			if (j >> i & 1) a[j] = add(a[j], a[j ^ (1 << i)]);
}

void ifmt(vec &a) {
	for (int i = 0; i < 16; ++i)
		for (int j = 0; j < 1 << 16; ++j)
			if (j >> i & 1) a[j] = dec(a[j], a[j ^ (1 << i)]);
}

vec operator + (const vec &a, const vec &b) {
	vec ans(1 << 16);
	for (int i = 0; i < 1 << 16; ++i)
		ans[i] = add(a[i], b[i]);
	return ans;
}

vec operator | (vec a, vec b) {
	fmt(a); fmt(b);
	for (int i = 0; i < 1 << 16; ++i)
		a[i] = 1ll * a[i] * b[i] % mod;
	ifmt(a);
	return a;
}

vec operator & (vec a, vec b) {
	flip(a); flip(b);
	fmt(a); fmt(b);
	for (int i = 0; i < 1 << 16; ++i)
		a[i] = 1ll * a[i] * b[i] % mod;
	ifmt(a); flip(a);
	return a;
}


vec solve(int l, int r) {
	vec ans(1 << 16);
	if (l == r) {
		if (s[l] != '?') {
			if (s[l] >= 'A' && s[l] <= 'Z') {
				int p = s[l] - 'A', v = 0;
				for (int i = 0; i < 16; ++i)
					if (i >> p & 1) v |= 1 << i;
				++ans[v];
			} else {
				int p = s[l] - 'a', v = 0;
				for (int i = 0; i < 16; ++i)
					if (!(i >> p & 1)) v |= 1 << i;
				++ans[v];
			}
		} else {
			for (int p = 0; p < 4; ++p) {
				int v = 0;
				for (int i = 0; i < 16; ++i)
					if (i >> p & 1) v |= 1 << i;
				++ans[v];
			}
			for (int p = 0; p < 4; ++p) {
				int v = 0;
				for (int i = 0; i < 16; ++i)
					if (!(i >> p & 1)) v |= 1 << i;
				++ans[v];
			}
		}
	} else {
		assert(s[l] == '(');
		int cnt = 0, p = 0;
		for (int i = l; i <= r; ++i) {
			if (s[i] == '(') ++cnt;
			if (s[i] == ')') --cnt;
			if (!cnt) {
				p = i + 1; break;
			}
		}
		vec fl = solve(l + 1, p - 2);
		vec fr = solve(p + 2, r - 1);
		if (s[p] == '&') ans = fl & fr;
		else if (s[p] == '|') ans = fl | fr;
		else ans = (fl & fr) + (fl | fr);
	}
	return ans;
}

int main() {
	scanf("%s", s + 1);
	ans = solve(1, strlen(s + 1));
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < 4; ++j) {
			int x; scanf("%d", &x);
			if (x) a[i] |= 1 << j;
		}
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < 1 << 16; ++i) {
		bool fd = 1;
		for (int j = 1; j <= n; ++j)
			if ((i >> a[j] & 1) != b[j]) {
				fd = 0; break;
			}
		if (fd) {
			res = add(res, ans[i]);
		}
	}
	printf("%d", res);
}