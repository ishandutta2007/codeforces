#include <iostream>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

long long pw(long long a,long long p,long long mod)
{
	a %= mod;
	if(p<=0) return 1;
	long long b = pw(a,p/2,mod);
	if(!(p%2)) return (b*b)%mod;
	return (((b*b)%mod)*a)%mod;
}

void slow(int C,int a,int b,int u,int v)
{
	int best = 0;
	for(int m=0;(u*m)<=C;m++)
	{
		int n = (C-u*m)/v;
		best = max(best,a*m+b*n);
//		cout << a*m+b*n << endl;
	}
	cout << best << endl;
}

int main()
{
	long long C,a,b,u,v;
	cin >> C >> a >> b >> u >> v;
//	slow(C,a,b,u,v);
	long long best = 0;
	long long x,y;
	if(v>u)
	{
		swap(v,u);
		swap(b,a);
	}
	if(u > C)
	{
		best = b*(C/v);
	}
	else if(u>1000)
	{
		for(int m=0;(u*m)<=C;m++)
			best = max(best,a*m+b*((C-u*m)/v));
	}
	else
	{
		long long tu = u;
		long long tv = v;
		long long gdiv = gcd(tu,tv);
		u /= gdiv;
		v /= gdiv;
		int totu = 0;
		for(int i=1;i<u;i++)
			if(gcd(i,u)==1) totu++;
		int totv = 0;
		for(int i=1;i<v;i++)
			if(gcd(i,v)==1) totv++;
		for(long long W=max(0LL,C+1-tv);W<=C;W++)
		{
			long long w = W/gdiv;
			if(b*u > a*v)
			{
				//minimize x
				x = (w*pw(u,totv-1,v))%v;
				y = (w-u*x)/v;
				best = max(best,a*x+b*y);
			}
			else
			{
				//minimize y
				y = (w*pw(v,totu-1,u))%u;
				x = (w-v*y)/u;
				best = max(best,a*x+b*y);
			}
		}
	}
	cout << best << endl;
	return 0;
}