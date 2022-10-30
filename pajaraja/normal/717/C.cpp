#include <iostream>
#include <stdio.h>
#include <algorithm>
long long a[100000],rez=0;
int main(int argc, char** argv) 
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
	std::sort(a,a+n);
	for(int i=0;i<n;i++) rez=(rez+(a[i]*a[n-1-i]%10007))%10007;
	printf("%I64d",rez);
	return 0;
}