#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long t,rr,i,z;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		n=s.length();
		z=0;
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1];
			if((i>1&&a[i]==a[i-1])||(i>2&&a[i]==a[i-2]))
			{
				z++;
				a[i]=-1;
			}
		}
		printf("%lld\n",z);
	}
}