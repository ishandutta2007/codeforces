#include <iostream>
#include <stdio.h>
int main(int argc, char** argv) 
{
	int n,k,t;
	scanf("%d%d",&n,&k);
	n++;
	t=n%k;
	if(t!=0) n+=(k-t);
	printf("%d",n);
	return 0;
}