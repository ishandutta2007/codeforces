#include <cstdio>

int main(void) {
	int c;
	scanf("%d\n", &c);
	for(int t=0;t<c;t++) {
		int a,b;
		scanf("%d %d\n", &a, &b);
		int diff=b-a;
		if (diff<0) {
			diff=-diff;
		}
		printf("%d\n",diff/5+(diff%5+1)/2);
	}
	return 0;
}