#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],fq[100069];
string ky[3]={"Truth","Lie","Not defined"};

int main()
{
	long long i,c=0,sm=0,z;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		fq[abs(a[i])]+=a[i]/abs(a[i]);
		c+=a[i]<0;
	}
	for(i=1;i<=n;i++)
	{
		fq[i]+=c;
		sm+=fq[i]==m;
	}
	for(i=1;i<=n;i++)
	{
		if(fq[abs(a[i])]==m)
		{
			if(sm>1)
			{
				z=2;
			}
			else
			{
				z=0;
			}
		}
		else
		{
			z=1;
		}
		if(z!=2)
		{
			z^=a[i]<0;
		}
		printf("%s\n",ky[z].c_str());
	}
}