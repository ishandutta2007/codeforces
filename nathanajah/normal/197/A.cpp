#include <stdio.h>
int main()
{
	int a,b,r;
	scanf("%d %d %d",&a,&b,&r);
	printf(2*r <= a && 2*r <= b ? "First\n" : "Second\n");
}