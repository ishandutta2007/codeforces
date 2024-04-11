#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

const int N=2e5+1e3+7;

struct node{
	int x,w;
};

bool operator <(node a,node b)
{
	return a.w<b.w;
}

set<node>s;

set<node>::iterator it;

vector<int>a[N];

int n,mx[N],q,k,c[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		mx[x]=max(mx[x],y);
	}
	for(int i=1;i<=n;i++)
		if(mx[i])
			s.insert(node{i,mx[i]});
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
			scanf("%d",&c[i]);
		for(int i=1;i<=k;i++)
		{
			if(mx[c[i]]==0)
				continue;
			s.erase(node{c[i],mx[c[i]]});
		}
		if(s.size()==0)
			printf("0 0\n");
		if(s.size()==1)
			printf("%d %d\n",(*s.begin()).x,a[(*s.begin()).x][0]);
		if(s.size()>=2)
		{
			it=s.end();
			it--;
			int p=(*it).x;
			it--;
			printf("%d %d\n",p,*lower_bound(a[p].begin(),a[p].end(),(*it).w));
		}
		for(int i=1;i<=k;i++)
		{
			if(mx[c[i]]==0)
				continue;
			s.insert(node{c[i],mx[c[i]]});
		}
	}
}