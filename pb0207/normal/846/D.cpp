#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

const int N=507;

int n,m,k,r[N][N],q,now[N][N],f[N][N];

bool check(int s)
{
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			now[i][j]=max(r[i][j]-s,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(now[i][j]>0)
				f[i][j]=0;
			else
				f[i][j]=min(f[i][j-1],min(f[i-1][j],f[i-1][j-1]))+1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(f[i][j]>=k)
				return true;
	return false;
}

int main()
{
	cin>>n>>m>>k>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			r[i][j]=1e9+7;
	for(int i=1;i<=q;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		r[x][y]=t;
	}
	int l=-1,r=1e9+1;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid;
	}
	if(!check(r))
		cout<<"-1";
	else
		cout<<r;
}