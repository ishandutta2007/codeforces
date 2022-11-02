#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int inf=(int)2e9+10;
const int MOD=1e9+7;
const int N=100010;
struct Data
{
	int u,l,r,s;
	void scan(){scanf("%d%d%d%d",&u,&l,&r,&s);}
	bool operator<(const Data&a)const{return u>a.u;}
}a[N];
vector<pair<int,int>>g[N<<2];
int tree[N<<2],n,h,w,ans;
void build(int p,int le,int ri)
{
	if(le==ri){g[p].pb(mp(h+1,1));tree[p]=h+1;return;}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	tree[p]=min(tree[p<<1],tree[p<<1|1]);
}
void insert(int p,int le,int ri,int x,int a,int b)
{
	if(le==ri){g[p].pb(mp(a,b));tree[p]=a;return;}
	int mid=(le+ri)>>1;
	if(x<=mid)insert(p<<1,le,mid,x,a,b);
	else insert(p<<1|1,mid+1,ri,x,a,b);
	tree[p]=min(tree[p<<1],tree[p<<1|1]);
}
void pop(int p,int le,int ri,int ll,int rr,int lim,int&ans)
{
	if(tree[p]>lim)return;
	if(le==ri)
	{
		for(;g[p].size()&&g[p].back().first<=lim;ans=(ans+g[p].back().second)%MOD,g[p].pop_back());
		tree[p]=!g[p].size()?inf:g[p].back().first;
		return;
	}
	int mid=(le+ri)>>1;
	if(ll<=mid)pop(p<<1,le,mid,ll,rr,lim,ans);
	if(rr>mid)pop(p<<1|1,mid+1,ri,ll,rr,lim,ans);
	tree[p]=min(tree[p<<1],tree[p<<1|1]);
}
int main()
{
	scanf("%d%d%d",&h,&w,&n);
	rep(i,n)a[i].scan();
	sort(a+1,a+n+1);
	build(1,1,w);
	ans=w;
	rep(i,n)
	{
		int tmp=0;
		pop(1,1,w,a[i].l,a[i].r,a[i].u+a[i].s,tmp);
		if(tmp)
		{
			ans=(ans+tmp)%MOD;
			insert(1,1,w,a[i].l==1?a[i].r+1:a[i].l-1,a[i].u,tmp);
			insert(1,1,w,a[i].r==w?a[i].l-1:a[i].r+1,a[i].u,tmp);
		}
	}
	printf("%d\n",ans);
	return 0;
}