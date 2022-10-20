#include <bits/stdc++.h>
#define N 100010
using namespace std;
long long q,n,c1,c2,dp[N],a,b,c[N],v[N],ind;
void getval(int x,int y)
{
	if(ind==x)
	{
		dp[x]=max(dp[x],max(dp[x]+v[y]*a,c2+v[y]*b));
	}
	else
	{
		dp[x]=max(dp[x],max(dp[x]+v[y]*a,c1+v[y]*b));
	}
	if(ind==x)
	{
		c1=max(c1,dp[x]);
	}
	else
	{
		if(dp[x]>c1)
		{
			ind=x;
			c2=c1;
			c1=dp[x];
		}
		else if(dp[x]>c2)
		{
			c2=dp[x];
		}
	}
	return;
}
int main(){
	int i;
	cin>>n>>q;
	for(i=0;i<n;i++)
	{
		cin>>v[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>c[i];
	}
	while(q--)
	{
		memset(dp,-63,sizeof(dp));
		ind=0;
		cin>>a>>b;
		c1=c2=0;
		for(i=0;i<n;i++)
		{
			getval(c[i],i); 
		}
		cout<<c1<<endl;
	}
	return 0;
}