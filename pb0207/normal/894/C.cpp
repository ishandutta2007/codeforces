#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e4+1e3+7;

int s[N],n,a[N],vis[1000001],has[1000001];
int main()
{
	cin>>n;
	int totg=0;
	for(int i=1;i<=n;i++)
		cin>>s[i],vis[s[i]]=true;
	for(int i=1;i<=n;i++)
	{
		totg=__gcd(totg,s[i]);
		if(!vis[totg])
		{
			puts("-1");
			return 0;
		}
	}
	printf("%d\n",n*2);
	for(int i=1;i<=n;i++)
		printf("%d %d ",s[i],totg);
}