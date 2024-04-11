#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

const int N=1e5+1e3+7;

double d,r;

int n,ans;

double x[N],y[N],rd[N];

int main()
{
	cin>>r>>d;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>y[i]>>rd[i];
	for(int i=1;i<=n;i++)
	{
		double dis=sqrt(x[i]*x[i]+y[i]*y[i]);
		if(dis-rd[i]>=r-d&&dis+rd[i]<=r)
			ans++;	
	}
	cout<<ans;
}