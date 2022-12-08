#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1,I=1e9;
int A,B,C,D,X,Y,Z,u,v,l,r,s=I;
pair<int,int>a[N],b[N],c[N],d[N];
vector<int>x[N],y[N],z[N]; 
signed main()
{
	cin>>A>>B>>C>>D;
	for(int i=1;i<=A;i++)
		cin>>a[i].first,a[i].second=i;
	for(int i=1;i<=B;i++)
		cin>>b[i].first,b[i].second=i;
	for(int i=1;i<=C;i++)
		cin>>c[i].first,c[i].second=i;
	for(int i=1;i<=D;i++)
		cin>>d[i].first,d[i].second=i;
	cin>>X;
	for(int i=1;i<=X;i++)
		cin>>u>>v,x[u].push_back(v);
	for(int i=1;i<=X;i++)
		sort(x[i].begin(),x[i].end());
	cin>>Y;
	for(int i=1;i<=Y;i++)
		cin>>u>>v,y[u].push_back(v);
	for(int i=1;i<=Y;i++)
		sort(y[i].begin(),y[i].end());
	cin>>Z;
	for(int i=1;i<=Z;i++)
		cin>>u>>v,z[u].push_back(v);
	for(int i=1;i<=Z;i++)
		sort(z[i].begin(),z[i].end());
	sort(d+1,d+D+1);
	for(int i=1;i<=C;i++)
		if(!z[i].size())
			c[i].first+=d[1].first;
		else
		{
			v=0;
			for(int j=1;j<=D;j++)
			{
				l=0,r=z[i].size()-1;
				while(l<r)
					if(z[i][(l+r)/2]<d[j].second)
						l=(l+r)/2+1;
					else
						r=(l+r)/2;
				if(z[i][l]!=d[j].second)
				{
					c[i].first+=d[j].first,v=1;
					break;
				}
			}
			if(!v)
				c[i].first=I;
		}
	sort(c+1,c+C+1);
	for(int i=1;i<=B;i++)
		if(!y[i].size())
			b[i].first+=c[1].first;
		else
		{
			v=0;
			for(int j=1;j<=C;j++)
			{
				l=0,r=y[i].size()-1;
				while(l<r)
					if(y[i][(l+r)/2]<c[j].second)
						l=(l+r)/2+1;
					else
						r=(l+r)/2;
				if(y[i][l]!=c[j].second)
				{
					b[i].first+=c[j].first,v=1;
					break;
				}
			}
			if(!v)
				b[i].first=I;
		}
	sort(b+1,b+B+1);
	for(int i=1;i<=A;i++)
		if(!x[i].size())
			a[i].first+=b[1].first;
		else
		{
			v=0;
			for(int j=1;j<=B;j++)
			{
				l=0,r=x[i].size()-1;
				while(l<r)
					if(x[i][(l+r)/2]<b[j].second)
						l=(l+r)/2+1;
					else
						r=(l+r)/2;
				if(x[i][l]!=b[j].second)
				{
					a[i].first+=b[j].first,v=1;
					break;
				}
			}
			if(!v)
				a[i].first=I;
		}
	for(int i=1;i<=A;i++)
		s=min(s,a[i].first);
	if(s==I)
		cout<<-1;
	else
		cout<<s;
	return 0;
}