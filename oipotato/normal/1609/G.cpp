#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int N=100010;
LL tag[N<<2],mx[N<<2],sum[N<<2],sumx[N<<2],a[N],b[N],base;
int n,m,q;
void build(int p,int le,int ri)
{
	tag[p]=0;
	if(le==ri){mx[p]=b[le];sum[p]=b[le];sumx[p]=b[le]*(m-le);return;}
	int mid=(le+ri)>>1;
	build(p<<1,le,mid);
	build(p<<1|1,mid+1,ri);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	sumx[p]=sumx[p<<1]+sumx[p<<1|1];
}
void add(int p,int le,int ri,LL d)
{
	tag[p]+=d;
	mx[p]+=d;
	sum[p]+=(ri-le+1)*d;
	sumx[p]+=d*(m-le+m-ri)*(ri-le+1)/2;
}
void add(int p,int le,int ri,int ll,int rr,int d)
{
	if(ll<=le&&ri<=rr){add(p,le,ri,d);return;}
	int mid=(le+ri)>>1;
	if(tag[p]){add(p<<1,le,mid,tag[p]);add(p<<1|1,mid+1,ri,tag[p]);tag[p]=0;}
	if(ll<=mid)add(p<<1,le,mid,ll,rr,d);
	if(rr>mid)add(p<<1|1,mid+1,ri,ll,rr,d);
	mx[p]=max(mx[p<<1],mx[p<<1|1]);
	sum[p]=sum[p<<1]+sum[p<<1|1];
	sumx[p]=sumx[p<<1]+sumx[p<<1|1];
}
void get(int p,int le,int ri,LL x,int&pos,LL&Sum,LL&SumX)
{
	if(mx[p]<x){pos=ri;Sum+=sum[p];SumX+=sumx[p];return;}
	if(le==ri)return;
	int mid=(le+ri)>>1;
	if(tag[p]){add(p<<1,le,mid,tag[p]);add(p<<1|1,mid+1,ri,tag[p]);tag[p]=0;}
	if(mx[p<<1]<x)get(p<<1|1,mid+1,ri,x,pos=mid,Sum+=sum[p<<1],SumX+=sumx[p<<1]);
	else get(p<<1,le,mid,x,pos,Sum,SumX);
}
LL query()
{
	LL res=base*(n+m-1);
	LL lastsum=0,lastsumx=0;
	int lastpos=0;
	rep(i,n-1)
	{
		LL sum=0,sumx=0;
		int pos=0;
		get(1,1,m-1,a[i],pos,sum,sumx);
		res+=a[i]*(n+m-2-pos-(i-1))+sumx-lastsumx+(sum-lastsum)*(n+m-2-pos-(i-1)+1-(m-pos));
		lastpos=pos;lastsum=sum;lastsumx=sumx;
	}
	res+=sumx[1]-lastsumx;
	return res;
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	rep(i,n)scanf("%lld",&a[i]);
	rep(i,m)scanf("%lld",&b[i]);
	base=a[1]+b[1];
	rep(i,n-1)a[i]=a[i+1]-a[i];
	rep(i,m-1)b[i]=b[i+1]-b[i];
	build(1,1,m-1);
	rep(i,q)
	{
		int typ,k,d;
		scanf("%d%d%d",&typ,&k,&d);
		if(typ==1)
		{
			if(k==n)base+=d,k--;
			for(int j=n-k;j<n;j++)a[j]+=d;
		}
		else
		{
			if(k==m)base+=d,k--;
			add(1,1,m-1,m-k,m-1,d);
		}
		printf("%lld\n",query());
	}
    return 0;
}