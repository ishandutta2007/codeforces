#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=3e5+1e3+7;

int n,a[N],ans,now,vis[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	ans=1;
	cout<<ans<<" ";
	vis[n+1]=1;
	now=n+1;
	for(int i=1;i<=n;++i)
	{
		vis[a[i]]=1;
		while(vis[now-1])
			now--;
		printf("%d ",i-n+now);
	}
}