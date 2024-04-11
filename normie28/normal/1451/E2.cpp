#include <bits/stdc++.h>
using namespace std;
int n,m,i,j,k,t,u,v,c0,c2;
int arr[70001],found[70001];
int main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for (i=2;i<=n;i++)
	{
		cout<<"XOR "<<1<<' '<<i<<endl;
		cin>>arr[i];
	}
	for (i=1;i<=n;i++)
	{
		if (!found[arr[i]])
		{
			found[arr[i]]=i;
		}
		else
		{
			cout<<"AND "<<found[arr[i]]<<' '<<i<<endl;
			cin>>u;
			u^=arr[i];
			cout<<"! ";
			for (j=1;j<=n;j++) cout<<(arr[j]^u)<<' ';
			cout<<endl;
			return 0;
		}
	}
//			for (i=1;i<=n;i++) cout<<(arr[i])<<' ';
//			cout<<endl;
	for (i=2;i<=n;i++) if (arr[i]==1) break;
	cout<<"AND "<<1<<' '<<i<<endl;
	cin>>u;
	u>>=1;
	u<<=1;
	for (i=1;i<=n;i++) arr[i]^=u;
//			for (i=1;i<=n;i++) cout<<(arr[i])<<' ';
//			cout<<endl;
	for (i=1;i<=n;i++) if (arr[i]==0) c0=i;
	else if (arr[i]==2) c2=i;
	cout<<"AND "<<c0<<' '<<c2<<endl;
	cin>>u;
	if (u)
	{
		for (i=1;i<=n;i++) arr[i]^=1;
	}
			cout<<"! ";
			for (i=1;i<=n;i++) cout<<(arr[i])<<' ';
			cout<<endl;
			return 0;
}