#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;
const int B = 262144;

int a[B];
pii tr[2 * B];

int getmin(int nd, int ndl, int ndr, int l, int r) {
	if (l > ndr || ndl > r) return B - 1;
	else if (l <= ndl && ndr <= r) return tr[nd].first;
	else {
		int mid = (ndl + ndr) / 2;
		int i1 = getmin(2 * nd, ndl, mid, l, r);
		int i2 = getmin(2 * nd + 1, mid + 1, ndr, l, r);
		if (a[i1] < a[i2])return i1;
		else return i2;
	}
}

int getmax(int nd, int ndl, int ndr, int l, int r) {
	if (l > ndr || ndl > r) return B - 2;
	else if (l <= ndl && ndr <= r) return tr[nd].second;
	else {
		int mid = (ndl + ndr) / 2;
		int i1 = getmax(2 * nd, ndl, mid, l, r);
		int i2 = getmax(2 * nd + 1, mid + 1, ndr, l, r);
		if (a[i1] < a[i2])return i2;
		else return i1;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	a[B - 1] = 2000000000;
	for (int i = 0; i < B; i++) {
		tr[B + i].first = i;
		tr[B + i].second = i;
	}
	for (int i = B - 1; i > 0; i--) {
		const pii &x = tr[2 * i];
		const pii &y = tr[2 * i + 1];
		if (a[x.first] > a[y.first]) tr[i].first = y.first;
		else tr[i].first = x.first;
		if (a[x.second] > a[y.second]) tr[i].second = x.second;
		else tr[i].second = y.second;
	}
	for (int i = 0; i < m; i++) {
		int l, r, x;
		scanf("%d %d %d", &l, &r, &x);
		l--; r--;
		int i1 = getmin(1, 0, B - 1, l, r);
		int i2 = getmax(1, 0, B - 1, l, r);
		if (a[i1] != x) {
			printf("%d\n", i1 + 1);
		}
		else if (a[i2] != x) {
			printf("%d\n", i2 + 1);
		}
		else {
			puts("-1");
		}
	}
}