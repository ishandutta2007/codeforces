//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
using namespace std;
ll dp[10][10][10][2][2][2][2];
pair<pair<ll,ll>,pair<ll,ll> > lst[10][10][10][2][2][2][2];
vector<ll> a,b,c;
string s,ansa="",ansb="",ansc="";
ll dfs(ll x,ll y,ll z,ll t,ll k1,ll k2,ll k3)
{
	if(dp[x][y][z][t][k1][k2][k3]!=-1)
	{
		return dp[x][y][z][t][k1][k2][k3];
	}
	if(x==0&&y==0&&z==0)
	{
		return dp[x][y][z][t][k1][k2][k3]=(t==0?0:INF);
	}
	dp[x][y][z][t][k1][k2][k3]=INF;
	ll v,i,j,k,u;
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<10;k++)
			{
				for(u=0;u<2;u++)
				{
					if(i+j+u==k+t*10&&(i==a[x]||j==b[y]||k==c[z]))
					{
						v=dfs(x-(i==a[x]),y-(j==b[y]),z-(k==c[z]),u,k1&&(i==0),k2&&(j==0),k3&&(k==0))+((!k1)||i>0)+((!k2)||j>0)+((!k3)||k>0);
						if(v<dp[x][y][z][t][k1][k2][k3])
						{
							dp[x][y][z][t][k1][k2][k3]=v;
							lst[x][y][z][t][k1][k2][k3]=make_pair(make_pair(i,j),make_pair(k,u));
						}
					}
				}
			}
		}
	}
	return dp[x][y][z][t][k1][k2][k3];
}
void getpath(ll x,ll y,ll z,ll t,ll k1,ll k2,ll k3)
{
	if(x==0&&y==0&&z==0)
	{
		return;
	}
	ll i=lst[x][y][z][t][k1][k2][k3].F.F,j=lst[x][y][z][t][k1][k2][k3].F.S,k=lst[x][y][z][t][k1][k2][k3].S.F,u=lst[x][y][z][t][k1][k2][k3].S.S;
	if((!k1)||i>0)
	{
		ansa+=(char)(i+'0');
	}
	if((!k2)||j>0)
	{
		ansb+=(char)(j+'0');
	}
	if((!k3)||k>0)
	{
		ansc+=(char)(k+'0');
	}
	getpath(x-(i==a[x]),y-(j==b[y]),z-(k==c[z]),u,k1&&(i==0),k2&&(j==0),k3&&(k==0));
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,x1,x2;
	cin>>s;
	x1=s.find('+');
	x2=s.find('=');
	a.push_back(-1),b.push_back(-1),c.push_back(-1);
	for(i=x1-1;i>=0;i--)
	{
		a.push_back(s[i]-'0');
	}
	for(i=x2-1;i>x1;i--)
	{
		b.push_back(s[i]-'0');
	}
	for(i=s.size()-1;i>x2;i--)
	{
		c.push_back(s[i]-'0');
	}
	memset(dp,-1,sizeof(dp));
	x1=dfs(a.size()-1,b.size()-1,c.size()-1,0,1,1,1);
	x2=dfs(a.size()-1,b.size()-1,c.size()-1,1,1,1,1)+1;
	if(x1<=x2)
	{
		getpath(a.size()-1,b.size()-1,c.size()-1,0,1,1,1);
	}
	else
	{
		ansc+="1";
		getpath(a.size()-1,b.size()-1,c.size()-1,1,1,1,1);
	}
	cout<<ansa<<"+"<<ansb<<"="<<ansc<<endl;
	return 0;
}