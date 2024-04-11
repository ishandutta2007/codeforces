#include <stdio.h>

int arr[1010];
int n;

int in(int a,int b,int c) {
	if(b <= a && a <= c) return 1;
	if(b >= a && a >= c) return 1;
	return 0;
}
int main() {
	int i,j;
	scanf("%d",&n);
	int ans = 0;
	for(i=0;i<n;i++) {
		scanf("%d",&arr[i]);
		for(j=i-3;j>=0;j--) {
			if(in(arr[i],arr[j],arr[j+1]) && !in(arr[i-1],arr[j],arr[j+1]))
				ans = 1;
			if(!in(arr[i],arr[j],arr[j+1]) && in(arr[i-1],arr[j],arr[j+1]))
				ans = 1;
		}
	}
	if(ans) printf("yes\n");
	else printf("no\n");
	return 0;
}