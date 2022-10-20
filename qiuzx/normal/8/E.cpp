#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 60
using namespace std;
ll dp[N][2][2],n,k;
vector<ll> v;
ll getdp()
{
	ll i,j,k,c1,c2;
	memset(dp,0,sizeof(dp));
	dp[0][1][0]=1;
	for(i=1;i<=(n+1)/2;i++)
	{
		for(j=0;j<2;j++)
		{
			if(v[i-1]!=-1&&j!=v[i-1])
			{
				continue;
			}
			for(k=0;k<2;k++)
			{
				if(v[n-i]!=-1&&k!=v[n-i])
				{
					continue;
				}
				if(n%2==1&&i==(n+1)/2&&j!=k)
				{
					continue;
				}
				if(j==k)
				{
					if(j==0)
					{
						dp[i][0][1]+=dp[i-1][0][0]+dp[i-1][0][1];
						dp[i][1][1]+=dp[i-1][1][0]+dp[i-1][1][1];
					}
					else
					{
						dp[i][0][1]+=dp[i-1][0][1];
						dp[i][1][1]+=dp[i-1][1][1];
					}
				}
				else if(j<k)
				{
					dp[i][0][0]+=dp[i-1][0][0]+dp[i-1][1][0];
					dp[i][0][1]+=dp[i-1][0][1]+dp[i-1][1][1];
				}
				else
				{
					dp[i][0][0]+=dp[i-1][0][0];
					dp[i][0][1]+=dp[i-1][0][1];
				}
			}
		}
	}
	return dp[(n+1)/2][0][0]+dp[(n+1)/2][0][1]+dp[(n+1)/2][1][0]+dp[(n+1)/2][1][1];
}
bool check()
{
	ll i;
	bool b1=true,b2=true,b3=true;
	for(i=0;i<v.size();i++)
	{
		if(v[i]<(v[i]^1))
		{
			b1=false;
		}
		if(v[i]<v[n-i-1])
		{
			b2=false;
		}
		if(v[i]<(v[n-i-1]^1))
		{
			b3=false;
		}
		if(b1&&v[i]>(v[i]^1))
		{
			return false;
		}
		if(b2&&v[i]>v[n-i-1])
		{
			return false;
		}
		if(b3&&v[i]>(v[n-i-1]^1))
		{
			return false;
		}
	}
	return true;
}
int main(){
	ll i,upd;
	cin>>n>>k;
	k++;
	for(i=0;i<n;i++)
	{
		v.push_back(-1);
	}
	v[0]=0;
	for(i=1;i<n;i++)
	{
		v[i]=0;
		upd=getdp();
		if(k>upd)
		{
			k-=upd;
			v[i]=1;
		}
	}
	if(k!=1||(!check()))
	{
		puts("-1");
		return 0;
	}
	for(i=0;i<n;i++)
	{
		cout<<v[i];
	}
	puts("");
	return 0;
}