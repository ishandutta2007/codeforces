#include <stdio.h>

int sum[40];
int arr[40][2];
int n,d;

int main() {
	int i,j;
	int min,max;
	scanf("%d %d",&n,&d);
	min = max = 0;
	for(i=0;i<n;i++) {
		scanf("%d %d",&arr[i][0],&arr[i][1]);
		min += arr[i][0];
		max += arr[i][1];
	}
	for(i=n-1;i>=0;i--)
		sum[i] = sum[i+1] + arr[i][1];
	if(d < min || d > max) {
		printf("NO\n");
	}else {
		printf("YES\n");
		for(i=0;i<n;i++) {
			for(j=arr[i][0];j<=arr[i][1];j++) {
				if(d-j <= sum[i+1])
					break;
			}
			d -= j;
			printf("%d ",j);
		}
	}
	return 0;
}