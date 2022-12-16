#include <bits/stdc++.h>

char S[20][20];

int mx[8] = {0, 1, 0, -1, 1, 1, -1, -1}, my[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int co[8] = {2, 3, 0, 1, 7, 6, 5, 4};

int main () {
	for (int i = 0; i < 10; ++i)
		scanf (" %s", S[i]);
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < 10; ++j)
			if (S[i][j] == '.')
				for (int k = 0; k < 8; ++k) {
					int nx = i + mx[k], ny = j + my[k], st = 1;
					while (nx >= 0 && ny >= 0 && nx < 10 && ny < 10 && S[nx][ny] == 'X') {
						nx += mx[k], ny += my[k], ++st;
					}
					nx = i + mx[co[k]]; ny = j + my[co[k]];
					while (nx >= 0 && ny >= 0 && nx < 10 && ny < 10 && S[nx][ny] == 'X') {
						nx += mx[co[k]], ny += my[co[k]], ++st;
					}
					if (st >= 5) {
						puts ("YES");
						return 0;
					}
				}
	puts ("NO");
	return 0;
}