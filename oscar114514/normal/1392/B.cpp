#include<bits/stdc++.h>
using namespace std;
int T,n;
long long m;
int a[233333];
void gao()
{
	int maxx=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		maxx=max(maxx,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=maxx-a[i];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int t=1;t<=min(10ll,m);t++)
		{
			gao();
		}
		if(!(m<=10||(m-10)%2==0))gao();
		for(int i=1;i<=n;i++)
		{
			cout<<a[i]<<' ';
		}
		cout<<endl;
	}
	return 0;
}