#include<cstdio>
int main()
{
	int c, i, sum = 0;
	for (i = 1; i <= 5; i++){
		scanf("%d", &c);
		sum += c;
	}
	if (sum % 5 == 0 && sum!=0)printf("%d\n", sum / 5);
	else printf("-1\n");
	return 0;
}