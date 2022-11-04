#include<stdio.h>
int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	if (m > n)printf("-1\n");
	if (m <= n){
		if (n % 2 == 0){
			for (i = n / 2; i <= n; i++){
				if (i%m == 0){
					printf("%d\n", i);
					break;
				}
			}
		}
		if (n % 2 == 1){
			for (i = n / 2 + 1; i <= n; i++){
				if (i%m == 0){
					printf("%d\n", i);
					break;
				}
			}
		}
	}
	return 0;
}