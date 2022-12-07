#include<bits/stdc++.h>
using namespace std;
set<int> s[200010];
struct Bian
{
	int s,t,last;
}bian[200010];
int last[200010],maxbian=0;
void addbian(int s,int t)
{
	maxbian++;
	bian[maxbian].s=s;
	bian[maxbian].t=t;
	bian[maxbian].last=last[s];
	last[s]=maxbian;
}
vector<int> vv[200010];
int v[200010],d[200010];
queue<int> q;
int r[200010],cs[200010];
int main()
{
	int n,m,z;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		vv[t1].push_back(t2);
		addbian(t2,t1);
	}
	cin>>z;
	for(int i=1;i<=z;i++)
		cin>>r[i];
	v[r[z]]=1;
	q.push(r[z]);
	while(!q.empty())
	{
		int t1=q.front();
		q.pop();
		for(int j=last[t1];j;j=bian[j].last)
			if(v[bian[j].t]==0)
			{
				v[bian[j].t]=1;
				d[bian[j].t]=d[t1]+1;
				q.push(bian[j].t);
			}
	}
	for(int i=1;i<=n;i++)
	{
		int sz=vv[i].size();
		for(int j=0;j<sz;j++)
			if(d[vv[i][j]]==d[i]-1)
			{
				if(cs[i]==0)
					cs[i]=vv[i][j];
				else
					cs[i]=-1;
			}
	}
	int mn=0,mx=0;
	for(int i=1;i<z;i++)
	{
		if(cs[r[i]]!=r[i+1])
			mx++;
		if(d[r[i]]!=d[r[i+1]]+1)
			mn++;
	}
	cout<<mn<<' '<<mx<<endl;

}