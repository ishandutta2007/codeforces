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
#define N 300010
using namespace std;
ll n,lft[N][2],rht[N][2];
char buf[N];
string s;
int main(){
	ll t,i;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		scanf("%s",&buf);
		s=buf;
		for(i=0;i<=n;i++)
		{
			lft[i][0]=lft[i][1]=0;
			rht[i][0]=rht[i][1]=0;
		}
		for(i=1;i<=n;i++)
		{
			if(s[i-1]=='L')
			{
				lft[i][0]=lft[i-1][1]+1;
			}
			else
			{
				lft[i][1]=lft[i-1][0]+1;
			}
		}
		for(i=n-1;i>=0;i--)
		{
			if(s[i]=='L')
			{
				rht[i][1]=rht[i+1][0]+1;
			}
			else
			{
				rht[i][0]=rht[i+1][1]+1;
			}
		}
		for(i=0;i<=n;i++)
		{
			printf("%lld ",lft[i][0]+rht[i][0]+1);
		}
		puts("");
	}
	return 0;
}