#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll apple[200001],orange[200001];
ll n,m,i,j,k,t,t1,u,v,a,b;
vector<ll> lis;
int main()
{
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>n;
		lis.clear();
		for (i=1;i<=2*n-1;i++)
		{
			cin>>apple[i]>>orange[i];
			lis.push_back(i);
		}
		sort(lis.begin(),lis.end(),[](int a, int b){
			return (apple[a]>apple[b]);
		});
		u=0;
		for (i=1;i<=n-1;i++)
		{
			u+=orange[lis[2*i-1]];
			u-=orange[lis[2*i]];
		}
		if (u>=0)
		{
			cout<<"YES\n";
			cout<<lis[0]<<' ';
			for (i=1;i<=n-1;i++) cout<<lis[2*i-1]<<' ';
			cout<<endl;
		}
		else
		{
			cout<<"YES\n";
			cout<<lis[0]<<' ';
			for (i=1;i<=n-1;i++) cout<<lis[2*i]<<' ';
			cout<<endl;
		}
	}
}