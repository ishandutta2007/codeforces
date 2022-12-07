#include<bits/stdc++.h>
using namespace std;
struct Bian
{
	int s,t,last;
}bian[400010];
int last[200010],maxbian=0;
void addbian(int s,int t)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
queue<int> q;
int tp[400010];
int d1[400010],d2[400010],v[400010];
pair<int,int> p[400010],g[400010];
int z=0;
int main()
{	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>tp[i];
	for(int i=1;i<=m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		addbian(t1,t2);
		addbian(t2,t1);
	}
	q.push(1);
	v[1]=1;
	while(!q.empty())
	{
		int t1=q.front();
		q.pop();
		for(int j=last[t1];j;j=bian[j].last)
			if(v[bian[j].t]==0)
			{
				q.push(bian[j].t);
				d1[bian[j].t]=d1[t1]+1;
				v[bian[j].t]=1;
			}
	}
	memset(v,0,sizeof(v));
	q.push(n);
	v[n]=1;
	while(!q.empty())
	{
		int t1=q.front();
		q.pop();
		for(int j=last[t1];j;j=bian[j].last)
			if(v[bian[j].t]==0)
			{
				q.push(bian[j].t);
				d2[bian[j].t]=d2[t1]+1;
				v[bian[j].t]=1;
			}
	}	
	for(int i=1;i<=k;i++)
	{
		p[i].first=d1[tp[i]];
		p[i].second=d2[tp[i]];
	//	cout<<p[i].first<<' '<<p[i].second<<endl;
	}
	sort(p+1,p+k+1);
	int ans=0;
	for(int i=1;i<z;i++)
		ans=max(ans,min(g[i].first+g[i+1].second,g[i].second+g[i+1].first)+1);
	for(int i=1;i<=k;i++)
	{
		while(z>0)
		{
			ans=max(ans,min(p[i].first+g[z].second,p[i].second+g[z].first)+1);
			if(g[z].second<=p[i].second)
				z--;
			else
				break;
		}
		z++;
		g[z]=p[i];
	}
	ans=min(ans,d1[n]);
	if(ans==0)
		ans=d1[n];
	cout<<ans;
}