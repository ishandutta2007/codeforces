#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[1000005],st[400005][20],lg[1000005],b[1000005],vis[1000005];
typedef long long ll;
int query(int l,int r)
{
	int nw=lg[r-l+1];
	//printf("l=%d,r=%d,query=%d\n",l,r,max(st[l][nw],st[r-(1<<nw)+1][nw]));
	return max(st[l][nw],st[r-(1<<nw)+1][nw]);
}
ll solve(int l,int r)
{
	if(l==r||l>r) return 0;
	int q=query(l,r),id=b[q];
	ll ans=0;
	//printf("q=%d,l=%d,r=%d,id=%d\n",q,l,r,id);
	if(id-l<=r-id)
	{
		for(int i=l;i<id;i++)
		{
			int nw=a[i];
			if(nw>=q) continue;
			nw=q-nw;
			if(b[nw]>id&&b[nw]<=r) ans++;
		}
	}
	else
	{
		for(int i=id+1;i<=r;i++)
		{
			int nw=a[i];
			if(nw>=q) continue;
			nw=q-nw;
			if(b[nw]>=l&&b[nw]<id) ans++;
		}
	}
	ans+=solve(l,id-1);
	ans+=solve(id+1,r);
	return ans;
}
int main()
{
	scanf("%d",&n);
	lg[1]=0;
	for(int i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),b[a[i]]=i,st[i][0]=a[i];
	for(int i=1;i<=19;i++)
		for(int j=1;j<=n;j++)
		{
			int nw=(1<<i-1);
			if(j+nw<=n) st[j][i]=max(st[j][i-1],st[j+nw][i-1]);
			else st[j][i]=st[j][i-1];
		}
	printf("%I64d",solve(1,n));
	return 0;
}