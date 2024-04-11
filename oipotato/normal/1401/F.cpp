#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
const int N=(1<<18)+100;
long long c[N];
int a[N],n,q,swp[20],rev[20];
void modify(int x,int y){for(;x<=(1<<n);x+=x&(-x))c[x]+=y;}
long long get(int x){long long s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
int getid(int x,int st)
{
	for(int i=st+1;i<=n;i++)if(rev[i])x=(1<<i)-x+(x-1)/(1<<i)*(1<<(i+1))+1;
	for(int i=st;i<n;i++)if(swp[i])x=x+((((x-1)/(1<<i))&1)?-1:1)*(1<<i);
	return x;
}
long long get(int dep,int le,int ri,int ll,int rr)
{
	// printf("%d %d %d %d %d %d %d\n",dep,le,ri,ll,rr,getid(le,dep),getid(ri,dep));
	if(ll<=le&&ri<=rr)
	{
		int L=getid(le,dep),R=getid(ri,dep);
		if(L>R)swap(L,R);
		return get(R)-get(L-1);
	}
	int mid=(le+ri)>>1;
	long long res=0;
	if(ll<=mid)res+=get(dep-1,le,mid,ll,rr);
	if(rr>mid)res+=get(dep-1,mid+1,ri,ll,rr);
	return res;
}
int main()
{
	scanf("%d%d",&n,&q);
	rep(i,(1<<n))scanf("%d",&a[i]),modify(i,a[i]);
	rep(i,q)
	{
		int opt,x,k,l,r;
		scanf("%d",&opt);
		if(opt==1)
		{
			scanf("%d%d",&x,&k);
			x=getid(x,0);
			modify(x,k-a[x]);
			a[x]=k;
		}
		else if(opt==4){scanf("%d%d",&l,&r);printf("%lld\n",get(n,1,(1<<n),l,r));}
		else
		{
			scanf("%d",&k);
			if(opt==2)rev[k]^=1;else swp[k]^=1;
		}
	}
    return 0;
}