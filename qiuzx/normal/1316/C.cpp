#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1000010
using namespace std;
int n,m,p;
bool booka[N],bookb[N];
int read()
{
	int ret=0;
	char c;
	c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret;
}
int main(){
	int i,j,a;
	n=read();
	m=read();
	p=read();
	for(i=0;i<n;i++)
	{
		a=read();
		if(a%p==0)
		{
			booka[i]=true;
		}
		else
		{
			booka[i]=false;
		}
	}
	for(i=0;i<m;i++)
	{
		a=read();
		if(a%p==0)
		{
			bookb[i]=true;
		}
		else
		{
			bookb[i]=false;
		}
	}
	i=0;
	j=0;
	while(i<n&&j<m)
	{
		if(!booka[i]&&!bookb[j])
		{
			printf("%d\n",i+j);
			return 0;
		}
		if(booka[i])
		{
			i++;
		}
		if(bookb[j])
		{
			j++;
		}
	}
	return 0;
}