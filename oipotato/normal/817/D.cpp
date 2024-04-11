#include<cstdio>
#include<algorithm>
using namespace std;
int st_max[1000010][20],st_min[1000010][20],lg2[1000010],n;
long long ans;
void build_STtable()
{
	for(int i=1;i<20;i++)
	for(int j=1;j<=n-(1<<i)+1;j++)
	{
		st_max[j][i]=max(st_max[j][i-1],st_max[j+(1<<i-1)][i-1]);
		st_min[j][i]=min(st_min[j][i-1],st_min[j+(1<<i-1)][i-1]);
	}
}
int get_max(int l,int r){return max(st_max[l][lg2[r-l+1]],st_max[r-(1<<lg2[r-l+1])+1][lg2[r-l+1]]);}
int get_min(int l,int r){return min(st_min[l][lg2[r-l+1]],st_min[r-(1<<lg2[r-l+1])+1][lg2[r-l+1]]);}
int get_lmax(int x)
{
	int l=0,r=x;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(get_max(mid,x-1)>=st_max[x][0])l=mid;
		else r=mid;
	}
	return l;
}
int get_rmax(int x)
{
	int l=x,r=n+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(get_max(x+1,mid)>st_max[x][0])r=mid;
		else l=mid;
	}
	return r;
}
int get_lmin(int x)
{
	int l=0,r=x;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(get_min(mid,x-1)<=st_max[x][0])l=mid;
		else r=mid;
	}
	return l;
}
int get_rmin(int x)
{
	int l=x,r=n+1;
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(get_min(x+1,mid)<st_max[x][0])r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	for(int i=0;i<20;i++)lg2[1<<i]=i;
	for(int i=1;i<=1000000;i++)lg2[i]=max(lg2[i],lg2[i-1]);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&st_max[i][0]);
		st_min[i][0]=st_max[i][0];
	}
	build_STtable();
	for(int i=1;i<=n;i++)ans+=((long long)(i-get_lmax(i))*(get_rmax(i)-i)-(long long)(i-get_lmin(i))*(get_rmin(i)-i))*st_max[i][0];
	printf("%I64d",ans);
	return 0;
}