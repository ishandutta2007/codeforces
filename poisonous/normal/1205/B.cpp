#include<bits/stdc++.h>
using namespace std;
long long num[100010];
int d[130][130][130];
queue<pair<int,int> >q;
int np[65],a[65][4];
struct Bian
{
	int s,t,last;
}bian[100010];
int m,last[130];
void addbian(int s,int t)
{
	m++;
	bian[m].s=s;
	bian[m].t=t;
	bian[m].last=last[s];
	last[s]=m;
}
int main()
{
	int n;
	cin>>n;
	int k=1;
	for(int i=1;i<=n;i++)
	{
		cin>>num[k];
		int x=0;
		for(int j=0;j<63;j++)
			if(num[k]&(1ll<<j))
				x++;
		if(x>=1)
			k++;
	}
	n=k;
	for(int i=1;i<=n;i++)
		for(int j=0;j<63;j++)
			if(num[i]&(1ll<<j))
			{
				np[j]++;
				if(np[j]>=3)
				{
					cout<<3<<endl;
					return 0;
				}
				a[j][np[j]]=i;
			}
	int ans=100000000;
	for(int j=0;j<63;j++)
		if(np[j]>=2)
		{
			addbian(a[j][1],a[j][2]);
			addbian(a[j][2],a[j][1]);
		}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
				if(bian[j].s==i)
				{
					if(d[i][i][bian[j].t]==0)
					{
						d[i][i][bian[j].t]=1;
						q.push(make_pair(i,bian[j].t));
					}
				}			
		}
		while(!q.empty())
		{
			pair<int,int> p=q.front();
			q.pop();
			if(p.second==i)
			{
				ans=min(ans,d[i][p.first][p.second]);
				continue;
			}
			for(int j=last[p.second];j;j=bian[j].last)
				if(bian[j].t!=p.first)
					if(d[i][p.second][bian[j].t]==0)
					{
						d[i][p.second][bian[j].t]=d[i][p.first][p.second]+1;
						q.push(make_pair(p.second,bian[j].t));
					}
		}
	}
	if(ans<100000000)
		cout<<ans;
	else
		cout<<-1;
}