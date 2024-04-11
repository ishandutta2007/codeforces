#include <iostream>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int n,m,z,br=1;
	scanf("%d%d",&n,&m);
	n%=10;
	z=n;
	while(z!=m&&z!=0)
	{
		z=(z+n)%10;
		br++;
	}
	printf("%d",br);
	return 0;
}