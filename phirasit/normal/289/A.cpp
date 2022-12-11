#include <stdio.h>

int n,k;

int main() {
	int a,b;
	int cnt = 0;
	scanf("%d %d",&n,&k);
	while(n--) {
		scanf("%d %d",&a,&b);
		cnt += b-a+1;
	}
	printf("%d\n",cnt%k == 0?0:k-cnt%k);
	return 0;
}