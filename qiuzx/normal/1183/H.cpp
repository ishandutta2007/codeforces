#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 110
using namespace std;
ll n,k,dp[N][N],lst[N][30],curlst[30],ans=0;
string s;
int main(){
	ll i,j,l;
	cin>>n>>k>>s;
	memset(curlst,-1,sizeof(curlst));
	for(i=0;i<=s.size();i++)
	{
		for(j=0;j<26;j++)
		{
			lst[i][j]=curlst[j];
		}
		if(i<s.size())
		{
			curlst[s[i]-'a']=i;
		}
	}
	s+='#';
	dp[0][1]=1;
	dp[0][0]=1;
	for(i=1;i<=n;i++)
	{
		dp[i][0]=1;
		dp[i][1]=1;
		for(j=2;j<=i+1;j++)
		{
			for(l=0;l<26;l++)
			{
				if(lst[i][l]!=-1)
				{
					dp[i][j]+=dp[lst[i][l]][j-1];
				}
			}
		}
	}
	for(i=n+1;i>0;i--)
	{
		if(k<=dp[n][i])
		{
			cout<<ans+k*(n-i+1)<<endl;
			return 0;
		}
		ans+=dp[n][i]*(n-i+1);
		k-=dp[n][i];
	}
	puts("-1");
	return 0;
}