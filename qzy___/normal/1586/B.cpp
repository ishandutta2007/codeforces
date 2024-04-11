#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+1;
int T,n,m,x,y,z,v[N];
signed main()
{
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			v[i]=0;
		for(int i=1;i<=m;i++)
			cin>>x>>y>>z,v[y]=1;
		for(int i=1;i<=n;i++)
			if(!v[i])
				x=i;
		for(int i=1;i<=n;i++)
			if(i!=x)
				cout<<i<<' '<<x<<'\n';
	}
	return 0;
}