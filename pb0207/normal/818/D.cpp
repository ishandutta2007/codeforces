#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

int n,a,b,col[N],cnt[N*10],can[N*10],vis[N*10];

int main()
{
	cin>>n>>a;
	for(int i=1;i<=n;i++)
		cin>>col[i];
	for(int i=1;i<=n;i++)
	{
		cnt[col[i]]++;
		if(cnt[col[i]]<=cnt[a])
			can[col[i]]=1;
	}
	for(int i=1;i<=1000000;i++)
		if(i!=a&&!can[i]&&cnt[i]>=cnt[a])
		{
			cout<<i;
			exit(0);
		}
	cout<<"-1";
}