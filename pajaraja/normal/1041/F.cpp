#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
int a[MAXN],b[MAXN];
map<int,int> mp[37];
int main()
{
	int n,m,t,sol=2;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d%d",&m,&t);
	for(int i=0;i<m;i++) scanf("%d",&b[i]);
	for(int j=1;j<=30;j++)
	{
		int x=(1<<j);
		for(int i=0;i<n;i++)
		{
			int t=++mp[j][a[i]%x];
			sol=max(t,sol);
		}
		for(int i=0;i<m;i++)
		{
			int t=++mp[j][(b[i]+x/2)%x];
			sol=max(t,sol);
		}
	}
	for(int i=0;i<n;i++)
	{
		int t=++mp[0][a[i]];
		sol=max(t,sol);
	}
	for(int i=0;i<m;i++)
	{
		int t=++mp[0][b[i]];
		sol=max(t,sol);
	}
	printf("%d",sol);
}