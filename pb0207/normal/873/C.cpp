#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101][101],n,m,k,suf[101][101],pre[101][101],mx[101],ans1,ans2;

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],pre[i][j]=pre[i-1][j]+a[i][j];
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
		{
			for(int t=1;t<=min(k,n-i+1);t++)
				suf[i][j]+=a[i+t-1][j];
			mx[j]=max(mx[j],suf[i][j]);
		}
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++)
			if(suf[i][j]==mx[j])
			{
				ans1+=mx[j];
				ans2+=pre[i-1][j];
				break;
			}
	cout<<ans1<<" "<<ans2;
}