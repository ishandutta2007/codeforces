#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 210
using namespace std;
ll n,m,a[N][N],cur[N][N],fx[N];
void solve()
{
	ll i,j,bdr=-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			cur[i][j]=a[i][j]^fx[j];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=1;j<m;j++)
		{
			if(cur[i][j]!=cur[i][0])
			{
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			if(bdr!=-1)
			{
				return;
			}
			bdr=i;
		}
	}
	if(bdr!=-1)
	{
		for(i=0;i<m;i++)
		{
			if(cur[bdr][i]!=cur[bdr][0])
			{
				break;
			}
		}
		for(j=i+1;j<m;j++)
		{
			if(cur[bdr][j]!=cur[bdr][i])
			{
				j=-1;
				break;
			}
		}
		if(j==-1)
		{
			return;
		}
	}
	puts("YES");
	for(i=0;i<n;i++)
	{
		if(i<=bdr)
		{
			printf("%lld",cur[i][0]);
		}
		else
		{
			printf("%lld",cur[i][0]^1);
		}
	}
	puts("");
	for(i=0;i<m;i++)
	{
		printf("%lld",fx[i]);
	}
	exit(0);
}
int main(){
	ll i,j,cnt=0;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<m;i++)
	{
		fx[i]=a[0][i];
	}
	solve();
	for(i=0;i<m;i++)
	{
		fx[i]=(a[n-1][i]^1);
	}
	solve();
	puts("NO");
	return 0;
}