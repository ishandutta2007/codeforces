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
#define N 55
#define M 1200010
using namespace std;
ll n,m,iden[M];
double dp[M];//possibility of finding out if you ask a query of mask
double ans=0;
string s[N];
int main(){
	ll i,j,k,mask,cnt;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	m=s[0].size();
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			mask=0;
			for(k=0;k<m;k++)
			{
				if(s[i][k]==s[j][k]&&i!=j)
				{
					mask|=((ll)1<<k);
				}
			}
			iden[mask]|=((ll)1<<i)|((ll)1<<j);
		}
	}
	for(i=(1<<m)-1;i>=0;i--)
	{
		dp[i]=0;
		for(j=0;j<m;j++)
		{
			iden[i]|=iden[i|((ll)1<<j)];
		}
	}
	dp[0]=1;
	for(i=0;i<(1<<m);i++)
	{
		for(j=0;j<m;j++)
		{
			if(!(i&(1<<j)))
			{
				dp[i|(1<<j)]+=dp[i]/(double)(m-__builtin_popcount(i));
			}
		}
		cnt=0;
		for(j=0;j<n;j++)
		{
			if(iden[i]&((ll)1<<j))
			{
				cnt++;
			}
		}
		ans+=dp[i]*(double)cnt/(double)n;
	}
	printf("%.12f\n",ans);
	return 0;
}