#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#define s (l+r)/2
using namespace std;
int n,a[100006];
int fobin(int l,int r,int t)
{
	int k=a[s];
	if(k==t) 
	{
		if(s==0) return s;
		else if(a[s-1]!=t) return s; 
	}
	if(l==r) return -1;
	if(k<t) return fobin(s+1,r,t);
	return fobin(l,s,t);
}
int lobin(int l,int r, int t)
{
	int k=a[s];
	if(k==t) 
	{
		if(s==n-1) return s;
		else if(a[s+1]!=t) return s; 
	}
	if(l==r) return -2;
	if(k<=t) return lobin(s+1,r,t);
	return lobin(l,s,t);
}
int main(int argc, char *argv[])
{
	int p1,p2,t=1;
	long long rez=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<31;i++)
	{
		t*=2;
		for(int i=0;i<n;i++)
		{
			p1=fobin(0,n-1,t-a[i]);
			p2=lobin(0,n-1,t-a[i]);
			rez+=p2-p1+1;
			if(p1<=i&&p2>=i) rez--; 
		}
	}
	rez/=2;
	printf("%I64d",rez);
	return 0;
}