#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

int n,a[N],vis[N],cnt,res[N],tot,ans,has[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],vis[a[i]]++;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]>1)
			cnt+=vis[i]-1;
		if(vis[i]==0)
			res[++tot]=i;
	}
	int now=1;
	for(int i=1;i<=n;i++)
	{
		if(now>tot)
			break;
		if(vis[a[i]]>1)
		{
			if(a[i]>res[now]||has[a[i]])
				vis[a[i]]--,a[i]=res[now],now++,ans++;
			else
				has[a[i]]=1;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}