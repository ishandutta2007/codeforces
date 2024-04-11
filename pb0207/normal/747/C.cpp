#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N=1e5+1e3+7;

struct node{
	int t,k,d;
}q[N];

bool operator < (node a,node b)
{
	return a.t<b.t;
}

int n,m,t[N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&q[i].t,&q[i].k,&q[i].d);
	sort(q+1,q+m+1);
	for(int i=1;i<=m;i++)
	{
		vector<pair<int,int> >use;
		use.clear();
		int tot=q[i].k;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			if(t[j]<=q[i].t)
			{
				use.push_back(make_pair(j,t[j]));
				t[j]=q[i].t+q[i].d,q[i].k--,ans+=j;
			}
			if(q[i].k==0)
				break;
		}
		if(q[i].k)
		{
			cout<<"-1"<<endl;
			for(int j=0;j<use.size();j++)
				t[use[j].first]=use[j].second;
		}
		else	
			cout<<ans<<endl;
	}
}