#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <complex>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d", &(x), &(y))
#define save(A, x) (A).push_back(mp(&x, x))
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MN = 1000000;

int fw[400000];
int fwlen = 0;
int bw[400000];
int bwlen = 0;
int chk[400000];

vector<pair<int*, int> > hist[400001];
vector<int> pos[400010];
int seq[400000];
vector<pii > query[400000];
int Ans[400000];

void pophist(vector<pair<int*, int> >& hist) {
	while (!hist.empty()) {
		auto x = hist.back();
		*(x.first) = x.second;
		hist.pop_back();
	}
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m; nii(n, m);
	for (int i = 0; i < n; i++) ni(seq[i]);
	for (int i = n - 1; i >= 0; i--) {
		if (bwlen == 0 || bw[bwlen - 1] > seq[i]) {
			save(hist[i], bwlen);
			bwlen++;
			save(hist[i], bw[bwlen - 1]);
			bw[bwlen - 1] = seq[i];
		}
		else {
			int l = 0; int  u = bwlen;
			while (l != u) {
				int mid = (l + u) / 2;
				if (bw[mid] <= seq[i]) u = mid;
				else l = mid + 1;
			}
			save(hist[i], bw[l]);
			bw[l] = seq[i];
		}
	}
	int maxlen = bwlen;
	int cur = 0;
	for (int i = 0; i < m; i++) {
		int a, b;
		nii(a, b);
		a--;
		query[a].push_back(mp(b, i));
	}
	for (int i = 0; i < n; i++) {
		pophist(hist[i]);
		for (auto &x : query[i]) {
			int ans = 1; int b = x.first;
			int l = 0; int  u = fwlen;
			while (l != u) {
				int mid = (l + u) / 2;
				if (fw[mid] >= b) u = mid;
				else l = mid + 1;
			}
			ans += l;
			l = 0; u = bwlen;
			while (l != u) {
				int mid = (l + u) / 2;
				if (bw[mid] <= b) u = mid;
				else l = mid + 1;
			}
			ans += l;
			Ans[x.second] = ans;
		}
		int chg = -1;
		if (fwlen == 0 || fw[fwlen - 1] < seq[i]) {
			fwlen++;
			fw[fwlen - 1] = seq[i];
			chg = fwlen - 1;
		}
		else {
			int l = 0; int u = fwlen;
			while (l != u) {
				int mid = (l + u) / 2;
				if (fw[mid] >= seq[i]) u = mid;
				else l = mid + 1;
			}
			fw[l] = seq[i];
			chg = l;
		}
		int l = 0; int u = bwlen;
		while (l != u) {
			int mid = (l + u) / 2;
			if (bw[mid] <= seq[i])u = mid;
			else l = mid + 1;
		}
		if (l + chg + 1 == maxlen) {
			chk[i] = 1;
			pos[chg].push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (pos[i].size() == 1) {
			chk[pos[i][0]] = 2;
		}
	}
	for (int i = 0; i < n; i++) {
		for (auto &x : query[i]) {
			if (chk[i] == 2) {
				Ans[x.second] = max(Ans[x.second], maxlen - 1);
			}
			else {
				Ans[x.second] = max(Ans[x.second], maxlen);
			}
		}
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", Ans[i]);
	}
	return 0;
}