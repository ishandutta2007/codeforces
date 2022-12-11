#include <stdio.h>

#define MX_N 210

int arr[MX_N][2];
int n;

int main() {
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	int cnt = 0;
	for(i=0;i<n;i++) {
		int a,b,c,d;
		a = b = c = d = 0;
		for(j=0;j<n;j++) {
			if(i == j) continue;
			if(arr[i][0] > arr[j][0] && arr[i][1] == arr[j][1])
				a = 1;
			if(arr[i][0] < arr[j][0] && arr[i][1] == arr[j][1])
				b = 1;
			if(arr[i][0] == arr[j][0] && arr[i][1] < arr[j][1])
				c = 1;
			if(arr[i][0] == arr[j][0] && arr[i][1] > arr[j][1])
				d = 1;
		}
		cnt += (a && b && c && d);
	}
	printf("%d\n",cnt);
	return 0;
}