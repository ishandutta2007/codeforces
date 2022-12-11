#include<bits/stdc++.h>
#define N 3000010
#define M 10000010
using namespace std;
int n,k,sum[M],cov[M],a[N],b[N],i,fa[N],next[N],l,r,j,S,K,m;
char s[N],ss[N];
int find(int l,int r,int x,int cur)
{
	//printf("find %d %d %d %d\n",l,r,x,cur);
	if(l==r)return l;
	int mid=l+r>>1;int t=mid-l+1-sum[cur<<1];
	if(t>=x)return find(l,mid,x,cur<<1);
	else return find(mid+1,r,x-t,cur<<1|1);
}
void pushdown(int x,int cur)
{
	cov[cur<<1]=cov[cur<<1|1]=1;cov[cur]=0;
	sum[cur<<1]=x+1>>1;sum[cur<<1|1]=x>>1;
}
void update(int cur)
{
	sum[cur]=sum[cur<<1]+sum[cur<<1|1];
}
void change(int l,int r,int L,int R,int cur)
{
	if(L<=l&&R>=r)
	{
		cov[cur]=1;
		sum[cur]=r-l+1;
		return;
	}
	if(cov[cur])pushdown(r-l+1,cur);
	int mid=l+r>>1;
	if(L<=mid)change(l,mid,L,R,cur<<1);
	if(R>mid)change(mid+1,r,L,R,cur<<1|1);
	update(cur);
}
int main()
{
	//freopen("DNA6.in","r",stdin);
	//freopen("DNA.out","w",stdout);
	gets(s+1);m=strlen(s+1);
	scanf("%d%d",&n,&K);
	for(i=1;i<=K;i++)
		scanf("%d%d",&a[i],&b[i]);
	for(i=1;i<n;i++)next[i]=i+1;
	for(;K;K--)
	{
		//printf("%d %d %d\n",sum[1],b[K],n);
		if((n-sum[1])<=b[K])continue;
		l=find(1,n,a[K],1);
		r=find(1,n,b[K],1);
		S=b[K]-a[K]+1;
		//printf("%d %d %d %d %d\n",l,r,S,find(1,n,b[K]+S,1),K);
		for(i=next[l],j=next[r],k=2;j&&k<=S;i=next[next[i]],j=next[j],k+=2)fa[j]=i;
		for(i=l,k=1;j&&k<=S;i=next[next[i]],j=next[j],k+=2)fa[j]=i;
		change(1,n,next[r],find(1,n,b[K]+S,1),1);
		next[r]=j;
	}
	for(i=j=1;i&&j<=m;i=next[i],j++)ss[i]=s[j]/*,printf("%d %d\n",i,j)*/;
	//for(i=1;i<=n;i++)printf("%d ",fa[i]);puts("");
	for(i=1;i<=n;i++)if(fa[i])ss[i]=ss[fa[i]];
	puts(ss+1);
}