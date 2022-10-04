#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <map>
#include <string>
#include <iostream>
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;



int dyn[5000][5000];
int dyn2[5000][5001];
char buf[5001];
int num[5003];
pii tmp[5000];
int srt[5000];
int srt2[5000];
int cnt[5001];

const int mod = 1000000007;

void proc(int n) {
	for (int l = 1; l <= n; l++) {
		if (l == 1) {
			for (int i = 0; i < n; i++) dyn2[i][l] = num[i];
			continue;
		}
		for (int i = 0; i < n - 1; i++) {
			tmp[i] = mp(num[i], dyn2[i + 1][l - 1]);
		}
		tmp[n - 1] = mp(num[n - 1], 0);
		int k = max(10, n);
		for (int i = 0; i <= k; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			cnt[tmp[i].second]++;
		}
		int sum = 0;
		for (int i = 0; i <= k; i++) {
			int t = cnt[i];
			cnt[i] = sum;
			sum += t;
		}
		for (int i = 0; i < n; i++) {
			srt[cnt[tmp[i].second]++] = i;
		}

		for (int i = 0; i <= k; i++) cnt[i] = 0;
		for (int i = 0; i < n; i++) {
			cnt[tmp[srt[i]].first]++;
		}
		sum = 0;
		for (int i = 0; i <= k; i++) {
			int t = cnt[i];
			cnt[i] = sum;
			sum += t;
		}
		for (int i = 0; i < n; i++) {
			srt2[cnt[tmp[srt[i]].first]++] = srt[i];
		}

		int nm = 1; dyn2[srt2[0]][l] = 1;
		for (int i = 1; i < n; i++) {
			int ps = srt2[i - 1];
			if (tmp[ps].first != tmp[srt2[i]].first || tmp[ps].second != tmp[srt2[i]].second) nm++;
			dyn2[srt2[i]][l] = nm;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	scanf("%s", buf);
	for (int i = 0; i < n; i++) num[i] = buf[i] - '0' + 1;
	proc(n);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = n - 1; j >= i; j--) {
			if (num[i] == 1) continue;
			if (j == n - 1) dyn[i][j] = 1;
			else {
				dyn[i][j] = dyn[i][j + 1];
				int len = j - i + 1;
				int totlen = n - i;
				if (2 * len > totlen) continue;
				int tmp;
				if (j + len + 1 == n) tmp = 0;
				else tmp = dyn[j + 1][j + len + 1];
				if (dyn2[i][len] < dyn2[i + len][len]) {
					tmp = dyn[j + 1][j + len];
				}
				dyn[i][j] = ((ll)dyn[i][j] + tmp)%mod;

			}
		}
	}
	printf("%d\n", dyn[0][0]);
	return 0;
}