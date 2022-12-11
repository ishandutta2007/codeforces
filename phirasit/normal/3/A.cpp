#include <stdio.h>

char a[5],b[5];

int max(int a,int b) {
	if(a > b) return a;
	return b;
}
int abs(int x) {
	if(x < 0) return -x;
	return x;
}
int main() {
	int i,j;
	scanf("%s %s",a,b);
	printf("%d\n",max(abs(a[0]-b[0]),abs(a[1]-b[1])));
	while(a[0] != b[0] || a[1] != b[1]) {
		if(a[0] < b[0]) { printf("R"); a[0]++; }
		if(a[0] > b[0]) { printf("L"); a[0]--; }
		if(a[1] > b[1]) { printf("D"); a[1]--; }
		if(a[1] < b[1]) { printf("U"); a[1]++; }
		printf("\n");
	}
	return 0;
}