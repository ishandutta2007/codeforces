#include <stdio.h>

int arr[110];
int n,a,b;

int main() {
	int i;
	scanf("%d",&n);
	for(i=1;i<n;i++)
		scanf("%d",&arr[i]);
	scanf("%d %d",&a,&b);
	i = 0;
	while(a < b)
		i += arr[a++];
	printf("%d\n",i);
	return 0;
}