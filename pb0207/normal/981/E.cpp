#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<vector>
using namespace std;

const int N=1e4+1e3+7;

typedef bitset<N> bs;

int n,q;

bs ans;

int cnt;

struct T{
	int l,r,ls,rs;
	vector<int>v;
}t[N*2+1];

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	return x;
}

void change(int x,int l,int r,int v)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].v.push_back(v);
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		change(t[x].ls,l,r,v);
	if(r>mid)
		change(t[x].rs,l,r,v);
}

void dfs(int x,bs w)
{
	for(int i=0;i<t[x].v.size();i++)
		w|=w<<t[x].v[i];
	if(t[x].l==t[x].r)
	{
		ans|=w;
		return;
	}
	dfs(t[x].ls,w);
	dfs(t[x].rs,w);
}

int main()
{
	scanf("%d%d",&n,&q);
	build(1,n);
	while(q--)
	{
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		change(1,l,r,x);
	}
	dfs(1,bs(1));
	int tot=0;
	for(int i=1;i<=n;i++)
		tot+=ans[i];
	printf("%d\n",tot);
	for(int i=1;i<=n;i++)
		if(ans[i])
			printf("%d ",i);
}