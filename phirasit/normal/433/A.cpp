#include <stdio.h>

int main() {
	int sum = 0;
	int cnt = 0;
	int n;
	scanf("%d",&n);
	while(n--) {
		int a;
		scanf("%d",&a);
		sum += a;
		cnt += a == 100;
	}
	printf("%s\n",(sum/2)%100 == 0?(sum/200)%2 != 0 && cnt == 0?"NO":"YES":"NO");
	return 0;
}