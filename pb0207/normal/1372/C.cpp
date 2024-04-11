#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=3e5+1e3+7;

int n,a[N],T;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		bool a0=1,a1=1,a2=1;
		for(int i=1;i<=n;i++)
			a0&=a[i]==i;
		if(a0)
		{
			puts("0");
			continue;
		}
		int fs=n+1,ls=0;
		for(int i=1;i<=n;i++)
			if(a[i]!=i)
			{
				fs=min(fs,i);
				ls=max(ls,i);
			}
		for(int i=fs;i<=ls;i++)
			a1&=a[i]!=i;
		for(int i=1;i<fs;i++)
			a1&=a[i]==i;
		for(int i=ls+1;i<=n;i++)
			a1&=a[i]==i;
		if(a1)
		{
			puts("1");
			continue;
		}
		puts("2");
	}
}