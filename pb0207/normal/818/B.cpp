#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e2+1e1+7;

int n,m,l[N],vis[N],a[N];

int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>l[i];
	for(int i=2;i<=m;i++)
	{
		int k=l[i]-l[i-1];
		if(k<=0)
			k+=n;
		if(a[l[i-1]]==0)
		{
			if(vis[k])
			{
				cout<<"-1";
				return 0;
			}
			a[l[i-1]]=k;
			vis[k]=1;
		}
		if(a[l[i-1]]!=k)
		{
			cout<<"-1";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
		if(!a[i])
		{
			for(int j=1;j<=n;j++)
			{
				if(!vis[j])
				{
					a[i]=j,vis[j]=1;
					break;
				}
			}
		}
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}