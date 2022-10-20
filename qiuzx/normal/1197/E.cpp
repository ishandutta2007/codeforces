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
#define N 200010
using namespace std;
ll dp[N],path[N],n,ans=INF127,res=0,mx=0;
vector<pair<ll,ll> > outn;
int main(){
	ll i,j,x,y,pos;
	scanf("%I64d",&n);
	outn.push_back(make_pair(0,0));
	for(i=0;i<n;i++)
	{
		scanf("%I64d%I64d",&x,&y);
		outn.push_back(make_pair(x,y));
		mx=max(mx,y);
	}
	sort(outn.begin(),outn.end());
	memset(dp,127,sizeof(dp));
	dp[0]=0;
	path[0]=1;
	for(i=1;i<outn.size();i++)
	{
		pos=upper_bound(outn.begin(),outn.end(),make_pair(outn[i].S,LINF))-outn.begin()-1;
		x=-1;
		for(j=pos;j>=0;j--)
		{
			if(outn[j].F<=x)
			{
				break;
			}
			if(dp[i]>dp[j]+outn[i].S-outn[j].F)
			{
				dp[i]=dp[j]+outn[i].S-outn[j].F;
				path[i]=path[j];
			}
			else if(dp[i]==dp[j]+outn[i].S-outn[j].F)
			{
				path[i]=(path[i]+path[j])%MOD;
			}
			else
			{
				break;
			}
			x=outn[j].S;
		}
		if(outn[i].F>mx)
		{
			if(ans>dp[i])
			{
				ans=dp[i];
				res=path[i];
			}
			else if(ans==dp[i])
			{
				res=(res+path[i])%MOD;
			}
		}
	}
	printf("%I64d\n",res);
	return 0;
}