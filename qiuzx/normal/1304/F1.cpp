#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 20010
#define M 55
using namespace std;
int n,m,k,a[M][N],qdh[M][N],dp[M][N],ans=-INF63;
int val[4*N],lft[4*N],rgh[4*N];
void build_tree(int x,int lay,int l,int r)
{
	if(l>r)
	{
		return;
	}
	lft[lay]=l;
	rgh[lay]=r;
	if(l==r)
	{
		val[lay]=dp[x][l];
		return;
	}
	int mid=((l+r)>>1);
	build_tree(x,(lay<<1),l,mid);
	build_tree(x,(lay<<1)+1,mid+1,r);
	val[lay]=max(val[lay<<1],val[(lay<<1)+1]);
	return;
}
int find_pnt(int lay,int l,int r)
{
	if(lft[lay]>rgh[lay])
	{
		return 0;
	}
	if(lft[lay]>=l&&rgh[lay]<=r)
	{
		return val[lay];
	}
	if(lft[lay]>r||rgh[lay]<l)
	{
		return 0;
	}
	int mid=(lft[lay]+rgh[lay])>>1,a=0,b=0;
	if(mid>=l)
	{
		a=find_pnt(lay<<1,l,r);
	}
	if(mid<r)
	{
		b=find_pnt((lay<<1)+1,l,r);
	}
	return max(a,b);
}
int main(){
	int i,j,l;
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i<n;i++)
	{
		qdh[i][0]=0;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			qdh[i][j]=qdh[i][j-1]+a[i][j];
		}
	}
	memset(dp,-63,sizeof(dp));
	for(i=1;i<=m;i++)
	{
		dp[0][i]=qdh[0][i+k-1]-qdh[0][i-1]+qdh[1][i+k-1]-qdh[1][i-1];
	}
	for(i=1;i<n;i++)
	{
		build_tree(i-1,1,1,m);
		for(j=1;j+k-1<=m;j++)
		{
			dp[i][j]=max(find_pnt(1,1,max(0,j-k)),find_pnt(1,min(m+1,j+k),m));
			/*for(l=0;l<32;l++)
			{
				cout<<val[l]<<" "<<lft[l]<<","<<rgh[l]<<endl;
			}*/
			for(l=max(1,j-k+1);l<=min(m,j+k-1);l++)
			{
				if(l<=j)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][l]-qdh[i][l+k-1]+qdh[i][j-1]);
				}
				else
				{
					dp[i][j]=max(dp[i][j],dp[i-1][l]-qdh[i][j+k-1]+qdh[i][l-1]);
				}
			}
			dp[i][j]+=qdh[i][j+k-1]-qdh[i][j-1]+qdh[i+1][j+k-1]-qdh[i+1][j-1];
		}
	}
	for(i=1;i<=m;i++)
	{
		ans=max(ans,dp[n-1][i]);
	}
	printf("%d\n",ans);
	return 0;
}