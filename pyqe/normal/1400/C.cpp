#include <bits/stdc++.h>

using namespace std;

long long n,d;
bitset<100069> a,sq;

int main()
{
	long long t,rr,i,u,k;
	string s;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		cin>>s;
		scanf("%lld",&d);
		n=s.length();
		for(i=1;i<=n;i++)
		{
			a[i]=s[i-1]-'0';
			sq[i]=1;
		}
		for(i=1;i<=n;i++)
		{
			if(!a[i])
			{
				for(u=-1;u<=1;u+=2)
				{
					if(i+d*u>0&&i+d*u<=n)
					{
						sq[i+d*u]=0;
					}
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			k=0;
			for(u=-1;u<=1;u+=2)
			{
				if(i+d*u>0&&i+d*u<=n)
				{
					k|=sq[i+d*u];
				}
			}
			if(k!=a[i])
			{
				i=-1;
				break;
			}
		}
		if(i!=-1)
		{
			for(i=1;i<=n;i++)
			{
				printf("%lld",(long long)sq[i]);
			}
			printf("\n");
		}
		else
		{
			printf("-1\n");
		}
	}
}