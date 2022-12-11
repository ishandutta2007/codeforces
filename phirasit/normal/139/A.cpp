#include <stdio.h>

int arr[10],n;

int main() {
	int i,sum = 0;
	scanf("%d",&n);
	for(i=0;i<7;i++) {
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	n %= sum;
	sum = 0;
	if(n == 0) {
		for(i=6;i>=0;i--)
			if(arr[i])
				break;
		printf("%d\n",i+1); 
		return 0; 
	}
	for(i=0;sum < n;i++)
		sum += arr[i];
	printf("%d\n",i);
	return 0;
}