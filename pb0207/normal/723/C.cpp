#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e3+1e2+7;

int n,m,cnt,b[N],a[N],tot,ans[N];

int r[N];

int main()
{
	cin>>n>>m;
	tot=n/m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=m&&b[a[i]]<tot)
			b[a[i]]++;
		else
			r[++cnt]=i;
	}
	int ps=1;
	for(int i=1;i<=m;i++)
	{
		if(b[i]<tot)
		{
			for(;ps<=cnt&&b[i]<tot;ps++)
				b[i]++,ans[r[ps]]=i;
		}
	}
	cout<<tot<<" "<<(ps-1)<<endl;
	for(int i=1;i<=n;i++)
		if(!ans[i])
			cout<<a[i]<<" ";
		else
			cout<<ans[i]<<" ";
}