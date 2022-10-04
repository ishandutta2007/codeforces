#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <complex>
#include <tuple>
#include <list>
#include <limits.h>
#define mp make_pair
#define ni(x) scanf("%d", &(x))
#define nii(x,y) scanf("%d%d",&(x),&(y))

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int mod = 1000000007;
const int inf = 2012345678;
const double pi = 3.1415926535897932384626433832795;
//----------------------------------------------------------------------------//

int t[150000];
vector<int> bad;

void ex() {
	puts("0");
	exit(0);
}
int n;
int chk(int a, int b) {
	swap(t[a], t[b]);
	int bad = 0;
	for (int i = 0; i < n - 1; i++) {
		if (i % 2 == 0) {
			if (t[i] >= t[i + 1]) {
				bad = 1;
				break;
			}
		}
		else {
			if (t[i] <= t[i + 1]) {
				bad = 1;
				break;
			}
		}
	}
	swap(t[a], t[b]);
	if (bad) return 0;
	return 1;
}

int main() {
#ifndef __GNUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ni(n);
	for (int i = 0; i < n; i++) {
		ni(t[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		if (i % 2 == 0) {
			if (t[i] >= t[i + 1]) bad.push_back(i);
		}
		else {
			if (t[i] <= t[i + 1]) bad.push_back(i);
		}
	}
	if (bad.size() >= 5) {
		puts("0");
		return 0;
	}
	if (bad.size() == 4) {
		if (bad[1] != bad[0] + 1 || bad[3] != bad[2] + 1) {
			puts("0");
			return 0;
		}
		else {
			int cnt = 0;
			cnt = chk(bad[1], bad[3]);
			printf("%d", cnt);
		}
		return 0;
	}
	else if (bad.size() == 3) {
		int cnt = 0;
		if (bad[1] == bad[0] + 1) {
			cnt += chk(bad[0] + 1, bad[2]);
			if(bad[2] < n- 1) cnt += chk(bad[0] + 1, bad[2] + 1);
			if (bad[2] == bad[1] + 1) {
				
				cnt += chk(bad[0], bad[1] + 1);
				
				cnt += chk(bad[0] + 1, bad[1] + 1);
			}
		}
		else if(bad[2] == bad[1]+1){
			cnt += chk(bad[0] + 1, bad[1] + 1);
			cnt += chk(bad[0], bad[1] + 1);
		
		}
		else {
			puts("0");
			return 0;
		}
		printf("%d", cnt);
		return 0;
	}
	else if (bad.size() == 2) {
		if (bad[1] != bad[0] + 1) {
			int cnt = 0;
			cnt += chk(bad[0] + 1, bad[1]);
			if (bad[1] < n - 1) {
				cnt += chk(bad[0] + 1, bad[1] + 1);

				cnt += chk(bad[0], bad[1] + 1);
			}
				cnt += chk(bad[0], bad[1]);
				printf("%d", cnt);
		}
		else {
			int cnt = 0;
			cnt += chk(bad[0], bad[1]);
			if (bad[1] < n - 1) {
				cnt += chk(bad[0], bad[1] + 1);
				cnt += chk(bad[1], bad[1] + 1);
			}
			
			int lb = -inf; int ub = inf;
			if (bad[1] % 2 == 0) {
				ub = t[bad[0]] - 1;
				if (bad[1] < n - 1) ub = min(ub, t[bad[1] + 1] - 1);
			}
			else {
				lb = t[bad[0]] + 1;
				if (bad[1] < n - 1)lb = max(lb, t[bad[1] + 1] + 1);
			}
			int val = t[bad[1]];
			for (int i = 0; i < bad[0]; i++) {
				if (lb > t[i] || ub < t[i]) continue;
				if (i % 2 == 0) {
					if (i > 0 && val >= t[i - 1] || i < n - 1 && val >= t[i + 1]) continue;
				}
				else {
					if (i > 0 && val <= t[i - 1] || i < n - 1 && val <= t[i + 1]) continue;
				}
				cnt++;
			}
			for (int i = bad[1] + 2; i < n; i++) {
				if (lb > t[i] || ub < t[i]) continue;
				if (i % 2 == 0) {
					if (i > 0 && val >= t[i - 1] || i < n - 1 && val >= t[i + 1]) continue;
				}
				else {
					if (i > 0 && val <= t[i - 1] || i < n - 1 && val <= t[i + 1]) continue;
				}
				cnt++;
			}
			printf("%d", cnt);
		}
		return 0;
	}
	else {
		int cnt = 0;
		if (bad[0] > 0) {
			cnt += chk(bad[0] - 1, bad[0]);
			cnt += chk(bad[0] - 1, bad[0] + 1);
		}
		if (bad[0] < n - 1) cnt += chk(bad[0], bad[0] + 1);
		if (bad[0] < n - 2) {
			cnt += chk(bad[0], bad[0] + 2);
			cnt += chk(bad[0] + 1, bad[0] + 2);
		}
		int lb = -inf; int ub = inf;
		int k = bad[0];
		if (k % 2 == 0) {
			if (k > 0) ub = min(ub, t[k - 1] - 1);
			if (k < n - 1) ub = min(ub, t[k + 1] - 1);
		}
		else {
			if (k > 0)lb = max(lb, t[k - 1] + 1);
			if (k < n - 1) lb = max(lb, t[k - 1] + 1);
		}
		int val = t[k];
		for (int i = 0; i < bad[0] - 1; i++) {
			if (t[i] < lb || t[i] > ub) continue;
			if (i % 2 == 0) {
				if (i > 0 && val >= t[i - 1] || i < n - 1 && val >= t[i + 1]) continue;
			}
			else {
				if (i > 0 && val <= t[i - 1] || i < n - 1 && val <= t[i + 1]) continue;
			}
			cnt++;
		}
		for (int i = bad[0] + 3; i < n; i++) {
			if (t[i] < lb || t[i] > ub) continue;
			if (i % 2 == 0) {
				if (i > 0 && val >= t[i - 1] || i < n - 1 && val >= t[i + 1]) continue;
			}
			else {
				if (i > 0 && val <= t[i - 1] || i < n - 1 && val <= t[i + 1]) continue;
			}
			cnt++;
		}

		lb = -inf; ub = inf;
		k = bad[0] + 1;
		if (k % 2 == 0) {
			if (k > 0) ub = min(ub, t[k - 1] - 1);
			if (k < n - 1) ub = min(ub, t[k + 1] - 1);
		}
		else {
			if (k > 0)lb = max(lb, t[k - 1] + 1);
			if (k < n - 1) lb = max(lb, t[k - 1] + 1);
		}
		val = t[k];
		for (int i = 0; i < bad[0] - 1; i++) {
			if (t[i] < lb || t[i] > ub) continue;
			if (i % 2 == 0) {
				if (i > 0 && val >= t[i - 1] || i < n - 1 && val >= t[i + 1]) continue;
			}
			else {
				if (i > 0 && val <= t[i - 1] || i < n - 1 && val <= t[i + 1]) continue;
			}
			cnt++;
		}
		for (int i = bad[0] + 3; i < n; i++) {
			if (t[i] < lb || t[i] > ub) continue;
			if (i % 2 == 0) {
				if (i > 0 && val >= t[i - 1] || i < n - 1 && val >= t[i + 1]) continue;
			}
			else {
				if (i > 0 && val <= t[i - 1] || i < n - 1 && val <= t[i + 1]) continue;
			}
			cnt++;
		}
		printf("%d", cnt);
	}
	return 0;
}