#include <iostream>
#include <stdio.h>
int a[100000],b[100000];
int main(int argc, char** argv) 
{
	int n,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	a[n-1]=b[n-1];
	for(int i=1;i<n;i++) a[i-1]=b[i-1]+b[i];
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	return 0;
}