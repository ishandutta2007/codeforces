#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <tuple>
#include <limits.h>
#include <iostream>
#include <iomanip>
#include <complex>
#include <string.h>
#include <string>

#define mp make_pair
#define mtp make_tuple
#define ni(x) scanf("%d", &(x))
#define nii(x, y) scanf("%d%d", &(x), &(y))
#define mul(x,y) (ll)(x)*(y)%mod

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

char buf[4000][4000];
int fw[3000][3000];
int bw[3000][3000];
int tmpfw[4000];
int tmpbw[4000];

const int B = 4096;

struct BIT {
	int tr[2 * B];
	BIT() {}
	void init() {
		for (int i = 0; i < 2 * B; i++) tr[i] = 0;
	}
	void upd(int i) {
		tr[B + i]++;
		int cur = (B + i) / 2;
		while (cur > 0) {
			tr[cur]++;
			cur /= 2;
		}
	}
	int get(int nd, int ndl, int ndr, int l, int r) {
		if (l > ndr || ndl > r) return 0;
		else if (l <= ndl && ndr <= r) return tr[nd];
		else {
			int mid = (ndl + ndr) / 2;
			return get(2 * nd, ndl, mid, l, r) + get(2 * nd + 1, mid + 1, ndr, l, r);
		}
	}
};

BIT bit;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	for (int i = 0; i < n; i++) scanf("%s", buf[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (buf[i][j] == '.') {}
			else if (j == 0) fw[i][j] = 1;
			else fw[i][j] = fw[i][j - 1] + 1;

			if (buf[i][m - 1 - j] == '.') {}
			else if (j == 0) bw[i][m - 1 - j] = 1;
			else bw[i][m - 1 - j] = bw[i][m - j] + 1;
		}
	}
	ll ans = 0;
	for (int sum = 0; sum < m + n - 1; sum++) {
		int s, e;
		if (sum < n) {
			s = 0;
		}
		else s = sum - n + 1;

		if (sum < m) e = sum;
		else {
			e = m - 1;
		}
		int cur = -1;
		for (int i = s; i <= e; i++) {
			if (buf[sum - i][i] == '.') {
				cur = -1;
			}
			else {
				if (cur == -1) cur = i;
				tmpbw[i] = cur;
			}
		}
		cur = -1;
		for (int i = e; i >= s; i--) {
			if (buf[sum - i][i] == '.') {
				cur = -1;
			}
			else {
				if (cur == -1) cur = i;
				tmpfw[i] = cur;
			}
		}

		vector<pii> fi;
		vector<pii> se;

		for (int i = s; i <= e; i++) {
			if (buf[sum - i][i] == '.') continue;
			int power = i + bw[sum - i][i] - 1;
			power = min(power, tmpfw[i]);
			fi.push_back(mp(i, power));
		}
		for (int i = s; i <= e; i++) {
			if (buf[sum - i][i] == '.')continue;
			int power = i - fw[sum - i][i] + 1;
			power = max(power, tmpbw[i]);
			se.push_back(mp(power, i));
		}
		sort(fi.begin(), fi.end());
		sort(se.begin(), se.end());
		auto it = fi.begin();
		auto it2 = se.begin();
		bit.init();
		for (int i = s; i <= e; i++) {
			for (; it2 != se.end(); it2++) {
				if (it2->first != i) break;
				else {
					bit.upd(it2->second - s);
				}
			}
			for (; it != fi.end(); it++) {
				if (it->first != i) break;
				else {
					ans += bit.get(1, 0, B - 1, it->first - s, it->second - s);
				}
			}
		}
	}
	printf("%I64d", ans);

	return 0;
}
/*
const int mod = 1000000007;

char d;

int pow(int n, int e) {
	if (e == 0) return 1;
	int tmp = pow(n, e / 2);
	tmp = mul(tmp, tmp);
	if (e % 2) tmp = mul(tmp, n);
	return tmp;
}

int solve(char *dec, int len) { //d-goods in [1, dec]
	if (len == 0) return 1;
	if (len == 1)return dec[0] - '0' + 1;
	if (dec[1] == '0' + d) {
		int res1 = mul(dec[0] - '0', pow(0, (len - 1) / 2));
		int res2 = solve(dec + 2, len - 2);
		return ((ll)res1 + res2) % mod;
	}
	else if (dec[1] < '0' + d) {
		int dd = dec[0] - '0';
		dd = mul(dd, pow(9, (len - 1) / 2));
		return dd;
	}
	else {
		int dd = dec[0] - '0' + 1;
		dd = mul(dd, pow(9, (len - 1) / 2));
		return dd;
	}
}

char a[3000];
char b[3000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m, dd;
	nii(m, dd);
	d = '0' + dd;


	return 0;
}*/