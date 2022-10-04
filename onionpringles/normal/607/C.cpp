#pragma warning(disable:4996)

#include <stdio.h>
#include <vector>
#include <algorithm>
#define mp(a,b) make_pair(a,b)

char A[1000010];
char B[1000010];
char C[1000010];
int dyn[1000000];
char dir[4] = { 'N','E','W','S' };

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	scanf("%s", A);
	scanf("%s", B);
	n--;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			if (B[i] == dir[j]) C[n - 1 - i] = dir[3 - j];
		}
	}
	dyn[0] = 0; dyn[1] = 0;
	for (int i = 2; i < n; i++) {
		int bef = dyn[i - 1];
		while (bef!=0 && C[bef] != C[i - 1]) {
			bef = dyn[bef];
		}
		if (C[bef] == C[i - 1]) {
			dyn[i] = bef + 1;
		}
		else {
			dyn[i] = 0;
		}
	}
	//for (int i = 0; i < n; i++) printf("%d\n", dyn[i]);
	
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (C[cur] == A[i]) {
			cur++;
		}
		else {
			while (C[cur] != A[i] && cur != 0) {
				cur = dyn[cur];
			}
			if (C[cur] == A[i]) {
				cur++;
			}
		}
	}
	if (cur > 0) printf("NO");
	else printf("YES");
}