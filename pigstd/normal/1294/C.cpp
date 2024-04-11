#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int T;
 
signed main()
{
    cin>>T;
    for (int kkk=1;kkk<=T;kkk++)
	{
		int a;
		scanf("%lld",&a);
		int sum=0,q=a;
		bool flag=0;
		for (int i=2;i<=sqrt(a);i++)
		{
			if (q%i==0)
			{
				q/=i,sum++;
			}
			if (sum==2&&q!=1)
			{
				if (q<=i)
					break;
				else
					{flag=1;break;}
			}
		}
		if (!flag)
			printf("NO\n");
		else
		{
			printf("YES\n");
            q=a;sum=0;
			for (int i=2;i<=sqrt(q);i++)
			{
				if (q%i==0)
				{
					q/=i,sum++;
					printf("%d ",i);
					if (sum==2)
					{
						printf("%d\n",q);
						break;
					}
				}
				if (sum==2)
					break;
			}
		}
	}
	return 0;
}