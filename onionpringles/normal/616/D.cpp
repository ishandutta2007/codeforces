#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>
#include <set>
#include <tuple>

#define mp make_pair
#define mtp make_tuple
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(m), &(n))

using namespace std;
typedef pair<int, int> pii;

int a[500000];
int cnt[1000001];
int acnt[500000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, k; nii(n, k);
	for (int i = 0; i < n; i++) ni(a[i]);
	int l = 1;
	int u = n + 1;
	int good = 0;
	pii res;
	while (l != u) {
		int mid = (l + u) / 2;
		int m = n + 1 - mid;
		good = 0;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < m; i++) {
			if (i == 0) {
				acnt[i] = 1;
				cnt[a[i]]++;
				continue;
			}
			if (cnt[a[i]]>0) acnt[i] = acnt[i - 1];
			else acnt[i] = acnt[i - 1] + 1;
			cnt[a[i]]++;
		}
		for (int i = m; i < n; i++) {
			cnt[a[i - m]]--;
			acnt[i] = acnt[i - 1];
			if (cnt[a[i - m]] == 0)  acnt[i]--;
			if (cnt[a[i]] == 0) acnt[i]++;
			cnt[a[i]]++;
		}
		for (int i = m - 1; i < n; i++) {
			if (acnt[i] <= k) {
				res = mp(i - m + 1, i);
				good = 1;
				break;
			}
		}
		if (good) {
			u = mid;
		}
		else l = mid + 1;
	}
	printf("%d %d", res.first + 1, res.second + 1);
	return 0;
}