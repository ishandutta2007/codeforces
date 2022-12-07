#include<bits/stdc++.h>
using namespace std;
struct Bian
{
	int s,t,last;
	int w;
}bian[8000010];
int last[1000010],maxbian=0;
void addbian(int s,int t,int w)
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
long long d[1000010];
int v[1000010];

int main()
{	
	int n,m,s,rt1,rt2;
	cin>>n>>m>>s;

	for(int i=1;i<=m;i++)
	{
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		addbian(t1,t2,t3);
		addbian(t2,t1,t3);
	}
	for(int i=1;i<=n;i++)
	{
		if(i==s)
			d[i]=0;
		else
			d[i]=(long long)(1e18);
	}
	q.push(make_pair(0,s));
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
	int ds,ans=0;
	cin>>ds;
	for(int i=1;i<=n;i++)
		if(d[i]==ds)
			ans++;
	for(int i=1;i<=maxbian;i++)
		if(d[bian[i].s]<ds&&d[bian[i].s]+bian[i].w>ds)
			if(d[bian[i].s]+d[bian[i].t]+bian[i].w>=2*ds)
			ans++;
	for(int i=1;i<=maxbian;i+=2)
		if(d[bian[i].s]<ds&&d[bian[i].s]+bian[i].w>ds)
			if(d[bian[i].s]+d[bian[i].t]+bian[i].w==2*ds)
				ans--;
	cout<<ans<<endl;
	
}