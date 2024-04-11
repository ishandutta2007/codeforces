#include <stdio.h>

#define MX_N 100010

int arr[MX_N][2];
int x,y;
int n;

int main() {
	int i,j;
	int a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	x = y = 0;
	a = b = 0;
	for(i=0;2*i<=n;i++) {
		arr[i][0] = arr[i][1] = 0;
		if(i > x) x = i;
		if(i > y) y = i;
		while(a < i) {
			a++;
			b--;
		}
		while(b < i) {
			b++;
			a--;
		}
		int k = n-a-b;
		while(k-- > 0) {
			if(arr[a+1][0] < arr[b+1][1]) a++;
			else b++;
		}
		if(a > x) x = a;
		if(b > y) y = b;
	}
	for(i=1;i<=n;i++) {
		printf("%d",i <= x);
	}
	printf("\n");
	for(i=1;i<=n;i++) {
		printf("%d",i <= y);
	}
	printf("\n");
	return 0;
}