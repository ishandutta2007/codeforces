#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+1;
int f[N],T,n,m,a[N],c[N],A,B,x;
signed main()
{
	ios::sync_with_stdio(0);
	for(int i=1;i<N;i++)
		if(!f[i])
		{
			f[i]=i;
			for(int j=1;i*j*j<N;j++)
				f[i*j*j]=i;
		}
	cin>>T;
	while(T--&&cin>>n)
	{
		A=B=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],c[f[a[i]]]++;
		for(int i=1;i<=n;i++)
			A=max(A,c[f[a[i]]]);
		for(int i=1;i<=n;i++)
			if(f[a[i]]!=1&&c[f[a[i]]]%2==0)
				B+=c[f[a[i]]],c[f[a[i]]]=0;
		cin>>m;
		while(m--&&cin>>x)
			if(x)
				cout<<max(A,B+c[1])<<'\n';
			else
				cout<<A<<'\n';
		for(int i=1;i<=n;i++)
			c[f[a[i]]]=0;
	}
	return 0;
}