#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define s (l+r)/2
using namespace std;
int n,m,a[100006],b[100006],mini[100006];
int lobin(int l,int r,int t)
{
	int k=b[s];
	if(k<=t)
	{
		if(s==m-1) return s;
		else if(b[s+1]>t) return s; 
	}
	if(l==r) return -1;
	if(k<=t) return lobin(s+1,r,t);
	return lobin(l,s,t);
}
int main(int argc, char *argv[])
{
	int mins=000000000,p1,p2,t=1;
	long long rez=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	sort(a,a+n);
	sort(b,b+m);
		for(int i=0;i<n;i++)
		{
			p1=lobin(0,m-1,a[i]);
			if(p1==m-1) mini[i]=a[i]-b[p1];
			else
			{
				if(p1==-1) mini[i]=b[0]-a[i];
				else mini[i]=fmin(a[i]-b[p1],b[p1+1]-a[i]);
	        }
		}
	for(int i=0;i<n;i++) mins=fmax(mins,mini[i]);
	printf("%d",mins);
	return 0;
}