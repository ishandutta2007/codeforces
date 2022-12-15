#include<cstdio>

int main()
{
	int y,b,r;
	scanf("%d%d%d",&y,&b,&r);
	y++; r--;
	if (b<y) y=b;
	if (r<y) y=r;
	printf("%d\n",3*y);
	return 0;
}