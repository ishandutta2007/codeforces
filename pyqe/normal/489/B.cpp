#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n,m,i,p=0,q=0,c=0;
	
	scanf("%lld",&n);
	long long a[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	sort(a,a+n);
	scanf("%lld",&m);
	long long b[m];
	for(i=0;i<m;i++)
	{
		scanf("%lld",b+i);
	}
	sort(b,b+m);
	while(p<n&&q<m)
	{
		if(abs(a[p]-b[q])<=1)
		{
			p++;
			q++;
			c++;
		}
		else
		{
			if(p==n-1&&q==m-1)
			{
				break;
			}
			else if(p==n-1)
			{
				q++;
			}
			else if(q==m-1)
			{
				p++;
			}
			else if(a[p+1]==b[q]+1)
			{
				p++;
			}
			else if(b[q+1]==a[p]+1)
			{
				q++;
			}
			else if(a[p+1]<b[q+1])
			{
				p++;
			}
			else if(a[p+1]>b[q+1])
			{
				q++;
			}
			else if(a[p]<b[q])
			{
				p++;
			}
			else if(a[p]>b[q])
			{
				q++;
			}
		}
	}
	printf("%lld\n",c);
}