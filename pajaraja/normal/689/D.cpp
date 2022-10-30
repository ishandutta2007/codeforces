#include <iostream>
#include <stdio.h>
#include <math.h>
#define s (l+r)/2
int a[200010],b[200010];
int segmin[800010],segmax[800010];
void napravisegmin(int l,int r,int indx)
{
	if(l==r) 
	{
	    segmin[indx]=a[l];
	    return;
	}
	napravisegmin(l,s,2*indx);
	napravisegmin(s+1,r,2*indx+1);
	segmin[indx]=fmin(segmin[2*indx],segmin[2*indx+1]);
}
void napravisegmax(int l,int r,int indx)
{
	if(l==r) 
	{
	    segmax[indx]=b[l];
	    return;
	}
	napravisegmax(l,s,2*indx);
	napravisegmax(s+1,r,2*indx+1);
	segmax[indx]=fmax(segmax[2*indx],segmax[2*indx+1]);
}
int nadjimin(int l,int r,int tl,int tr,int indx)
{
	if(l>=tl&&r<=tr) return segmin[indx];
	if(l>tr||r<tl) return 1000000001;
	int k,t;
	k=nadjimin(l,s,tl,tr,2*indx);
	t=nadjimin(s+1,r,tl,tr,2*indx+1);
	return fmin(k,t);
}
int nadjimax(int l,int r,int tl,int tr,int indx)
{
	if(l>=tl&&r<=tr) return segmax[indx];
	if(l>tr||r<tl) return -1000000001;
	int k,t;
	k=nadjimax(l,s,tl,tr,2*indx);
	t=nadjimax(s+1,r,tl,tr,2*indx+1);
	return fmax(k,t);
}
int nadjiraz(int l,int r,int n)
{
	return (nadjimin(1,n,l,r,1)-nadjimax(1,n,l,r,1));
}
int main(int argc, char** argv) 
{
	int n,k,t,p1=1,p2=1;
	long long sol=0,t1,t2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	napravisegmin(1,n,1);
	napravisegmax(1,n,1);
	for(int i=1;i<=n;i++)
	{
		if(p1==i-1) p1++;
		if(p2==i-1) p2++;
		while(nadjiraz(i,p1,n)>0&&p1<=n) p1++;
		while(nadjiraz(i,p2,n)>=0&&p2<=n) p2++;
		if(p2==n&&nadjiraz(i,p2,n)==0) p2++;
		p2--;
		t1=p1;
		t2=p2;
		if(nadjiraz(i,p1,n)==0) sol+=(t2-t1+1);
	}
	printf("%I64d",sol);
	return 0;
}