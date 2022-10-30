
#include <iostream>
#include <stdio.h>

int main(int argc, char** argv) 
{
	int n,r;
	scanf("%d",&n);
	int x[n],y[n];
	for (int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	r=n/2-2;
	printf("%d",r);
	return 0;
}