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
#define N 110
using namespace std;
ll n,dp[N][N][N];
string s,cont;
vector<string> alls;
map<string,ll> id;
ll find_lst(ll num,ll l,ll r)
{
	ll i,bran=0;
	vector<pair<char,ll> > exp;
	string chs=alls[num];
	for(i=l;i<=r;i++)
	{
		if(chs[i]=='+'||chs[i]=='-'||chs[i]=='*'||chs[i]=='/')
		{
			if(bran==0)
			{
				exp.push_back(make_pair(chs[i],i));
			}
		}
		else if(chs[i]=='(')
		{
			bran++;
		}
		else if(chs[i]==')')
		{
			bran--;
		}
	}
	if(exp.empty())
	{
		if(chs[l]=='(')
		{
			return -100;
		}
		return -1;
	}
	for(i=exp.size()-1;i>=0;i--)
	{
		if(exp[i].F=='+'||exp[i].F=='-')
		{
			return exp[i].S;
		}
	}
	return exp[exp.size()-1].S;
}
ll dfs(ll num,ll l,ll r)
{
	if(dp[num][l][r]!=-1)
	{
		return dp[num][l][r];
	}
	if(l>r)
	{
		return -1;
	}
	string nd="";
	ll plc=find_lst(num,l,r),a,b,i;
	if(plc==-100)
	{
		if(dfs(num,l+1,r-1)!=3)
		{
			dp[num][l][r]=0;
		}
		else
		{
			dp[num][l][r]=3;
		}
	}
	else if(plc==-1)
	{
		for(i=l;i<=r;i++)
		{
			nd+=alls[num][i];
		}
		if(!id.count(nd))
		{
			dp[num][l][r]=0;
		}
		else
		{
			dp[num][l][r]=dfs(id[nd],0,alls[id[nd]].size()-1);
		}
	}
	else
	{
		a=dfs(num,l,plc-1);
		b=dfs(num,plc+1,r);
		if(a==3||b==3)
		{
			dp[num][l][r]=3;
		}
		else
		{
			if(alls[num][plc]=='+')
			{
				dp[num][l][r]=1;
			}
			else if(alls[num][plc]=='-')
			{
				if(b==1)
				{
					dp[num][l][r]=3;
				}
				else
				{
					dp[num][l][r]=1;
				}
			}
			else if(alls[num][plc]=='*')
			{
				if(a==1||b==1)
				{
					dp[num][l][r]=3;
				}
				else
				{
					dp[num][l][r]=2;
				}
			}
			else
			{
				if(a==1||b==1||b==2)
				{
					dp[num][l][r]=3;
				}
				else
				{
					dp[num][l][r]=2;
				}
			}
		}
	}
	return dp[num][l][r];
}
int main(){
	char c;
	ll i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		c=getchar();
		while(c!='#')
		{
			c=getchar();
		}
		cin>>s;
		cin>>s;
		id[s]=i;
		c=getchar();
		cont="";
		while(c!='\n')
		{
			if(c!=' ')
			{
				cont+=c;
			}
			c=getchar();
		}
		alls.push_back(cont);
	}
	c=getchar();
	cont="";
	while(c!='\n')
	{
		if(c!=' ')
		{
			cont+=c;
		}
		c=getchar();
	}
	alls.push_back(cont);
	memset(dp,-1,sizeof(dp));
	if(dfs(n,0,cont.size()-1)==3)
	{
		puts("Suspicious");
	}
	else
	{
		puts("OK");
	}
	return 0;
}