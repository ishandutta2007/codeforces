#include <stdio.h>

#define N 1010

int arr[N];
int n;

int main() {
	int a,b;
	scanf("%d%d%d",&n,&a,&b);
	while(a--) {
		int x;
		scanf("%d",&x);
		arr[x] = 1;
	}
	while(b--) {
		int y;
		scanf("%d",&y);
		arr[y] = 2;
	}
	for(int i=1;i<=n;i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}