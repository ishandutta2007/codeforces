#include <stdio.h>

#define N 110

char str[N][N];
int x[N];
int n, m;

int main() {
	scanf("%d%d", &n , &m);
	for(int i = 0;i < n;i++) {
		scanf("%s", str[i]);
		x[i] = 0;
	}
	int ans = 0;
	for(int i = 0;i < m;i++) {
		bool found = false;
		for(int j = 0;j < n-1;j++) { 
			if(x[j] == 0 && str[j][i] > str[j+1][i]) {
				found = true;
			}
		}
		if(found) ans++;
		else for(int j = 0;j < n-1;j++) {
			if(str[j][i] < str[j+1][i]) {
				x[j] = 1;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}