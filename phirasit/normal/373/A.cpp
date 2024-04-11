#include <stdio.h>

char str[10][10];
int cnt[20];
int k;

int main() {
	int i,j;
	scanf("%d",&k);
	for(i=0;i<10;i++) {
		cnt[i] = 0;
	}
	for(i=0;i<4;i++) {
		scanf("%s",str[i]);
		for(j=0;j<4;j++) {
			if(str[i][j] == '.') continue;
			cnt[str[i][j]-'0']++;
		}
	}
	for(i=1;i<10;i++)
		if(cnt[i] > 2*k)
			break;
	if(i < 10)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}