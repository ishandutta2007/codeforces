#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 300005
#define M 8000005

#define ls tree[t].l
#define rs tree[t].r
#define mid ((l+r)>>1)
#define Ls tree[t1].l
#define Rs tree[t1].r

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,root[N],tot,x;

long long ans;

struct Node{
		int l,r,sum;
}tree[M];

void update(int ll,int l,int r,int t,int t1)
{
		if (l==r) tree[t].sum++;
		else
		{
				if (ll<=mid) 
				{
					ls=++tot;
					tree[ls]=tree[Ls];
					update(ll,l,mid,ls,Ls);
				}
				else
				{
					rs=++tot;
					tree[rs]=tree[Rs];
					update(ll,mid+1,r,rs,Rs);
				}
				tree[t].sum=tree[ls].sum+tree[rs].sum;
		}
}

int ask(int ll,int rr,int l,int r,int t)
{
		if (ll<=l&&r<=rr) return tree[t].sum;
		else
		{
				int S=0;
				if (ll<=mid) S+=ask(ll,rr,l,mid,ls);
				if (rr>mid)  S+=ask(ll,rr,mid+1,r,rs);
				return S;
		}
}

int main()
{
		scanf("%d",&n);
		for (i=1;i<=n;++i)
		{
				scanf("%d",&x); x=min(x,n);
				root[i]=++tot;
				tree[root[i]]=tree[root[i-1]];
				update(x,1,n,root[i],root[i-1]);
				ans+=ask(i,n,1,n,root[min(x,i-1)]);
		}
		cout<<ans<<endl;
}