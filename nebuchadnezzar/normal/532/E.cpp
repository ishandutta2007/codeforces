#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <ctime>
#include <time.h>
#include <string>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <bitset>
#include <cassert>

using namespace std;

const int maxn = (int)1e5 + 10;
char s[maxn];
char t[maxn];
int cnt[2][maxn];
int g[2][maxn];
int p[maxn];
int n;

long long hsh[maxn];
long long pp = (int)1e9 + 7;
set <long long> res;
long long tt[maxn];

long long go_hsh(int l, int r) {
	if (l == 0) {
		return hsh[r];
	} else {
		long long f = hsh[r] - hsh[l - 1] * tt[r - l + 1];

		f %= pp;
		f += pp;
		f %= pp;

		return f;
	}
}

void go_hash(int pos, char c) {
	long long f = 0;

	if (pos != 0) {
		f += hsh[pos - 1] * tt[n - pos + 1];
		f %= pp;
	}

	f += (c - 'a' + 1) * tt[n - pos];
	f %= pp;

	if (pos != n) {
		f += go_hsh(pos, n - 1);
		f %= pp;
	}

	res.insert(f);
}

int main() {
	scanf("%d", &n);

	tt[0] = 1;

	for (int i = 1; i < maxn; i++) {
		tt[i] = tt[i - 1] * 1234567;
		tt[i] %= pp;
	}

	scanf("%s", s);
	scanf("%s", t);

	long long now = 0;

	for (int i = 0; i < n; i++) {
		now *= 1234567;
		now += s[i] - 'a' + 1;
		now %= pp;
		hsh[i] = now;
	}

	cnt[0][0] = 0;
	g[0][0] = (s[0] == t[0]);

	for (int i = 1; i < n; i++) {
		if (s[i] == t[i - 1]) {
			cnt[0][i] = cnt[0][i - 1] + 1;
		} else {
			cnt[0][i] = 0;
		}

		if (s[i] == t[i]) {
			g[0][i] = g[0][i - 1] + 1;
		} else {
			g[0][i] = 0;
		}
	}

	cnt[1][n] = 0;
	p[n - 1] = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (i != 0 && s[i] == t[i - 1]) {
			cnt[1][i] = cnt[1][i + 1] + 1;
		} else {
			cnt[1][i] = 0;
		}

		if (i != n - 1 && s[i] == t[i + 1]) {
			p[i] = p[i + 1] + 1;
		} else {
			p[i] = 0;
		}

		if (s[i] == t[i]) {
			g[1][i] = g[1][i + 1] + 1;
		} else {
			g[1][i] = 0;
		}
	}

	int ans = 0;

	for (int i = 0; i <= n; i++) {
		if (i == 0 || g[0][i - 1] == i) {
			int pos = i + p[i];
			pos++;
			if (pos + g[1][pos] == n) {
				//ans++;
				go_hash(i, t[i]);
			}
		} else if (i == n || i + g[1][i] == n) {
			int pos = i - 1 - cnt[0][i - 1];
			if (pos == 0 || g[0][pos - 1] == pos) {
				go_hash(i, t[i - 1]);
				//ans++;
			}
		}
	}

	cout << res.size() << endl;

	return 0;
}