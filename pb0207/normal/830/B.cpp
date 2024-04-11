#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

ll c[N],a[N],n,last,now,ans,vis[N];

vector<int>v[N];

struct node{
	int id,v;
}b[N];

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=lowbit(x);
	}
}

int q(int x)
{
	ll ret=0;
	while(x)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

ll query(int l,int r)
{
	if(l<=r)
		return q(r)-q(l-1);
	if(l>r)
		return q(r)+q(n)-q(l-1);
}

bool cmp(node a,node b)
{
	return a.v<b.v||(a.v==b.v&&a.id<b.id);
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i].v=a[i],b[i].id=i,add(i,1),v[a[i]].push_back(i);
	sort(b+1,b+n+1,cmp);
	last=1;
	for(int i=1;i<=n;i++)
	if(!vis[b[i].v])
	{
		vis[b[i].v]=1;
		int k=lower_bound(v[b[i].v].begin(),v[b[i].v].end(),last)-v[b[i].v].begin();
		for(int j=k;j<v[b[i].v].size();j++)
			ans+=query(last,v[b[i].v][j]),last=v[b[i].v][j],add(last,-1);
		for(int j=0;j<k;j++)
			ans+=query(last,v[b[i].v][j]),last=v[b[i].v][j],add(last,-1);
	}
	cout<<ans;
}