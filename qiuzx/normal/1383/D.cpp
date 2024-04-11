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
#define N 260
using namespace std;
ll n,m,v[N][N],l[N],r[N],ans[N][N];
bool is_row[N*N],is_col[N*N];
int main(){
	ll i,j,k,mx,a,b;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%lld",&v[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		mx=0;
		for(j=0;j<m;j++)
		{
			mx=max(mx,v[i][j]);
		}
		is_row[mx]=true;
	}
	for(j=0;j<m;j++)
	{
		mx=0;
		for(i=0;i<n;i++)
		{
			mx=max(mx,v[i][j]);
		}
		is_col[mx]=true;
	}
	memset(l,63,sizeof(l));
	memset(r,-1,sizeof(r));
	a=-1;
	b=-1;
	for(i=n*m;i>=1;i--)
	{
		if(is_row[i])
		{
			a++;
		}
		if(is_col[i])
		{
			b++;
		}
		if(is_row[i]||is_col[i])
		{
			ans[a][b]=i;
			l[a]=min(l[a],b);
			r[a]=max(r[a],b);
		}
		else
		{
			for(j=0;j<=a;j++)
			{
				if(l[j]!=0)
				{
					l[j]--;
					ans[j][l[j]]=i;
					j=-1;
					break;
				}
			}
			if(j!=-1)
			{
				for(j=a;j>=0;j--)
				{
					if(r[j]!=b)
					{
						r[j]++;
						ans[j][r[j]]=i;
						break;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%lld ",ans[i][j]);
		}
		puts("");
	}
	return 0;
}