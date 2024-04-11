#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	if (n % 4 == 0)
		printf("%d %d", n / 2, n / 2);
	else if (n % 4 == 2)
		printf("%d %d", n / 2 - 1, n / 2 + 1);
	else{
		if (n == 13)printf("4 9");
		if (n == 15)printf("6 9");
		if (n == 17)printf("8 9");
		if (n >= 19)printf("15 %d", n - 15);
	}
	return 0;
}