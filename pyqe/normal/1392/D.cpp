#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[200069];

int main()
{
	long long t,rr,i,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		nn=0;
		for(i=0;i<n;i++)
		{
			if(!i||s[i]!=s[i-1])
			{
				nn++;
				a[nn]=0;
			}
			a[nn]++;
		}
		if(nn==1)
		{
			a[1]+=2;
		}
		else if(nn%2)
		{
			a[1]+=a[nn];
			nn--;
		}
		z=0;
		for(i=1;i<=nn;i++)
		{
			z+=a[i]/3;
		}
		printf("%lld\n",z);
	}
}