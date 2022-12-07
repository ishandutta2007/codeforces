#include<bits/stdc++.h>
using namespace std;
struct Bian
{
	int s,t,w,last;
}bian[800010];
int last[400010],maxbian=0;
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
long long d[400010];
int x[400010],pre[400010],v[400010],y[400010];
queue<int> qu;
int main()
{	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int t1,t2,t3;
		scanf("%d%d%d",&t1,&t2,&t3);
		addbian(t1,t2,t3);
		addbian(t2,t1,t3);
	}
	for(int i=2;i<=n;i++)
		d[i]=(long long)(1e18);
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		pii p=q.top();
		q.pop();
		int i=p.second;
		if(v[i])
			continue;
		v[i]=1;
		for(int j=last[i];j;j=bian[j].last)
			if(d[bian[j].t]>d[i]+bian[j].w)
			{
				d[bian[j].t]=d[i]+bian[j].w;
				pre[bian[j].t]=j;
				q.push(make_pair(d[bian[j].t],bian[j].t));
			}
	}
	for(int i=2;i<=n;i++)
		x[bian[pre[i]].s]++;
	for(int i=1;i<=n;i++)
		if(x[i]==0)
			qu.push(i);
	int a=n-1;
	while(a>k)
	{
		int tmp=qu.front();
		qu.pop();
		y[tmp]=1;
		x[bian[pre[tmp]].s]--;
		if(x[bian[pre[tmp]].s]==0)
			qu.push(bian[pre[tmp]].s);
		a--;
	}
	cout<<a<<endl;
	for(int i=2;i<=n;i++)
		if(y[i]==0)
			cout<<(pre[i]+1)/2<<' ';
	cout<<endl;
}