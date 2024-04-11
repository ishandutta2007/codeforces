#include <iostream>
#include <stdio.h>
#include <algorithm>
int main(int argc, char** argv) 
{
	int a[3];
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	a[1]/=2;
	a[2]/=4;
	std::sort(a,a+3);
	printf("%d",7*a[0]);
	return 0;
}