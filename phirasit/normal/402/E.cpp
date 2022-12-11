#include <stdio.h>

#define N 2010

int arr[N][N];
int pass[N];
int n;
int cnt1 = 0, cnt2 = 0;

void dfs1(int i) {
	pass[i] = 1;
	cnt1++;
	for(int j = 1;j <= n;j++) {
		if(!pass[j] && arr[i][j]) {
			dfs1(j);
		}
	}
}
void dfs2(int i) {
	pass[i] = 1;
	cnt2++;
	for(int j = 1;j <= n;j++) {
		if(!pass[j] && arr[j][i]) {
			dfs2(j);
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	dfs1(1);
	for(int i = 1;i <= n;i++) {
		pass[i] = 0;
	}
	dfs2(1);
	printf("%s\n", (cnt1 == n && cnt2 == n) ? "YES" : "NO");
	return 0;
}