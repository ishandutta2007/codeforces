// LUOGU_RID: 90641794
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define mod 1000000007
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
ll ksm(ll x,ll y)
{
	ll ret=1;
	while(y>0)
	{
		if(y&1)
		{
			ret=(ret*x)%mod;
		}
		x=(x*x)%mod;
		y>>=1;
	}
	return ret;
}
struct Matrix{
	ll n,a[N][N];
	void init(ll _n)
	{
		memset(a,0,sizeof(a));
		n=_n;
		return;
	}
	ll det()
	{
		ll i,j,k,ans=1;
		for(i=0;i<n;i++)
		{
			for(j=i;j<n;j++)
			{
				if(a[j][i]!=0)
				{
					break;
				}
			}
			if(j!=i)
			{
				ans=(mod-ans)%mod;
				for(k=0;k<n;k++)
				{
					swap(a[j][k],a[i][k]);
				}
			}
			for(j=i+1;j<n;j++)
			{
				while(a[j][i])
				{
					ll divnum=a[i][i]/a[j][i];
					for(k=0;k<n;k++)
					{
						a[i][k]=(a[i][k]+(mod-divnum)*a[j][k])%mod;
						swap(a[i][k],a[j][k]);
					}
					ans=(mod-ans)%mod;
				}
			}
			ans=(ans*a[i][i])%mod;
		}
		return ans;
	}
	ll calc()
	{
		ll i;
		for(i=0;i<n;i++)
		{
			a[i][n]=a[n][i]=0;
		}
		n--;
		return det();
	}
}mat;
ll n,k,a[N][N],val[N];
bool ed[N][N];
ll find_nonz(ll col,ll st)
{
	ll i;
	for(i=st;i<n;i++)
	{
		if(a[i][col]!=0)
		{
			return i;
		}
	}
	return -1;
}
void row_swap(ll r1,ll r2)
{
	ll i;
	for(i=0;i<=n;i++)
	{
		swap(a[r1][i],a[r2][i]);
	}
	return;
}
void row_div(ll r,ll val)
{
	ll i;
	val=ksm(val,mod-2);
	for(i=0;i<=n;i++)
	{
		a[r][i]=(a[r][i]*val)%mod;
	}
	return;
}
void row_sub(ll r1,ll r2,ll val)
{
	ll i;
	for(i=0;i<=n;i++)
	{
		(a[r2][i]-=a[r1][i]*val)%=mod;
		a[r2][i]=(a[r2][i]+mod)%mod;
	}
	return;
}
void gauss()
{
	ll i,j,k;
	for(i=0,j=0;i<n;i++,j++)
	{
		k=find_nonz(i,j);
		if(k==-1)
		{
			j--;
			continue;
		}
		row_swap(j,k);
		row_div(j,a[j][i]);
		for(k=0;k<n;k++)
		{
			if(k!=j)
			{
				row_sub(j,k,a[k][i]);
			}
		}
	}
	return;
}
int main(){
	ll i,j,l,x,y;
	scanf("%lld",&n);
	for(i=1;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		x--,y--;
		ed[x][y]=ed[y][x]=true;
	}
	for(i=0;i<n;i++)
	{
		mat.init(n);
		for(j=0;j<n;j++)
		{
			for(l=0;l<n;l++)
			{
				if(j==l)
				{
					continue;
				}
				else if(ed[j][l])
				{
					mat.a[j][j]++;
					mat.a[j][l]=mod-1;
				}
				else
				{
					mat.a[j][j]+=i;
					mat.a[j][l]=(mod-i)%mod;
				}
			}
		}
		val[i]=mat.calc();
	}
	for(i=0;i<n;i++)
	{
		ll pw=1;
		for(j=0;j<n;j++)
		{
			a[i][j]=pw;
			pw=(pw*i)%mod;
		}
		a[i][n]=val[i];
	}
	gauss();
	for(i=n-1;i>=0;i--)
	{
		cout<<a[i][n]<<" ";
	}
	puts("");
	return 0;
}