#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int inf=1e9;
typedef pair<pair<int,int>,pair<int,int>> Node;
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=200001;
// bool testa;
Node mx[N<<2][9];
int a[200010],n,m;
// bool testb;
void merge(Node&ans,const Node&x,const Node&y)
{
	if(x.first<y.first)ans=make_pair(x.first,min(x.second,y.first));
	else ans=make_pair(y.first,min(x.first,y.second));
}
void build(int p,int le,int ri)
{
	if(le==ri)
	{
		int x=a[le],num=x;
		rep(i,9)
		{
			mx[p][i-1].first=make_pair(x%10?num:inf,le);
			mx[p][i-1].second=make_pair(inf,le);
			x/=10;
		}
		return;
	}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	rep(i,9)merge(mx[p][i-1],mx[p<<1][i-1],mx[p<<1|1][i-1]);
}
void modify(int p,int le,int ri,int x,int y)
{
	if(le==ri)
	{
		int x=y,num=x;
		rep(i,9)
		{
			mx[p][i-1].first=make_pair(x%10?num:inf,le);
			mx[p][i-1].second=make_pair(inf,le);
			x/=10;
		}
		return;
	}
	int mid=(le+ri)>>1;
	if(x<=mid)modify(p<<1,le,mid,x,y);
	else modify(p<<1|1,mid+1,ri,x,y);
	rep(i,9)merge(mx[p][i-1],mx[p<<1][i-1],mx[p<<1|1][i-1]);
}
void query(int p,int le,int ri,int ll,int rr,int key,Node&ans)
{
	if(ll<=le&&ri<=rr){merge(ans,ans,mx[p][key]);return;}
	int mid=(le+ri)>>1;
	if(ll<=mid)query(p<<1,le,mid,ll,rr,key,ans);
	if(rr>mid)query(p<<1|1,mid+1,ri,ll,rr,key,ans);
}
int query(int l,int r)
{
	int ans=2*inf;
	rep(i,9)
	{
		Node tmp=make_pair(make_pair(inf,inf),make_pair(inf,inf));
		query(1,1,n,l,r,i-1,tmp);
		if(tmp.second.first<inf)ans=min(ans,tmp.first.first+tmp.second.first);
	}
	return ans==2*inf?-1:ans;
}
int main()
{
	// cout<<(&testb-&testa)/1024./1024<<endl;
	scanf("%d%d",&n,&m);
	rep(i,n)scanf("%d",&a[i]);
	build(1,1,n);
	rep(i,m)
	{
		int opt,x,y;
		scanf("%d%d%d",&opt,&x,&y);
		if(opt==1)modify(1,1,n,x,y);
		else printf("%d\n",query(x,y));
	}
	return 0;
}