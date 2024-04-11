#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10001];
int main(int argc, char** argv) 
{
	fill(a,a+10001,0);
	int n,m,t1,t2,r=0;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
	    scanf("%d%d",&t1,&t2);
	    a[t1]++;
	    a[t2]++;
	}
	for(int i=1;i<=n;i++) r+=((a[i]*(a[i]-1))/2);
	printf("%d",r);
	return 0;
}