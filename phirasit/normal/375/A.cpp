/* C. Divisible by Seven */

#include <stdio.h>

#define MX_N 1000010

char str[MX_N];
int cnt[20];
int out[] = {
	1869,6198,1896,1689,1986,1968,1698,1869,6198,1896
};
int main() {
	int i,j;
	scanf("%s",str);
	for(i=0;str[i];i++) {
		cnt[str[i]-'0']++;
	}
	cnt[1]--;
	cnt[8]--;
	cnt[6]--;
	cnt[9]--;
	j = 0;
	for(i=1;i<=9;i++) {
		while(cnt[i]--) {
			printf("%d",i);
			j = (10*j + i)%7;
		}
	}
	printf("%d",out[j]);
	while(cnt[0]--)
		printf("0");
	printf("\n");
	return 0;
}