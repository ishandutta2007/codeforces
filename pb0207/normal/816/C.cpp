
 #include<cstdio>
#include<iostream>
using namespace std;

const int N=1e2+1e1+7;

int n,m,a[N][N],r[N],c[N],ans1[100001],ans2[100001],cnt;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		r[i]=0x7ffffff;
	for(int j=1;j<=m;j++)
		c[j]=0x7ffffff;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	if(n<m)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				r[i]=min(r[i],a[i][j]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				a[i][j]-=r[i];
			for(int j=1;j<=r[i];j++)
				ans1[++cnt]=i;
		}
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				c[j]=min(c[j],a[i][j]);
		for(int j=1;j<=m;j++)
		{	
			for(int i=1;i<=n;i++)
					a[i][j]-=c[j];
			for(int i=1;i<=c[j];i++)
				ans2[++cnt]=j;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]>0)
					goto ddd;
	}
	else
	{
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
				c[j]=min(c[j],a[i][j]);
		for(int j=1;j<=m;j++)
		{	
			for(int i=1;i<=n;i++)
				a[i][j]-=c[j];
			for(int i=1;i<=c[j];i++)
				ans2[++cnt]=j;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				r[i]=min(r[i],a[i][j]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				a[i][j]-=r[i];
			for(int j=1;j<=r[i];j++)
				ans1[++cnt]=i;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(a[i][j]>0)
					goto ddd;
	}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		if(ans1[i])
			cout<<"row "<<ans1[i]<<endl;
		else
			cout<<"col "<<ans2[i]<<endl;
	return 0;
	ddd:;
	cout<<"-1";
}