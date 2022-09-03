#include <bits/stdc++.h>
using namespace std;
int f[205],n,m,l[205],u[205];
long long a=1;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=n;i++)
	{
		memset(u,0,sizeof(u));
		int t=i,c=0;
		while(!u[t])l[t]=c++,u[t]=true,t=f[t];
		a=a/__gcd(a,c-l[t]*1ll)*(c-l[t]);
		m=max(m,l[t]);
	}
	cout<<max(a,(m-1)/a*a+a);
	return 0;
}