#include <stdio.h>

int arr[40][2];
int n;

int main() {
	int ans = 0;
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d %d",&arr[i][0],&arr[i][1]);
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(arr[i][0] == arr[j][1])
				ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}