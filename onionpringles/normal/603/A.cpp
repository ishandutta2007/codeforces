#pragma warning(disable:4996)
#include <stdio.h>

#include <vector>
#include <algorithm>

using namespace std;

char str[100002];

int main() {
	int n;
	scanf("%d", &n);
	scanf(" %s", str);
	char cur = str[0];
	int cnt = 0;
	int allcnt = 0;
	int mttwo = 0;
	int mtthr = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == cur) {
			cnt++;
		}
		else {
			if (cnt >= 2) mttwo++;
			if (cnt >= 3) mtthr++;
			allcnt++;
			cur = str[i];
			cnt = 1;
		}
	}
	if (cnt >= 2) mttwo++;
	if (cnt >= 3) mtthr++;
	allcnt++;
	cnt = 0;
	int res;
	if (mtthr > 0) {
		res = allcnt + 2;
	}
	else if (mttwo > 1) {
		res = allcnt + 2;
	}
	else if (mttwo == 1) {
		res = allcnt + 1;
	}
	else {
		res = allcnt;
	}
	printf("%d", res);

	return 0;
}