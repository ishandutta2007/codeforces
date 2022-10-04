#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int S = 317;

pair<pii, int> query[100000];
int a[S*S];
ll ans[100000];
int cnt[1048577];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	nii(n, m); ni(k);
	for (int i = 1; i <= n; i++) {
		int x;
		ni(x);
		a[i] = a[i - 1] ^ x;
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		nii(l, r);
		l--;
		query[i] = mp(mp(l, r), i);
	}
	sort(query, query + m, [](const pair<pii, int>& x, const pair<pii, int>& y)->bool {
		return x.first.first / S < y.first.first / S || x.first.first / S == y.first.first / S && x.first.second < y.first.second;
	});
	int curl = -1;
	ll tmp = 0;
	int svl = -1;
	int svr = -1;
	for (int i = 0; i < m;i++) {
		auto x = query[i];
		int l = x.first.first;
		int r = x.first.second;
		if (l / S != curl) {
			curl = l / S;
			tmp = 0;
			memset(cnt, 0, sizeof(cnt));
			for (int i = l; i <= r; i++) {
				int sk = a[i] ^ k;
				tmp = tmp + cnt[sk];
				cnt[a[i]]++;
			}
			ans[x.second] = tmp;
		}
		else {
			if (svl < l) {
				for (int i = svl; i < l; i++) {
					int sk = a[i] ^ k;
					tmp = tmp - cnt[sk];
					if (k == 0) tmp++;
					cnt[a[i]]--;
				}
			}
			else if(svl>l) {
				for (int i = svl - 1; i >= l; i--) {
					int sk = a[i] ^ k;
					tmp = tmp + cnt[sk];
					cnt[a[i]]++;
				}
			}
			for (int i = svr + 1; i <= r; i++) {
				int sk = a[i] ^ k;
				tmp = tmp + cnt[sk];
				cnt[a[i]]++;
			}
			ans[x.second] = tmp;
		}
		svl = l; svr = r;
	}
	for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
	return 0;
}