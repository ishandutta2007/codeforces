#include <bits/stdc++.h>

using namespace std;

long long n;
bitset<39> a;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		n--;
		for(k=1,i=1;i<=38;i++,k*=3);
		a.reset();
		for(i=38;i>=0;i--,k/=3)
		{
			if(n>=k)
			{
				n-=k;
				a[i]=1;
			}
		}
		for(i=0;a[i];a[i]=0,i++);
		a[i]=1;
		z=0;
		for(k=1,i=0;i<=38;i++,k*=3)
		{
			if(a[i])
			{
				z+=k;
			}
		}
		printf("%lld\n",z);
	}
}