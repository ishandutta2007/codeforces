#include <stdio.h>
#include <algorithm>

using namespace std;

int n, p, k;

int main() {
	scanf("%d%d%d", &n, &p, &k);
	if(p-k > 1) {
		printf("<< ");
	}
	for(int i = max(1, p-k);i <= p-1;i++) {
		printf("%d ", i);
	}
	printf("(%d) ", p);
	for(int i = p+1;i <= min(p+k, n);i++) {
		printf("%d ", i);
	}
	if(p+k < n) {
		printf(">> ");
	}
	printf("\n");
	return 0;
}