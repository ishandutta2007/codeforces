#include<bits/stdc++.h>
#define int long long
using namespace std;

int ans,n,m,a,b=1;

signed main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>a;
		int minn=a-b<0?a-b+n:a-b;
		ans+=minn;
		b=a;
	}
	cout<<ans;
}