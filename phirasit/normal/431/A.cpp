#include <stdio.h>

int arr[5];
char str[100010];

int main() {
	for(int i = 0;i< 4;i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%s",str);
	int ans = 0;
	for(int i = 0;str[i];i++) {
		ans += arr[str[i] - '1'];
	}
	printf("%d\n",ans);
	return 0;
}