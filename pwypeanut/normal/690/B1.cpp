#include <bits/stdc++.h>
using namespace std;

int N, mn_x, mx_x, mn_y, mx_y;
char s[55][55];

void die() {
	printf("No\n");
	exit(0);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", &s[i]);
	mn_y = mn_x = N;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (s[i][j] != '0') {
				mn_x = min(mn_x, i);
				mx_x = max(mx_x, i);
				mn_y = min(mn_y, j);
				mx_y = max(mx_y, j);
			}
			if (s[i][j] == '4') cnt++;
		}
	}
	if (s[mn_x][mn_y] != '1') die();
	if (s[mx_x][mx_y] != '1') die();
	if (s[mn_x][mx_y] != '1') die();
	if (s[mx_x][mn_y] != '1') die();
	for (int i = mn_x + 1; i < mx_x; i++) {
		if (s[i][mn_y] != '2') die();
		if (s[i][mx_y] != '2') die();
	}
	for (int i = mn_y + 1; i < mx_y; i++) {
		if (s[mn_x][i] != '2') die();
		if (s[mx_x][i] != '2') die();
	}
	for (int i = mn_x + 1; i < mx_x; i++) {
		for (int j = mn_y + 1; j < mx_y; j++) {
			if (s[i][j] != '4') die();
		}
	}
	if (cnt == 0) die();
	printf("Yes\n");
}