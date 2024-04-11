#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(n), &(m))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<ll> rs;
int chk[2000];
int x[2000];
int y[2000];

ll dis(int x1, int y1, int x2, int y2) {
	ll dx = x1 - x2;
	ll dy = y1 - y2;
	return dx*dx + dy*dy;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, x1, x2, y1, y2;
	ni(n); nii(x1, y1); nii(x2, y2);
	rs.push_back(0);
	for (int i = 0; i < n; i++) {
		nii(x[i], y[i]);
		rs.push_back(dis(x1, y1, x[i], y[i]));
	}
	sort(rs.begin(), rs.end());
	ll ans = 500000000000000000LL;
	for (auto &d : rs) {
		memset(chk, 0, sizeof(chk));
		for (int i = 0; i < n; i++) {
			if (dis(x1, y1, x[i], y[i]) <= d)chk[i] = 1;
		}
		ll tmp = 0;
		for (int i = 0; i < n; i++) {
			if (chk[i]) continue;
			tmp = max(tmp, dis(x2, y2, x[i], y[i]));
		}
		ans = min(ans, tmp + d);
	}
	printf("%I64d", ans);

	return 0;
}