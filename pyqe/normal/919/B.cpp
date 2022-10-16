#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long k,c=0,sz;
bool g,nd=false;
vector <long long> a;

void bf(long long m,long long z)
{
	if(m==0)
	{
		c++;
		if(c==k)
		{
			a.push_back(10-z);
			nd=true;
		}
		return;
	}
	int i=0;
	
	if(g)
	{
		i=1;
		g=false;
	}
	for(i=i;i<10;i++)
	{
		if(z+i<=10)
		{
			a.push_back(i);
			bf(m-1,z+i);
			if(nd)
			{
				return;
			}
			a.pop_back();
		}
		else
		{
			return;
		}
	}
}

int main()
{
	long long i;
	
	scanf("%lld",&k);
	for(i=1;i>0;i++)
	{
		g=true;
		bf(i,0);
		if(nd)
		{
			break;
		}
	}
	sz=a.size();
	for(i=0;i<sz;i++)
	{
		printf("%lld",a[i]);
	}
	printf("\n");
}