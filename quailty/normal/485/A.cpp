#include<stdio.h>
int main(void)
{
	int a, m, i;
	scanf("%d%d", &a, &m);
	for (i = 0; i <= m; i++){
		if (a%m == 0){
			printf("Yes");
			break;
		}
		if (a < 0){
			a = a;
		}
		a = (a + a)%m;
		if (i == m)
			printf("No");
	}
	return 0;
}