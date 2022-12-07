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
int o;
int lch1[1000010],rch1[1000010],lch2[1000010],rch2[1000010];
int bt1(int l,int r)
{
	o++;
	int i=o;
	if(l==r)
	{
		addbian(i,l,0);
		return i;
	}
	int mid=(l+r)>>1;
	lch1[i]=bt1(l,mid);
	rch1[i]=bt1(mid+1,r);
	addbian(i,lch1[i],0);
	addbian(i,rch1[i],0);
	return i;
}
int bt2(int l,int r)
{
	o++;
	int i=o;
	if(l==r)
	{
		addbian(l,i,0);
		return i;
	}
	int mid=(l+r)>>1;
	lch2[i]=bt2(l,mid);
	rch2[i]=bt2(mid+1,r);
	addbian(lch2[i],i,0);
	addbian(rch2[i],i,0);
	return i;
}
void insert1(int i,int l,int r,int x,int y,int z,int w)
{
	if(l==x&&r==y)
	{
		addbian(z,i,w);
		return;
	}
	int mid=(l+r)>>1;
	if(x>mid)
		insert1(rch1[i],mid+1,r,x,y,z,w);
	else
		if(y<=mid)
			insert1(lch1[i],l,mid,x,y,z,w);
		else
		{
			insert1(lch1[i],l,mid,x,mid,z,w);
			insert1(rch1[i],mid+1,r,mid+1,y,z,w);
		}
}
void insert2(int i,int l,int r,int x,int y,int z,int w)
{
	if(l==x&&r==y)
	{
		addbian(i,z,w);
		return;
	}
	int mid=(l+r)>>1;
	if(x>mid)
		insert2(rch2[i],mid+1,r,x,y,z,w);
	else
		if(y<=mid)
			insert2(lch2[i],l,mid,x,y,z,w);
		else
		{
			insert2(lch2[i],l,mid,x,mid,z,w);
			insert2(rch2[i],mid+1,r,mid+1,y,z,w);
		}
}
int main()
{	
	int n,m,s,rt1,rt2;
	cin>>n>>m>>s;
	o=n;
	rt1=bt1(1,n);
	rt2=bt2(1,n);
	for(int i=1;i<=m;i++)
	{
		int t1,t2,t3,t4,t5;
		scanf("%d%d%d%d",&t1,&t2,&t3,&t4);
		if(t1==1)
			addbian(t2,t3,t4);
		else
		{
			scanf("%d",&t5);
			if(t1==2)
				insert1(rt1,1,n,t3,t4,t2,t5);
			else
				insert2(rt2,1,n,t3,t4,t2,t5);
		}
	}
	for(int i=1;i<=o;i++)
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
	for(int i=1;i<=n;i++)
		if(d[i]<9e17)
			cout<<d[i]<<' ';
		else
			cout<<-1<<' ';
	
}