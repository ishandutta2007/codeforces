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
#define N 500010
using namespace std;
char buf[N];
ll occ[2*N],ed[2*N],sum;
string s;
bool check(ll x)
{
	if(occ[x+1]==0)
	{
		return true;
	}
	if(occ[x-1]==0)
	{
		return false;
	}
	if(ed[x-1]==1)
	{
		return false;
	}
	return true;
}
int main(){
	ll T,i;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%s",&buf);
		s=buf;
		sum=s.size();
		for(i=0;i<=2*sum;i++)
		{
			ed[i]=0;
			occ[i]=0;
		}
		for(i=0;i<s.size();i++)
		{
			if(s[i]=='1')
			{
				ed[sum]++;
				sum++;
			}
			else
			{
				sum--;
				ed[sum]++;
			}
			occ[sum]++;
		}
		sum=s.size();
		for(i=0;i<s.size();i++)
		{
			if(check(sum))
			{
				printf("0");
				sum--;
				ed[sum]--;
			}
			else
			{
				printf("1");
				ed[sum]--;
				sum++;
			}
			occ[sum]--;
		}
		puts("");
	}
	return 0;
}