#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1,I=1e18;
int T,n,a[N],q[N],t,x,y,A;
signed main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		t=x=y=0,A=I;
		for(int i=1;i<=n;i++)
			if(a[i]&1)
				q[++t]=i;
		if(abs(n-2*t)>1)
		{
			cout<<-1<<'\n';
			continue;
		}
		if((n+1)/2==t)
		{
			for(int i=1;i<=t;i++)
				x+=abs(q[i]-2*i+1);
			A=min(A,x);
		}
		if(n/2==t)
		{
			for(int i=1;i<=t;i++)
				y+=abs(q[i]-2*i);
			A=min(A,y);
		}
		cout<<A<<'\n';
	}
	return 0;
}