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
#define N 100010
using namespace std;
ll n,a[N],lst[N],dp[N],lon[N];
bool ad[N];
vector<ll> ze;
string s,ans;
void solve1(char c)
{
	ll i;
	for(i=0;i+1<n;i++)
	{
		printf("%lld%c",a[i],c);
	}
	printf("%lld\n",a[n-1]);
	return;
}
void solve2()
{
	ll i;
	for(i=0;i+1<n;i++)
	{
		printf("%lld+",a[i]);
	}
	printf("%lld\n",a[n-1]);
	return;
}
void solve3()
{
	ll i,j;
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			break;
		}
	}
	if(i==n)
	{
		for(i=0;i+1<n;i++)
		{
			printf("%lld*",a[i]);
		}
		printf("%lld\n",a[n-1]);
		return;
	}
	for(j=0;j<i-1;j++)
	{
		printf("%lld*",a[j]);
	}
	if(i!=0)
	{
		printf("%lld-",a[i-1]);
	}
	printf("%lld",a[i]);
	for(j=i+1;j<n;j++)
	{
		printf("*%lld",a[j]);
	}
	puts("");
	return;
}
ll dfs(ll l,ll x)
{
	if(x<l)
	{
		return 0;
	}
	if(dp[x]!=-1)
	{
		return dp[x];
	}
	ll p=1,i,j,tr;
	dp[x]=0;
	for(i=x;i>=l;i--)
	{
		p*=a[i];
		tr=dfs(l,i-1)+p;
		if(dp[x]<tr)
		{
			dp[x]=tr;
			lst[x]=i;
		}
		j=i;
		i=lon[i]+1;
		tr=dfs(l,i-1)+j-i+p;
		if(dp[x]<tr)
		{
			dp[x]=tr;
			lst[x]=i;
		}
	}
	return dp[x];
}
void gpath(ll l,ll x)
{
	if(x<l)
	{
		return;
	}
	ad[lst[x]]=true;
	gpath(l,lst[x]-1);
	return;
}
void solve4()
{
	memset(dp,-1,sizeof(dp));//too large->INF+2
	memset(lst,-1,sizeof(lst));//last place to place a '+' eg. 2+3+4*5*6*7+8: lst[4]=2
	ll i,j,l=-1,p;
	ze.push_back(-1);
	for(i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			ad[i]=ad[i+1]=true;
			ze.push_back(i);
		}
	}
	ze.push_back(n);
	for(i=0;i<n;i++)
	{
		lon[i]=l;
		if(a[i]!=1)
		{
			l=i;
		}
	}
	for(i=0;i+1<ze.size();i++)
	{
		p=1;
		for(j=ze[i]+1;j<ze[i+1];j++)
		{
			p*=a[j];
			if(p>(ll)100*INF)
			{
				break;
			}
		}
		if(p<=(ll)100*INF)
		{
			dfs(ze[i]+1,ze[i+1]-1);
			gpath(ze[i]+1,ze[i+1]-1);
		}
		else
		{
			for(j=ze[i]+1;j<ze[i+1]&&a[j]==1;j++)
			{
				ad[j]=true;
			}
			ad[j]=true;
			for(j=ze[i+1]-1;j>ze[i]&&a[j]==1;j--)
			{
				ad[j+1]=true;
			}
			ad[j+1]=true;
		}
	}
	printf("%lld",a[0]);
	for(i=1;i<n;i++)
	{
		if(ad[i])
		{
			printf("+%lld",a[i]);
		}
		else
		{
			printf("*%lld",a[i]);
		}
	}
	puts("");
	return;
}
int main(){
	ll i;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	cin>>s;
	if(s.size()==1)
	{
		solve1(s[0]);
		return 0;
	}
	if(s.find('*')==-1)
	{
		solve2();
		return 0;
	}
	if(s.find('+')==-1)
	{
		solve3();
		return 0;
	}
	solve4();
	return 0;
}