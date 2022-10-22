#include<cstdio>
#include<iostream>
using namespace std;

const int N=17;

int n,m,ans,pos=1,cnt,f[17][2];

char s[16][101];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m+2;j++)
			cin>>s[i][j];
	for(int i=1;i<=n;i++)
	{
		int flag=false;
		for(int j=1;j<=m+2;j++)
			if(s[i][j]=='1')
				flag=true;
		if(flag)
		{
			cnt=i;
			break;
		}
	}
	if(cnt==0)
	{
		cout<<0;
		return 0;
	}
	if(cnt==n)
	{
		int l=m+2,r=1;
		for(int j=1;j<=m+2;j++)
			if(s[n][j]=='1')
				l=min(l,j),r=max(r,j);
		cout<<r-1;
		return 0;
	}
	int l=m+2,r=1;
		for(int j=1;j<=m+2;j++)
			if(s[n][j]=='1')
				l=min(l,j),r=max(r,j);
	f[n][0]=(r-1)*2;
	f[n][1]=m+1;
	for(int i=n-1;i>=cnt+1;i--)
	{
		l=m+2,r=1;
		for(int j=1;j<=m+2;j++)
			if(s[i][j]=='1')
				l=min(l,j),r=max(r,j);
		f[i][0]=min(f[i+1][0]+(r-1)*2,f[i+1][1]+m+1)+1;
		f[i][1]=min(f[i+1][0]+m+1,f[i+1][1]+(m+2-l)*2)+1;
	}
	l=m+2,r=1;
	for(int j=1;j<=m+2;j++)
		if(s[cnt][j]=='1')
				l=min(l,j),r=max(r,j);
	f[cnt][0]=f[cnt+1][1]+m+2-l+1;
	f[cnt][1]=f[cnt+1][0]+r-1+1;
	cout<<min(f[cnt][0],f[cnt][1]);
}