#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],vis[N],ans[N],cnt,T,p;

int r(int a)
{
	return a>0?a:-a;
}

int main()
{
	cin>>T;
	while(T--)
	{
		p=0;
		cnt=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=ans[i-1]+1;j<=(int)(1e6);j++)
			{
				bool flag=false;
				for(int k=1;k<=n;k++)
					if(vis[a[k]+j])
						flag=true;
				if(flag)
					continue;
				else
				{
					for(int k=1;k<=n;k++)
						vis[a[k]+j]=true;
					ans[i]=j;
					cnt++;
					break;
				}
			}
		if(cnt<n)
			cout<<"NO"<<endl;
		else
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
				cout<<ans[i]<<" ";
			cout<<endl;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				vis[a[i]+ans[j]]=0;
	}
}