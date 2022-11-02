#include<cstdio>
#include<algorithm>
using namespace std;
struct Segment_Tree
{
	int ls,rs,cov;
	bool full,empty;
}tree[10000010];
int n,opt[100010],tot,root;
long long l[100010],r[100010],b[200010];
void cover(int &p,int le,int ri,int opt)
{
	if(!p)
	{
		p=++tot;
		tree[p].empty=1;
	}
	if(tree[p].cov&&le<ri&&opt==3)
	{
		cover(tree[p].ls,le,(le+ri)>>1,tree[p].cov);
		cover(tree[p].rs,((le+ri)>>1)+1,ri,tree[p].cov);
		tree[p].cov=0;
	}
	tree[p].cov=opt;
	if(opt==1)
	{
		tree[p].full=1;
		tree[p].empty=0;
	}
	else if(opt==2)
	{
		tree[p].full=0;
		tree[p].empty=1;
	}
	else swap(tree[p].full,tree[p].empty);
}
void maintain(int p)
{
	tree[p].full=tree[tree[p].ls].full&&tree[tree[p].rs].full;
	tree[p].empty=tree[tree[p].ls].empty&&tree[tree[p].rs].empty;
}
void modify(int &p,int le,int ri,int ll,int rr,int opt)
{
	if(!p)
	{
		p=++tot;
		tree[p].empty=1;
	}
	if(le==ll&&ri==rr)
	{
		cover(p,le,ri,opt);
		return;
	}
	long long mid=(le+ri)>>1;
	if(tree[p].cov)
	{
		cover(tree[p].ls,le,mid,tree[p].cov);
		cover(tree[p].rs,mid+1,ri,tree[p].cov);
		tree[p].cov=0;
	}
	if(rr<=mid)modify(tree[p].ls,le,mid,ll,rr,opt);
	else if(ll>mid)modify(tree[p].rs,mid+1,ri,ll,rr,opt);
	else
	{
		modify(tree[p].ls,le,mid,ll,mid,opt);
		modify(tree[p].rs,mid+1,ri,mid+1,rr,opt);
	}
	maintain(p);
}
int query(int p,int le,int ri)
{
	if(!p)return le;
	if(le==ri)return le;
	long long mid=(le+ri)>>1;
	if(tree[p].cov)
	{
		cover(tree[p].ls,le,mid,tree[p].cov);
		cover(tree[p].rs,mid+1,ri,tree[p].cov);
		tree[p].cov=0;
	}
	if(tree[tree[p].ls].full)return query(tree[p].rs,mid+1,ri);
	else return query(tree[p].ls,le,mid);
	maintain(p);
}
int main()
{
	tree[0].empty=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%I64d%I64d",&opt[i],&l[i],&r[i]);
		r[i]++;
		b[2*i]=l[i];
		b[2*i+1]=r[i];
	}
	b[1]=1;
	sort(b+1,b+2*n+2);
	for(int i=1;i<=n;i++)
	{
		int ll=lower_bound(b+1,b+2*n+1,l[i])-b,rr=lower_bound(b+1,b+2*n+1,r[i])-b;
		modify(root,1,2*n+1,ll,rr-1,opt[i]);
		printf("%I64d\n",b[query(root,1,2*n+1)]);
	}
	return 0;
}