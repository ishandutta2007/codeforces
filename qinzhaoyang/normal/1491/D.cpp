#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=31;
int T,x,y,t,c,q[N],p[N],A;
signed main()
{
	cin>>T;
	while(T--&&cin>>x>>y)
	{
		if(y<x)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		for(int i=30;i>=0;i--)
			if(((x>>i)&1)&&((y>>i)&1))
				x-=(1<<i),y-=(1<<i);
			else
				break;
		t=c=0,A=1;
		for(int i=0;i<31;i++)
		{
			if((x>>i)&1)
				q[++t]=i;
			if((y>>i)&1)
				p[++c]=i;
		}
		for(int i=1;i<=c;i++)
			if(q[i]>p[i])
				A=0;
		if(A==0||t<c)
			cout<<"NO"<<'\n';
		else
			cout<<"YES"<<'\n';
	}
	return 0;
}