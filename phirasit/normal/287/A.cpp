#include <stdio.h>

int arr[10][10];
char str[10][10];

int main() {
	int i,j,k,ch = 0;
	for(i=0;i<4;i++) {
		scanf("%s",str[i]);
		for(j=0;j<4;j++) {
			arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + (str[i][j] == '#');
		}
	}
	for(i=1;i<4;i++) {
		for(j=1;j<4;j++) {
			k = arr[i][j] - arr[i-2][j] - arr[i][j-2] + arr[i-2][j-2];
			if(k != 2)
				ch = 1;
		}
	}
	if(ch) printf("YES\n");
	else printf("NO\n");
	return 0;
}