#include<bits/stdc++.h>
using namespace std;
int n;
long long x[5555],y[5555];
int p[5555];
int chk(int i,int j,int k)
{
	return (x[i]-x[j])*(x[k]-x[j])+(y[i]-y[j])*(y[k]-y[j])>0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i];
		p[i]=i;
	}
	random_shuffle(p+1,p+n+1);
	for(int tt=1;tt<=2*n;tt++)
	{
		for(int i=1;i<n-1;i++)
		{
			if(!chk(p[i],p[i+1],p[i+2]))
				swap(p[i+1],p[i+2]);
		}
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<' ';
	return 0;
}