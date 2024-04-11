#include <bits/stdc++.h>

using namespace std;

long long n,aa[5069],a[5069],mn[5069],e;

int main()
{
	long long t,rr,i,j;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		cin>>s;
		for(i=1;i<=n;i++)
		{
			aa[i]=s[i-1]-'a';
			mn[i]=1e18;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n-i+1;j++)
			{
				a[j]=aa[j+i-1];
			}
			for(j=1;j<=i-1;j++)
			{
				if((n-i+1)%2==0)
				{
					a[n-i+1+j]=aa[j];
				}
				else
				{
					a[n-i+1+j]=aa[i-j];
				}
			}
			for(j=1;j<=n;j++)
			{
				if(a[j]<mn[j])
				{
					j=-1;
					break;
				}
				else if(a[j]>mn[j])
				{
					break;
				}
			}
			if(j==-1)
			{
				for(j=1;j<=n;j++)
				{
					mn[j]=a[j];
				}
				e=i;
			}
		}
		for(i=1;i<=n;i++)
		{
			printf("%c",(char)mn[i]+'a');
		}
		printf("\n%lld\n",e);
	}
}