#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int T,n,m,x,y,q[N],t,b,v[N],c[N],A;
vector<int>a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			a[i].clear(),v[i]=c[i]=0;
		while(m--&&cin>>x>>y)
			a[x].push_back(y),a[y].push_back(x);
		q[++t]=1,b=1,A=0;
		while(t)
		{
			x=q[t--];
			if(v[x])
				continue;
			v[x]=c[x]=1,A++;
			for(int i=0;i<a[x].size();i++)
			{
				y=a[x][i];
				if(!v[y])
					for(int j=0;j<a[y].size();j++)
						q[++t]=a[y][j];
				v[y]=1;
			}
		}
		for(int i=1;i<=n;i++)
			if(!v[i])
				b=0;
		if(b)
		{
			cout<<"YES"<<'\n'<<A<<'\n';
			for(int i=1;i<=n;i++)
				if(c[i])
					cout<<i<<' ';
			cout<<'\n';
		}
		else
			cout<<"NO"<<'\n';
	}
	return 0;
}