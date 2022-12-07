#include<bits/stdc++.h>
using namespace std;
struct Bian
{
	int s,t,last;
	long long w;
}bian[800010];
int last[400010],maxbian=0;
void addbian(int s,int t,long long w)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].w=w;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
typedef pair<long long,int> pii;
priority_queue<pii,vector<pii>,greater<pii> > q;
long long d[400010];
int v[400010];
int main()
{	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int t1,t2;
		long long t3;
		scanf("%d%d%lld",&t1,&t2,&t3);
		addbian(t1,t2,2*t3);
		addbian(t2,t1,2*t3);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&d[i]);
		q.push(make_pair(d[i],i));
	}
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
		cout<<d[i]<<' ';
	
}