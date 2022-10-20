#include<bits/stdc++.h>
using namespace std;
const int N=502,I=1e9;
int T,n,x,a[N],p[N],q[N],t,v,c,A;
int main()
{
	cin>>T;
	while(T--&&cin>>n>>x)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			p[i]=a[i];
		p[n+1]=x,sort(p+1,p+n+2),A=I;
		for(int i=1;i<=n+1;i++)
		{
			t=0,v=1,c=n;
			for(int j=1;j<=n+1;j++)
				if(j!=i)
					q[++t]=p[j];
			for(int j=1;j<=n;j++)
				if(q[j]>a[j])
					v=0;
			for(int j=1;j<=n;j++)
				if(q[j]==a[j])
					c--;
			if(v)
				A=min(A,c);
		}
		if(A==I)
			cout<<-1<<'\n';
		else
			cout<<A<<'\n';
	}
	return 0;
}