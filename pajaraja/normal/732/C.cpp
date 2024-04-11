#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a[3];
void cikloshift()
{
	long long b[3];
	b[0]=a[0];
	b[1]=a[1];
	b[2]=a[2];
	a[0]=b[1];
	a[1]=b[2];
	a[2]=b[0];
}
long long podprovera(long long v[])
{
	for(int i=0;i<3;i++) if(a[i]>v[i]) 
	{
	    return -1;
	}
	long long z=0;
	for(int i=0;i<3;i++) z+=v[i]-a[i];
	return z;
}
long long provera()
{
	long long t[3]={a[0],a[0],a[0]};
	long long r[3];
	r[0]=podprovera(t);
	t[2]--;
	r[1]=podprovera(t);
	t[1]--;
	r[2]=podprovera(t);
	if(r[1]==-1&&r[0]==-1&&r[2]==-1) return -1;
	long long maxx;
	for(int i=0;i<3;i++)
	{
		if(r[i]!=-1) maxx=r[i];
	}
	for(int i=0;i<3;i++)
	{
		if(r[i]!=-1) maxx=min(maxx,r[i]);
	}
	return maxx;
}

int main(int argc, char** argv) 
{
	scanf("%I64d%I64d%I64d",&a[0],&a[1],&a[2]);
	long long t[3],maxx;
	for(int i=0;i<3;i++)
	{
		t[i]=provera();
		cikloshift();
		if(t[i]!=-1) maxx=t[i];
	}
	for(int i=0;i<3;i++)
	{
		if(t[i]!=-1) maxx=min(maxx,t[i]);
	}
	printf("%I64d",maxx);
	return 0;
}