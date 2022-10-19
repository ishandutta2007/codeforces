#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 1500010
using namespace std;
struct SegT{
	int l,r;
	ll val;
}segt[N*4];
int n1,n2,n3,n4,m1,m2,m3,a[4][N];
ll dp[4][N],ans=LINF;
vector<int> vt[N][4][4];
void build_tree(int x,int l,int r)
{
	if(l>r)
	{
		return;
	}
	segt[x].l=l;
	segt[x].r=r;
	segt[x].val=LINF;
	if(l==r)
	{
		return;
	}
	int mid=(l+r)>>1,a=x<<1;
	build_tree(a,l,mid);
	build_tree(a|1,mid+1,r);
	return;
}
void update(int x,int l,ll v)
{
	int tl=segt[x].l,tr=segt[x].r;
	if(tl>l||tr<l)
	{
		return;
	}
	if(tl==l&&tr==l)
	{
		segt[x].val=min(segt[x].val,v);
		return;
	}
	int mid=(tl+tr)>>1,a=x<<1;
	if(mid>=l)
	{
		update(a,l,v);
	}
	else
	{
		update(a|1,l,v);
	}
	segt[x].val=min(segt[a].val,segt[a|1].val);
	return;
}
ll query(int x,int l,int r)
{
	if(l>r)
	{
		return LINF;
	}
	int tl=segt[x].l,tr=segt[x].r;
	if(tl>r||tr<l)
	{
		return LINF;
	}
	if(l<=tl&&tr<=r)
	{
		return segt[x].val;
	}
	int mid=(tl+tr)>>1,a=x<<1;
	ll ret=LINF;
	if(mid>=l)
	{
		ret=min(ret,query(a,l,r));
	}
	if(mid<r)
	{
		ret=min(ret,query(a|1,l,r));
	}
	return ret;
}
int main(){
	int i,j,x,y;
	scanf("%d%d%d%d",&n1,&n2,&n3,&n4);
	for(i=0;i<n1;i++)
	{
		scanf("%d",&a[0][i]);
	}
	for(i=0;i<n2;i++)
	{
		scanf("%d",&a[1][i]);
	}
	for(i=0;i<n3;i++)
	{
		scanf("%d",&a[2][i]);
	}
	for(i=0;i<n4;i++)
	{
		scanf("%d",&a[3][i]);
	}
	scanf("%d",&m1);
	for(i=0;i<m1;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vt[x][0][1].push_back(y);
		vt[y][1][0].push_back(x);
	}
	scanf("%d",&m2);
	for(i=0;i<m2;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vt[x][1][2].push_back(y);
		vt[y][2][1].push_back(x);
	}
	scanf("%d",&m3);
	for(i=0;i<m3;i++)
	{
		scanf("%d%d",&x,&y);
		x--;
		y--;
		vt[x][2][3].push_back(y);
		vt[y][3][2].push_back(x);
	}
	for(i=0;i<max(max(n1,n2),max(n3,n4));i++)
	{
		for(j=0;j<3;j++)
		{
			sort(vt[i][j][j+1].begin(),vt[i][j][j+1].end());
			sort(vt[i][j+1][j].begin(),vt[i][j+1][j].end());
		}
	}
	memset(dp,63,sizeof(dp));
	build_tree(1,0,n1-1);
	for(i=0;i<n1;i++)
	{
		update(1,i,a[0][i]);
	}
	for(i=0;i<n2;i++)
	{
		if(vt[i][1][0].empty())
		{
			dp[1][i]=query(1,0,n1-1)+a[1][i];
		}
		else
		{
			dp[1][i]=query(1,0,vt[i][1][0][0]-1)+a[1][i];
		}
		for(j=0;j+1<vt[i][1][0].size();j++)
		{
			dp[1][i]=min(dp[1][i],query(1,vt[i][1][0][j]+1,vt[i][1][0][j+1]-1)+a[1][i]);
		}
		if(!vt[i][1][0].empty())
		{
			dp[1][i]=min(dp[1][i],query(1,vt[i][1][0][vt[i][1][0].size()-1]+1,n1-1)+a[1][i]);
		}
	}
	build_tree(1,0,n2-1);
	for(i=0;i<n2;i++)
	{
		update(1,i,dp[1][i]);
	}
	for(i=0;i<n3;i++)
	{
		if(vt[i][2][1].empty())
		{
			dp[2][i]=query(1,0,n2-1)+a[2][i];
		}
		else
		{
			dp[2][i]=query(1,0,vt[i][2][1][0]-1)+a[2][i];
		}
		for(j=0;j+1<vt[i][2][1].size();j++)
		{
			dp[2][i]=min(dp[2][i],query(1,vt[i][2][1][j]+1,vt[i][2][1][j+1]-1)+a[2][i]);
		}
		if(!vt[i][2][1].empty())
		{
			dp[2][i]=min(dp[2][i],query(1,vt[i][2][1][vt[i][2][1].size()-1]+1,n2-1)+a[2][i]);
		}
	}
	build_tree(1,0,n3-1);
	for(i=0;i<n3;i++)
	{
		update(1,i,dp[2][i]);
	}
	for(i=0;i<n4;i++)
	{
		if(vt[i][3][2].empty())
		{
			dp[3][i]=query(1,0,n3-1)+a[3][i];
		}
		else
		{
			dp[3][i]=query(1,0,vt[i][3][2][0]-1)+a[3][i];
		}
		for(j=0;j+1<vt[i][3][2].size();j++)
		{
			dp[3][i]=min(dp[3][i],query(1,vt[i][3][2][j]+1,vt[i][3][2][j+1]-1)+a[3][i]);
		}
		if(!vt[i][3][2].empty())
		{
			dp[3][i]=min(dp[3][i],query(1,vt[i][3][2][vt[i][3][2].size()-1]+1,n3-1)+a[3][i]);
		}
		ans=min(ans,dp[3][i]);
	}
	if(ans>=LINF)
	{
		puts("-1");
	}
	else
	{
		printf("%lld\n",ans);
	}
	return 0;
}