#include<cstdio>
#include<iostream>
using namespace std;

const int N=1e2+1e1+7;

long long a[N][N],n,m,ans;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		long long tota=0,totb=0;
		for(int j=1;j<=m;j++)
		{
			tota+=a[i][j];
			totb+=!(a[i][j]);
		}
		ans+=((1ll<<tota)-1ll)+((1ll<<totb)-1ll);
	}
	for(int i=1;i<=m;i++)
	{
		long long tota=0,totb=0;
		for(int j=1;j<=n;j++)
		{
			tota+=a[j][i];
			totb+=!(a[j][i]);
		}
		ans+=((1ll<<tota)-1ll)+((1ll<<totb)-1ll);
	}
	cout<<ans-n*m;
}