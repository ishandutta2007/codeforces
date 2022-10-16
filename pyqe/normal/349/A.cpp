#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long d[3]={0,0,0},k,n,i;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k==25)
		{
			d[0]++;
		}
		else if(k==50)
		{
			if(d[0]==0)
			{
				i=-1;
				break;
			}
			d[0]--;
			d[1]++;
		}
		else if(k==100)
		{
			if(d[1]==0)
			{
				if(d[0]<3)
				{
					i=-1;
					break;
				}
				d[0]-=3;
			}
			else
			{
				if(d[0]==0)
				{
					i=-1;
					break;
				}
				d[0]--;
				d[1]--;
			}
			d[2]++;
		}
	}
	if(i==-1)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
	}
}