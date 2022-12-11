#include <stdio.h>

#define N 1010

int play[N][N];
int n,k;

int main() {
	scanf("%d%d",&n,&k);
	bool found = false;
	int ans = 0;
	for(int i=1;i<=n;i++) {
		int cnt = 0;
		for(int j=1;j<=n && cnt < k;j++) {
			if(!play[j][i] && !play[i][j] && i != j) {
				play[i][j] = 1;
				cnt++;
				ans++;
			}
			if(j == n && cnt < k) {
				found = true;
			}
		}		
	}
	if(found == true) {
		printf("-1\n");
	}else {
		printf("%d\n",ans);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=n;j++) {
				if(play[i][j]) {
					printf("%d %d\n",i,j);
				}
			}
		}
	}
	return 0;
}