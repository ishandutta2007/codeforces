#include <iostream>
#include <stdio.h>
#define s (l+r)/2
long long n,k,a[100001],b[100001];
bool provera(long long t)
{
	long long total=0;
	for(int i=0;i<n;i++) 
	{
	    total+=t*a[i]>b[i]?t*a[i]-b[i]:0;
	    if(total>k||total<0) return false;
	}
	return true;
}
int binarna(long long l,long long r)
{
	if(provera(s)) 
	{
	    if(!provera(s+1)) return s;
	    else return binarna(s+1,r);
	}
	return binarna(l,s);
	
}
int main(int argc, char** argv)
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
	for(int i=0;i<n;i++) scanf("%I64d",&b[i]);
	long long l=binarna(0,10000000000);
	printf("%I64d",l);
	return 0;
}