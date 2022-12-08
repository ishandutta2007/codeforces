#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=101;
int T,n,k,a[N],s,A,t;
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		s=a[1],A=0;
		for(int i=2;i<=n;i++)
		{
			if(100*a[i]>k*s)
				t=ceil(100.0*a[i]/k),A+=t-s,s=t;
			s+=a[i];
		}
		cout<<A<<'\n';
	}
	return 0;
}