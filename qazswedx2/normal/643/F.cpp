#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned int uint;
int n,p,q;
uint a[1005];
uint fpow(uint x,uint y)
{
	uint ans=1;
	while(y)
	{
		if(y&1) ans*=x;
		x*=x;
		y/=2;
	}
	return ans;
}
inline int lowbit(int x)
{
	return x&-x;
}
int F(int x)
{
	int ct=0;
	while(x%2==0) x/=2,ct++;
	return ct;
}
int main()
{
	scanf("%d%d%d",&n,&p,&q);
	p=min(p,n-1);
	uint nw=1,nw2=1;
	int ct=0;
	a[0]=1;
	for(int i=1;i<=p;i++)
	{
		nw*=(n-i+1)/lowbit(n-i+1);
		nw2*=i/lowbit(i);
		ct+=F(n-i+1);
		ct-=F(i);
		a[i]=(nw*fpow(nw2,(1u<<31u)-1))<<ct;
	}
/*	for(int i=0;i<=p;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	uint ans=0;
	for(int i=1;i<=q;i++)
	{
		uint nans=0;
		for(int j=p;j>=0;j--)
			nans=nans*i+a[j];
	//	printf("nans=%u\n",nans);
		ans^=(nans*i);
	}
	printf("%u\n",ans);
	return 0;
}