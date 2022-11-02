#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<cassert>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
// bool testa;
const int N=100010;
const int B=299;
const int BN=N/B+5;
int n,q,Bsum,a[N],f[N],L[N],R[N];
const int SQRTN=316;
int tR[SQRTN+5],belong[N],BR;
struct Block
{
	int a[N],tag[SQRTN+5];
	void add_p(int x,int y){a[x]+=y;}
	void add_suf(int x,int y)
	{
		int BL=belong[x];
		for(int i=BL+1;i<=BR;i++)tag[i]+=y;
		for(int i=x;i<=tR[BL];i++)a[i]+=y;
	}
	int get(int x){return a[x]+tag[belong[x]]+x;}
}b[BN];
void work(Block&b,int l,int r)
{
	for(int i=l;i<=r;i++)
	{
		f[i]=a[i]+1;
		for(int j=i-1;j>=l;j--)if(f[i]>a[j]+1)f[i]--;
		b.add_suf(f[i],1);
	}
}
void init()
{
	BR=(n-1)/SQRTN+1;
	for(int i=1,cnt=1;i<=n;i+=SQRTN,cnt++)tR[cnt]=min(i+SQRTN-1,n);
	rep(i,n)belong[i]=(i-1)/SQRTN+1;
	for(int i=1,cnt=1;i<=n;i+=B,cnt++)
	{
		L[cnt]=i;R[cnt]=min(i+B-1,n);
		work(b[cnt],L[cnt],R[cnt]);
	}
}
const int M=1<<17;
int c[M+10];
void add(int x,int y){for(;x<=M;x+=x&(-x))c[x]+=y;}
int get(int k)
{
	int l=1,r=M;
	for(;l<r;)
	{
		int mid=(l+r)>>1;
		if(c[mid]+mid>=k)r=mid;
		else l=mid+1,k-=c[mid];
	}
	return l;
}
void modify(int x,int y)
{
	int BL=(x-1)/B+1;
	b[BL].add_suf(f[x],-1);
	a[x]=y;
	f[x]=a[x]+1;
	for(int i=x-1;i>=L[BL];i--)if(f[x]>a[i]+1)f[x]--;
	b[BL].add_suf(f[x],1);
	// printf("* %d %d\n",x,f[x]);
	for(int i=L[BL];i<=R[BL];i++)
	if(i<=x)add(f[i],1);
	else
	{
		int newf=get(a[i]+1);
		if(newf<f[i])f[i]--,b[BL].add_p(f[i],1);
		else if(newf>f[i])b[BL].add_p(f[i],-1),f[i]++;
		add(f[i],1);
	}
	for(int i=L[BL];i<=R[BL];i++)add(f[i],-1);
}
int query(int x)
{
	int now=a[x]+1,BL=(x-1)/B+1;
	for(int i=x+1;i<=R[BL];i++)if(now>=a[i]+1)now++;
	for(int i=BL+1;i<=Bsum;i++)now=b[i].get(now);
	return now;
}
// bool testb;
int main()
{
	// cout<<(&testb-&testa)/1024./1024.<<endl;
	scanf("%d",&n);Bsum=(n-1)/B+1;
	rep(i,n)scanf("%d",&a[i]),a[i]=i-1-a[i];
	// rep(i,n)printf("%d%c",a[i]+1," \n"[i==n]);
	init();
	scanf("%d",&q);
	rep(i,q)
	{
		int opt,x,y;
		scanf("%d%d",&opt,&x);
		if(opt==1)scanf("%d",&y),modify(x,x-1-y);
		else printf("%d\n",query(x));
		// rep(i,n)printf("%d%c",a[i]+1," \n"[i==n]);
	}
    return 0;
}