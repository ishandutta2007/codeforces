#include<bits/stdc++.h>
using namespace std;
int num[3510];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k;
		cin>>n>>k>>m;
		for(int i=1;i<=n;i++)
			cin>>num[i];
		m=min(m,k-1);
		int ans=-1000000000;
		for(int i=0;i<=m;i++)
		{
			int nans=1000000000;
			for(int j=i+1;j+(m-i)+(n-k+1)-1<=n;j++)
				nans=min(nans,max(num[j],num[j+(n-k+1)-1]));
			ans=max(ans,nans);
		}
		cout<<ans<<endl;
	}
}