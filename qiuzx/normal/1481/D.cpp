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
#define N 1010
using namespace std;
ll n,m,hv[N][2];
char buf[N];
string s[N];
pair<ll,ll> ans;
int main(){
	ll t,i,j,ele;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		ans=make_pair(-1,-1);
		memset(hv,-1,sizeof(hv));
		for(i=0;i<n;i++)
		{
			scanf("%s",&buf);
			s[i]=buf;
			for(j=0;j<s[i].size();j++)
			{
				if(s[i][j]=='a')
				{
					hv[i][0]=j;
				}
				else if(s[i][j]=='b')
				{
					hv[i][1]=j;
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(s[i][j]==s[j][i])
				{
					ans=make_pair(i,j);
					break;
				}
			}
			if(ans.F!=-1)
			{
				break;
			}
		}
		if(ans.F!=-1)
		{
			puts("YES");
			for(i=0;i<=m;i++)
			{
				if(i%2==0)
				{
					printf("%lld ",ans.F+1);
				}
				else
				{
					printf("%lld ",ans.S+1);
				}
			}
			puts("");
			continue;
		}
		if(m%2==1)
		{
			puts("YES");
			for(i=0;i<=m;i++)
			{
				if(i%2==0)
				{
					printf("1 ");
				}
				else
				{
					printf("2 ");
				}
			}
			puts("");
			continue;
		}
		if(n==2)
		{
			puts("NO");
			continue;
		}
		for(i=0;i<n;i++)
		{
			if(hv[i][0]!=-1&&hv[i][1]!=-1)
			{
				ele=i;
				break;
			}
		}
		if(m%4==0)
		{
			puts("YES");
			printf("%lld ",ele+1);
			for(i=0;i*4<m;i++)
			{
				printf("%lld %lld %lld %lld ",hv[ele][0]+1,ele+1,hv[ele][1]+1,ele+1);
			}
			puts("");
			continue;
		}
		puts("YES");
		printf("%lld ",hv[ele][0]+1);
		for(i=0;i*2<m;i++)
		{
			if(i%2==0)
			{
				printf("%lld ",ele+1);
			}
			else
			{
				printf("%lld ",hv[ele][0]+1);
			}
		}
		for(i=0;i*2<m;i++)
		{
			if(i%2==0)
			{
				printf("%lld ",hv[ele][1]+1);
			}
			else
			{
				printf("%lld ",ele+1);
			}
		}
		puts("");
	}
	return 0;
}