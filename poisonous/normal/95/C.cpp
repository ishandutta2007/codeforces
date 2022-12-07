#include<bits/stdc++.h>
using namespace std;
struct Bian
{
	int s,t,last;
	int w;
}bian[2000010],bian2[2000010];
int last[1000010],maxbian=0,last2[1000010],maxbian2=0;
void addbian(int s,int t,int w)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].w=w;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
void addbian2(int s,int t,int w)
{
	maxbian2++;
	bian2[maxbian2].s=s;
	bian2[maxbian2].t=t;
	bian2[maxbian2].w=w;
	bian2[maxbian2].last=last2[s];
	last2[s]=maxbian2;
}
typedef pair<long long,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
long long d[1000010];
int v[1000010],t[1000010],c[1000010];

int main()
{	
	int n,m,x,y,rt1,rt2;
	cin>>n>>m>>x>>y;

	for(int i=1;i<=m;i++)
	{
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		addbian(t1,t2,t3);
		addbian(t2,t1,t3);
	}
	for(int i=1;i<=n;i++)
		scanf("%d%d",&t[i],&c[i]);
	for(int T=1;T<=n;T++)
	{
		for(int i=1;i<=n;i++)
		{
			v[i]=0;
			if(i==T)
				d[i]=0;
			else
				d[i]=(long long)(1e18);
		}
		q.push(make_pair(0,T));
		while(!q.empty())
		{
			int i=q.top().second;
			q.pop();
			if(v[i]==1)
				continue;
			v[i]=1;
			for(int j=last[i];j;j=bian[j].last)
				if(d[bian[j].t]>d[i]+bian[j].w)
				{
					d[bian[j].t]=d[i]+bian[j].w;
					q.push(make_pair(d[bian[j].t],bian[j].t));
				}
		}
		for(int i=1;i<=n;i++)
			if(d[i]<=t[T])
				addbian2(T,i,c[T]);
	}
	for(int i=1;i<=n;i++)
	{
		v[i]=0;
		if(i==x)
			d[i]=0;
		else
			d[i]=(long long)(1e18);
	}
	q.push(make_pair(0,x));
	while(!q.empty())
	{
		int i=q.top().second;
		q.pop();
		if(v[i]==1)
			continue;
		v[i]=1;
		for(int j=last2[i];j;j=bian2[j].last)
			if(d[bian2[j].t]>d[i]+bian2[j].w)
			{
				d[bian2[j].t]=d[i]+bian2[j].w;
				q.push(make_pair(d[bian2[j].t],bian2[j].t));
			}
	}
	if(d[y]>9e17)
		cout<<-1<<endl;
	else
		cout<<d[y];
	
}