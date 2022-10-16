#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

int n,m,d,z,cc=0,inf=1e9;
multiset<int> ms;
multiset<int>::iterator it;

void tgl(int x)
{
	it=ms.find(x);
	if(it==ms.end())
	{
		ms.insert(x);
	}
	else
	{
		ms.erase(it);
	}
}

void ad(int y,int x)
{
	int i,j;
	
	for(i=max(y-1,0);i<=min(y,n-2);i++)
	{
		for(j=max(x-1,0);j<=min(x,m-2);j++)
		{
			tgl(i*m+j);
		}
	}
}

void bf(int c)
{
	int i,j,y,x;
	
	cc++;
	if(ms.empty())
	{
		z=min(z,c);
		return;
	}
	if(c==d)
	{
		return;
	}
	y=*ms.begin()/m;
	x=*ms.begin()%m;
	for(i=y;i<=min(y+1,n-1);i++)
	{
		for(j=x;j<=min(x+1,m-1);j++)
		{
			ad(i,j);
			bf(c+1);
			ad(i,j);
		}
	}
}

int main()
{
	int i,j,k;
	
	scanf("%d%d%d",&n,&m,&d);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&k);
			if(k)
			{
				ad(i,j);
			}
		}
	}
	z=inf;
	bf(0);
	if(z==inf)
	{
		z=-1;
	}
	printf("%d\n",z);
}