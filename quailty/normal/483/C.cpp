#include<cstdio>
int main()
{
	int n, k, i, up, down, flag = 1;
	scanf("%d%d", &n, &k);
	up = 1;
	down = k + 1;
	for (i = 1; i <= k + 1; i++)
	{
		if (i % 2 == 1){
			if (flag == 0)printf(" ");
			printf("%d", up);
			flag = 0;
			up++;
		}
		if (i % 2 == 0){
			if (flag == 0)printf(" ");
			printf("%d", down);
			flag = 0;
			down--;
		}
	}
	for (i = k + 2; i <= n; i++)
		printf(" %d", i);
	printf("\n");
	return 0;
}