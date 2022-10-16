#include <bits/stdc++.h>

using namespace std;

long long n,sz=0,p=0,c=0,xx;
vector<long long> v,w;

void bf(long long z)
{
	if(p==sz)
	{
		if(xx/z>n)
		{
			return;
		}
		c++;
		return;
	}
	
	long long i,k=1;
	
	for(i=0;i<=w[p];i++)
	{
		p++;
		bf(z*k);
		p--;
		k*=v[p];
		if(z*k>n)
		{
			return;
		}
	}
}

int main()
{
	long long x,i;
	
	scanf("%lld%lld",&n,&x);
	xx=x;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			v.push_back(i);
			w.push_back(0);
			sz++;
			while(x%i==0)
			{
				x/=i;
				w[sz-1]++;
			}
		}
	}
	if(x>1)
	{
		v.push_back(x);
		w.push_back(1);
		sz++;
		x=1;
	}
	bf(1);
	printf("%lld\n",c);
}