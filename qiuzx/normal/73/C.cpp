#include <bits/stdc++.h>
using namespace std;
int dp[105][105][30],m,n,ans=-1000000000;
int v[30][30];
string s;
char x,y;
void check()
{
	int i,ans=0;
	for(i=1;i<s.size();i++)
	{
		ans+=v[s[i-1]-'a'][s[i]-'a'];
	}
	cout<<ans<<endl;
	exit(0);
}
int main(){
	int i,j,k,l;
	cin>>s>>m>>n;
	for(i=0;i<n;i++)
	{
		cin>>x>>y>>j;
		v[x-'a'][y-'a']=j;
	}
	if(m==0)
	{
		check();
	}
	for(i=0;i<105;i++)
	{
		for(j=0;j<105;j++)
		{
			for(k=0;k<30;k++)
			{
				dp[i][j][k]=-1000000000;
			}
		}
	}
	for(i=0;i<26;i++)
	{
		if(s[0]-'a'!=i)
		{
			dp[0][1][i]=0;
		}
		else
		{
			dp[0][0][i]=0;
		}
	}
	for(i=1;i<s.size();i++)
	{
		for(j=0;j<=m;j++)
		{
			for(k=0;k<26;k++)
			{
				if(k==s[i]-'a')
				{
					for(l=0;l<26;l++)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][l]+v[l][k]);
					}
				}
				else if(j!=0)
				{
					for(l=0;l<26;l++)
					{
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][l]+v[l][k]);
					}
				}
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<26;j++)
		{
			ans=max(ans,dp[s.size()-1][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}