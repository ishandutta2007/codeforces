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
using namespace std;
ll n,win[110],los[110],ans[110][110];
int main(){
	ll T,i,j,w;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		memset(win,0,sizeof(win));
		memset(los,0,sizeof(los));
		if(n%2==0)
		{
			w=(n-2)/2;
			for(i=0;i<n;i+=2)
			{
				ans[i][i+1]=0;
			}
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(j==i+1&&i%2==0)
					{
						continue;
					}
					if(win[i]>=w)
					{
						los[i]++;
						win[j]++;
						ans[i][j]=-1;
					}
					else
					{
						if(n-2-los[j]==w)
						{
							los[i]++;
							win[j]++;
							ans[i][j]=-1;
						}
						else
						{
							win[i]++;
							los[j]++;
							ans[i][j]=1;
						}
					}
				}
			}
		}
		else
		{
			w=(n-1)/2;
			for(i=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					if(win[i]>=w)
					{
						los[i]++;
						win[j]++;
						ans[i][j]=-1;
					}
					else
					{
						if(n-1-los[j]==w)
						{
							los[i]++;
							win[j]++;
							ans[i][j]=-1;
						}
						else
						{
							win[i]++;
							los[j]++;
							ans[i][j]=1;
						}
					}
				}
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				printf("%lld ",ans[i][j]);
			}
		}
		puts("");
	}
	return 0;
}