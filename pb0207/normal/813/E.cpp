#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e5+1e3+7;

vector<int>p[N];

struct T{
	int ls,rs,sum;
}t[N*41];

int n,k,a[N],nxk[N],last,q,tot,root[N];

void insert(int l,int r,int x,int &y,int v)
{
	y=++tot;
	t[y]=t[x];
	t[y].sum++;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	if(v<=mid)
		insert(l,mid,t[x].ls,t[y].ls,v);
	else
		insert(mid+1,r,t[x].rs,t[y].rs,v);
}

int query(int l,int r,int x,int y,int v)
{
	if(v>=r)
		return 0;
	if(l>v)
		return t[y].sum-t[x].sum;
	int mid=(l+r)>>1;
	return query(l,mid,t[x].ls,t[y].ls,v)+query(mid+1,r,t[x].rs,t[y].rs,v);
}

int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
	{
		if(p[a[i]].size()<k)
			nxk[i]=n+1;
		else
			nxk[i]=p[a[i]][p[a[i]].size()-k];
		p[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
		insert(1,n+1,root[i-1],root[i],nxk[i]);
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		l=(l+last)%n+1;
		r=(r+last)%n+1;
		if(l>r)
			swap(l,r);
		last=query(1,n+1,root[l-1],root[r],r);
		cout<<last<<endl;
	}
}