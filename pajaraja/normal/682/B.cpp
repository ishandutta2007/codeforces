#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int r=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=r) r++;
	}
	printf("%d",r);
	return 0;
}