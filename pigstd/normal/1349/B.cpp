#include<bits/stdc++.h>
using namespace std;

const int M=1e5+10;
int a[M],n,k,T;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		int flag=0;//k 
		for (int i=1;i<=n;i++)
			if (a[i]==k)
				flag=1;
		if (!flag)
			{puts("no");continue;}
		for (int i=1;i<=n;i++)
			if (a[i]>=k)a[i]=1;
			else a[i]=0;
		if (n==1)
			{puts("yes");continue;}
		if (n==2)
		{
			if (a[1]&&a[2]){puts("yes");continue;}
			else {puts("no");continue;}
		}
		int flags=0;
		for (int i=1;i<=n-2;i++)
			if (a[i]+a[i+1]+a[i+2]>=2)
				{flags=1;break;}
		if (!flags)puts("no");
		else puts("yes");
	}
	return 0;
}