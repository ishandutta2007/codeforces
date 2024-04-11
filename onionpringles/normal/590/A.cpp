#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

using namespace std;
typedef pair<int, int> pii;

int dat[500000];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", dat + i);
	}
	for (int i = 0; i < n; i++) {
		if (i % 2) dat[i] ^= 1;
	}
	int res = 0; int cur = -1; int cnt = 0; int curstart = 0;
	for (int i = 0; i < n; i++) {
		if (dat[i] == cur) cnt++;
		else {
			res = max(res, (cnt - 1) / 2);
			int m = (curstart + i) / 2;
			for (int j = curstart + 1; j < m; j++) {
				dat[j] = dat[j - 1] ^ 1;
			}
			for (int j = i - 1; j >= m; j--) {
				dat[j] = dat[j + 1] ^ 1;
			}
			cur = dat[i];
			curstart = i;
			cnt = 1;
		}
	}
	int i = n;
	res = max(res, (cnt - 1) / 2);
	int m = (curstart + i) / 2;
	for (int j = curstart + 1; j < m; j++) {
		dat[j] = dat[j - 1] ^ 1;
	}
	for (int j = i - 2; j >= m; j--) {
		dat[j] = dat[j + 1] ^ 1;
	}
	cur = dat[i];
	curstart = i;
	for (int i = 0; i < n; i++) {
		if (i % 2) dat[i] ^= 1;
	}
	printf("%d\n", res);
	for (int i = 0; i < n; i++) printf("%d ", dat[i]);
}