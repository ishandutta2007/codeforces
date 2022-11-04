#include<stdio.h>
#include<stdlib.h>
int  a[100000], q[100000],k[100000], sum[100000],temp[1000000];
int comp(const void*a, const void*b)
{
	return*(int*)a - *(int*)b;
}
int main()
{
	int n, m, i, j;
	scanf("%d", &n);
	for (i = 0; i <= n - 1; i++)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (i = 0; i <= m - 1; i++){
		scanf("%d", &q[i]);
		k[i] = q[i];
	}
	qsort(q, m, sizeof(int), comp);
	sum[0] = a[0];
	for (i = 1; i <= n - 1; i++)
		sum[i] = sum[i - 1] + a[i];
	i = 0;
	j = 0;
	while (i<=m-1){
		if (q[i] <= sum[j]){
			temp[q[i]] = j + 1;
			i = i + 1;
		}
		else j = j + 1;
	}
	for (i = 0; i <= m - 1; i++)
		printf("%d\n", temp[k[i]]);
	return 0;
}