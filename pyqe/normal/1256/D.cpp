#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<1000069> a;

int main()
{
	long long t,rr,i,c;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		cin>>s;
		for(i=0;i<n;i++)
		{
			a[i]=s[i]-'0';
		}
		c=0;
		for(i=0;i<n&&d;i++)
		{
			if(!a[i])
			{
				if(d<=i-c)
				{
					a[i]=1;
					a[i-d]=0;
					d=0;
				}
				else
				{
					a[i]=1;
					a[c]=0;
					d-=i-c;
				}
				c++;
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d",(bool)a[i]);
		}
		printf("\n");
	}
}