#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1e5+1e3+7;

struct node{
	int x,p;
}a[N];

bool cmp(node a,node b)
{
	return a.x<b.x;
}

int cnt[N],sz[N],fa[N],d[N],now;

int n;

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

void un(int x,int y)
{
	int fx=find(x),fy=find(y);
	if(fx==fy)
		return;
	cnt[sz[fx]]--,cnt[sz[fy]]--;
	sz[fy]+=sz[fx];
	cnt[sz[y]]++;
	fa[fx]=fy;
	now--;
}

int ans,v;

void init(int x)
{
	fa[x]=x;
	sz[x]=1;
	cnt[sz[x]]++;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x),a[i].p=i;
	sort(a+1,a+n+1,cmp);
	for(int i=1,j=1;i<=n;i=j)
	{
		while(j<=n&&a[j].x==a[i].x)
		{
			int pos=a[j].p;
			d[pos]=1;
			init(pos);
			now++;
			if(d[pos-1])
				un(pos-1,pos);
			if(d[pos+1])
				un(pos+1,pos);
			j++;
		}
		int g=find(a[i].p);
		if(cnt[sz[g]]==now&&now>ans)
		{
			ans=now;
			v=a[i].x+1;
		}
	}
	printf("%d",v);
}