#include<cstdio>
using namespace std;
int ls[200010],rs[200010],num[200010],root[10010],a[10010],l,r,x,n,m,tot;
void build(int p1,int p2,int le,int ri,int x)
{
	if(le==ri)
	{
		num[p2]++;
		return;
	}
	int mid=(le+ri)>>1;
	num[p2]=num[p1]+1;
	ls[p2]=ls[p1];
	rs[p2]=rs[p1];
	if(x<=mid)
	{
		ls[p2]=++tot;
		build(ls[p1],tot,le,mid,x);
	}
	else
	{
		rs[p2]=++tot;
		build(rs[p1],tot,mid+1,ri,x);
	}
}
int query(int p1,int p2,int le,int ri,int k)
{
	if(le==ri)return le;
	int mid=(le+ri)>>1;
	if(num[ls[p2]]-num[ls[p1]]>=k)return query(ls[p1],ls[p2],le,mid,k);
	else return query(rs[p1],rs[p2],mid+1,ri,k-(num[ls[p2]]-num[ls[p1]]));
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		build(root[i-1],root[i]=++tot,1,n,a[i]);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		if(a[x]==query(root[l-1],root[r],1,n,x-l+1))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}