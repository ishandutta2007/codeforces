#include <stdio.h>

#define N 110

char str[N][N];
int di[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;

int main() {
	
	scanf("%d", &n);
	
	for(int i = 0;i < n;i++) {
		scanf("%s", str[i]);
	}
	
	bool err = false;
	
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			int cnt = 0;
			for(int k = 0;k < 4;k++) {
				int ni = i + di[k][0], nj = j + di[k][1];
				if(ni < 0 || nj < 0 || ni >= n || nj >= n) {
					continue;
				}
				cnt += str[ni][nj] == 'o';
			}
			if(cnt%2) {
				err = true;
			}
		}
	}
	if(err) {
		printf("NO\n");
	}else {
		printf("YES\n");
	}
	return 0;
}