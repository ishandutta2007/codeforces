#include <iostream>
#include <stdio.h>
long long provera(long long k)
{
	long long i=2,j,s=0;
	bool m=true;
	while(m)
	{
		j=i*i*i;
		if(k<j)
		{
			m=false;
		}
		else
		{
			s+=k/j;
		}
		i++;
	}
	return s;
}
long long binarna(long long l,long long r,long long k)
{
	long long s=(l+r)/2;
	long long t=provera(s),t1=provera(l);
	if((l==r||r-l==1)&&t!=k) return -1;
	if(k==t) return s;
	if(k>t) return binarna(s,r,k);
	return binarna(l,s,k);
}
int main(int argc, char** argv) 
{
	long long n,t;
	scanf("%I64d",&n);
	t=binarna(1,1000000000000000000,n);
	while(provera(t-1)==n) t--;
	printf("%I64d",t);
	return 0;
}