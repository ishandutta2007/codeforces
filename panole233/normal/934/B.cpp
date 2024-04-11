#include<cstdio>
#include<cstring>

int n;

int main()
{
	scanf("%d",&n);
	if (n>36) {printf("-1\n"); return 0;}
	for (int i=1; i<=n/2; i++) printf("8");
	if (n&1) printf("4"); printf("\n");
	return 0;
}