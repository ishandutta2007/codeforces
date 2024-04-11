#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<queue>
#include<vector>
#include<map>
#include<cmath>
#include<set>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=300010;
vector<pair<int,int>>g[N];
pair<int,int>tree[N<<2];
int tag[N<<2],ans[N],c[N],a[N],n,q;
void modify(int x){for(;x<=n;x+=x&(-x))c[x]++;}
int get(int x){int s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
void build(int p,int le,int ri)
{
	tag[p]=0;tree[p]=mp(-n-1,0);
	if(le==ri)return;
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
}
void modify(int p,int le,int ri,int x,int y)
{
	if(le==ri){tree[p]=mp(y,le);return;}
	int mid=(le+ri)>>1;
	if(x<=mid)modify(p<<1,le,mid,x,y-tag[p]);
	else modify(p<<1|1,mid+1,ri,x,y-tag[p]);
	tree[p]=max(tree[p<<1],tree[p<<1|1]);
	tree[p].first+=tag[p];
}
void add(int p,int le,int ri,int x)
{
	if(le==ri){tag[p]++;tree[p].first++;return;}
	int mid=(le+ri)>>1;
	if(x<=mid){tag[p<<1|1]++;tree[p<<1|1].first++;add(p<<1,le,mid,x);}
	else add(p<<1|1,mid+1,ri,x);
	tree[p]=max(tree[p<<1],tree[p<<1|1]);
	tree[p].first+=tag[p];
}
int main()
{
	scanf("%d%d",&n,&q);
	rep(i,n)scanf("%d",&a[i]);
	rep(i,q){int x,y;scanf("%d%d",&x,&y);g[x].pb(mp(y,i));}
	build(1,1,n);
	for(int i=n;i;i--)
	{
		if(a[i]<i)modify(1,1,n,i,a[i]-i);
		else if(a[i]==i)
		{
			modify(i);
			add(1,1,n,i);
			for(;!tree[1].first;)
			{
				modify(tree[1].second);
				add(1,1,n,tree[1].second);
				modify(1,1,n,tree[1].second,-n-1);
			}
		}
		for(auto j:g[i-1])ans[j.second]=get(n-j.first);
	}
	rep(i,q)printf("%d\n",ans[i]);
	return 0;
}