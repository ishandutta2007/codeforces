#include <stdio.h>

int main() {
	int cnt = 0,n,k;
	scanf("%d%d",&n,&k);
	while(n--) {
		int a;
		scanf("%d",&a);
		cnt += 5-a >= k;
	}
	printf("%d\n",cnt/3);
	return 0;
}