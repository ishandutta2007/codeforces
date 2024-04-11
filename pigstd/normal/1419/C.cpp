#include<bits/stdc++.h>
using namespace std;

const int M=1e3+10;
int T;
int n,a[M],x;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>x;bool flag=1,flag2=0;int sum=0;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i],sum+=a[i];
			if (a[i]!=x)flag=0;
			if (a[i]==x)flag2=1;
		}
		if (flag)puts("0");
		else if (sum==x*n||flag2)puts("1");
		else puts("2");
	}
	return 0;
}