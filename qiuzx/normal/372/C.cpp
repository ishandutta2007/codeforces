#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 1000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define UINF 18446744073709551615
#define F first
#define S second
#define ll long long
#define N 310
#define M 150010
using namespace std;
ll n,m,d,a[N],b[N],t[N],dp[M],lst[M],tmp;
deque<ll> dq;
int main(){
	ll i,j;
	scanf("%I64d%I64d%I64d",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%I64d%I64d%I64d",&a[i],&b[i],&t[i]);
		a[i]--;
	}
	memset(dp,-127,sizeof(dp));
	for(i=0;i<n;i++)
	{
		lst[i]=0;
	}
	t[0]=1;
	for(i=1;i<=m;i++)
	{
		while(!dq.empty())
		{
			dq.pop_front();
		}
		tmp=-LINF;
		for(j=0;j<=min(n-1,d*(t[i]-t[i-1]));j++)
		{
			while(!dq.empty()&&lst[dq.back()]<=lst[j])
			{
				dq.pop_back();
			}
			dq.push_back(j);
		}
		dp[0]=lst[dq.front()]+b[i]-a[i];
		tmp=max(tmp,dp[0]);
		for(j=1;j<n;j++)
		{
			while(!dq.empty()&&dq.front()<max((ll)0,j-d*(t[i]-t[i-1])))
			{
				dq.pop_front();
			}
			if(j+d*(t[i]-t[i-1])<n)
			{
				while(!dq.empty()&&lst[dq.back()]<=lst[j+d*(t[i]-t[i-1])])
				{
					dq.pop_back();
				}
				dq.push_back(j+d*(t[i]-t[i-1]));
			}
			dp[j]=lst[dq.front()]+b[i]-abs(a[i]-j);
			tmp=max(tmp,dp[j]);
		}
		for(j=0;j<n;j++) 
		{
			lst[j]=dp[j];
		}
		if(i==m)
		{
			printf("%I64d\n",tmp);
		}
	}
	return 0;
}