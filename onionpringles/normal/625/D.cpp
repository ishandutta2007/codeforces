#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <string.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

char buf[100020];

int buf2[100020];
int buf3[100020];
int pal[100020];

int solve(int* buf, int n) {
	for (int i = 0; i < n / 2; i++) {
		if (buf[n - 1 - i] < 0) {
			buf[n - 1 - i - 1]--;
			buf[n - 1 - i] += 10;
		}
		if (buf[i] < 0) return 0;
		if (buf[i] == 0) {
			if (buf[n - 1 - i] == 0) {
				pal[i] = pal[n - 1 - i] = 0;
			}
			else return 0;
			continue;
		}
		if (buf[i] == 19) {
			if (buf[n - 1 - i] == 8) {
				if (i + 1 == n - 1 - i) {
					pal[i] = 9;
					pal[n - 1 - i] = 9;
					continue;
				}
				else {
					buf[i] --;
					buf[i + 1] += 10;
					buf[n - 2 - i]--;
					buf[n - 1 - i] += 10;
					pal[i] = pal[n - 1 - i] = 9;
					continue;
				}
			}
			else return 0;
		}
		if (buf[i] % 10 == buf[n - 1 - i] % 10) {
			if (buf[i] > 9) {
				if (n % 2 == 0 && i == n / 2 - 1) return 0;
				buf[n - 1 - i] += 10;
				buf[n - 2 - i]--;
			}
			pal[n - 1 - i] = buf[i] / 2;
			pal[i] = buf[i] - pal[n - 1 - i];
		}
		else if ((buf[i] - 1) % 10 == buf[n - 1 - i] % 10){
			if (i == 0 && buf[i] == 1) return 0;
			buf[i]--;
			buf[i + 1] += 10;
			if (buf[i] < 10 && buf[n - 1 - i] > 9) return 0;
			if (buf[i] > 9) {
				if (buf[n - 1 - i] < 10) {
					buf[n - 1 - i] += 10;
					buf[n - 2 - i]--;
				}
			}
			pal[n - 1 - i] = buf[i] / 2;
			pal[i] = buf[i] - pal[n - 1 - i];
		}
		else {
			return 0;
		}
	}
	if (n % 2 == 1) {
		if (buf[n / 2] % 2 != 0)return 0;
		else {
			pal[n / 2] = buf[n / 2] / 2;
		}
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", buf);
	int n = strlen(buf);
	for (int i = 0; i < n; i++) {
		buf2[i] = buf[i] - '0';
		buf3[i] = buf[i] - '0';
	}
	if (solve(buf2, n)) {
		for (int i = 0; i < n; i++) {
			assert(pal[i] < 10);
			printf("%d", pal[i]);
		}
	}
	else {
		if (n == 1 || buf3[0] > 1) {
			puts("0");
			return 0;
		}
		buf3[1] += 10;
		if (solve(buf3 + 1, n - 1)) {
			for (int i = 0; i < n - 1; i++) {
				assert(pal[i] < 10);
				printf("%d", pal[i]);
			}
		}
		else {
			puts("0");
			return 0;
		}
	}
	return 0;
}