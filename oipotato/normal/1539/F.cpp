#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=200010;
struct Node
{
	int lmax,rmax,sum;
	void init(int x){lmax=rmax=sum=x;}
	Node& operator+=(const Node&a)
	{
		lmax=max(0,max(lmax,sum+a.lmax));
		rmax=max(0,max(a.rmax,a.sum+rmax));
		sum+=a.sum;
		return (*this);
	}
}tree[N<<2];
pair<int,int>a[N];
int n,ans[N];
void build(int p,int le,int ri)
{
	if(le==ri){tree[p].init(1);return;}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	(tree[p]=tree[p<<1])+=tree[p<<1|1];
}
void modify(int p,int le,int ri,int x)
{
	if(le==ri){tree[p].init(-1);return;}
	int mid=(le+ri)>>1;
	if(x<=mid)modify(p<<1,le,mid,x);
	else modify(p<<1|1,mid+1,ri,x);
	(tree[p]=tree[p<<1])+=tree[p<<1|1];
}
Node query(int p,int le,int ri,int ll,int rr)
{
	Node tmp;tmp.init(0);
	if(ll>rr)return tmp;
	if(ll<=le&&ri<=rr)return tree[p];
	int mid=(le+ri)>>1;
	if(ll<=mid)tmp+=query(p<<1,le,mid,ll,rr);
	if(rr>mid)tmp+=query(p<<1|1,mid+1,ri,ll,rr);
	return tmp;
}
void work(int typ)
{
	build(1,1,n);
	rep(i,n)
	{
		int j=i;
		for(;j<=n&&a[j].first==a[i].first;j++);
		for(int k=i;k<j;k++)ans[a[k].second]=max(ans[a[k].second],(query(1,1,n,1,a[k].second-1).rmax+query(1,1,n,a[k].second+1,n).lmax+typ)/2);
		for(int k=i;k<j;k++)modify(1,1,n,a[k].second);
		i=j-1;
	}
}
int main()
{
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i].first),a[i].second=i;
	sort(a+1,a+n+1);
	work(1);
	reverse(a+1,a+n+1);
	work(0);
	rep(i,n)printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}