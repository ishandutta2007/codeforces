#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,a[N],f[N],g[N],c,x;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		if(a[i]>a[i-1])
			f[i]=f[i-1]+1,x=max(f[i],x);
	for(int i=n-1;i>=1;i--)
		if(a[i]>a[i+1])
			g[i]=g[i+1]+1,x=max(g[i],x);
	for(int i=1;i<=n;i++)
		c+=(f[i]==x)+(g[i]==x);
	if(c>2)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
		if(f[i]==x&&g[i]==x&&x%2==0)
		{
			cout<<1;
			return 0;
		}
	cout<<0;
	return 0;
}