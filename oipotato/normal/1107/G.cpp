#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cassert>
#include<set>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=300010;
struct Node
{
	long long sum,lmax,rmax,mmax;
	void init(long long x){sum=x;lmax=rmax=mmax=max(x,0ll);}
	Node& operator+=(const Node&a)
	{
		mmax=max(max(mmax,a.mmax),rmax+a.lmax);
		lmax=max(lmax,sum+a.lmax);
		rmax=max(a.rmax,a.sum+rmax);
		sum+=a.sum;
		return *this;
	}
}tree[N<<2];
int n,a,d[N],c[N],fa[N],r[N];
long long ans;
pair<long long,int>p[N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void build(int p,int le,int ri)
{
	if(le==ri){tree[p].init(a-c[le]);return;}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	(tree[p]=tree[p<<1])+=tree[p<<1|1];
}
Node query(int p,int le,int ri,int ll,int rr)
{
	if(ll<=le&&ri<=rr)return tree[p];
	int mid=(le+ri)>>1;
	Node ans;ans.init(0);
	if(ll<=mid)ans+=query(p<<1,le,mid,ll,rr);
	if(rr>mid)ans+=query(p<<1|1,mid+1,ri,ll,rr);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&a);
	rep(i,n)scanf("%d%d",&d[i],&c[i]),ans=max(ans,(long long)a-c[i]);
	build(1,1,n);
	rep(i,n-1)p[i]=mp(1ll*(d[i+1]-d[i])*(d[i+1]-d[i]),i);
	rep(i,n)fa[i]=r[i]=i;
	sort(p+1,p+n);
	rep(i,n-1)
	{
		int x=find(p[i].second),y=p[i].second+1;
		fa[y]=x;r[x]=r[y];//printf("%d %d %lld\n",x,r[x],query(1,1,n,x,r[x]).mmax);
		ans=max(ans,query(1,1,n,x,r[x]).mmax-p[i].first);
	}
	printf("%lld\n",ans);
	return 0;
}