#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, k, i, j, temp, sum=0,*f;
	scanf("%d%d", &n, &k);
	f = (int*)malloc(n*sizeof(int));
	for (i = 0; i <= n - 1; i++)scanf("%d", &f[i]);
	for (i = 0; i <= n - 1; i++)
	for (j = 0; j <= i - 1; j++){
		if (f[i] >= f[j]){
			temp = f[i];
			f[i] = f[j];
			f[j] = temp;
		}
	}
	for (i = 0; i <= n - 1;i++){
		if (i % k == 0)sum = sum + 2 * (f[i]-1);
	}
	printf("%d", sum);
	return 0;
}