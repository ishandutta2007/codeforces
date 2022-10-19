//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
ll n,m;
int main(){
	ll i,j,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		if(n%2==1&&m%2==1)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(i==0||i==n-1)
					{
						if(j%2==0)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else if(i%2==0)
					{
						if(j==0||j==m-1)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else
					{
						putchar('0');
					}
				}
				puts("");
			}
		}
		else if(n%2==0&&m%2==0)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(i==0)
					{
						if(j%2==0&&j!=0)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else if(i==n-1)
					{
						if(j%2==1&&j!=m-1)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else if(i%2==0)
					{
						if(j==m-1)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else
					{
						if(j==0)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
				}
				puts("");
			}
		}
		else if(n%2==0)
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(j==0||j==m-1)
					{
						if(i%2==0)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else if(i==0||i==n-1)
					{
						if(j%2==0)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else
					{
						putchar('0');
					}
				}
				puts("");
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					if(i==0||i==n-1)
					{
						if(j%2==0)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else if(i%2==0)
					{
						if(j==0||j==m-1)
						{
							putchar('1');
						}
						else
						{
							putchar('0');
						}
					}
					else
					{
						putchar('0');
					}
				}
				puts("");
			}
		}
	}
	return 0;
}