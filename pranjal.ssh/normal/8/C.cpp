#include<bits/stdc++.h>
#include <math.h>
using namespace std;

#define MOD 1000000007
#define MAX 1000
#define ll long long

#define sd(t) scanf("%d",&t)
#define sld(t) scanf("%ld",&t)
#define pd(t) printf("%d\n",t)

#define pcc pair<char,char>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tr(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define mp(a,b) make_pair(a,b)
#define F first
#define S second
#define Lim 5000007
#define pb(x) push_back(x)

int dp[16777250]; int x[30]; int y[30];
int q[16777250];
int dist( int m, int n)
{
	int ans = (x[m]-x[n])*(x[m]-x[n]) + (y[m]-y[n])*(y[m]-y[n]);
	return ans;
}

int main()
{
	int a,b;
	sd(a); sd(b);
	int n;
	sd(n);
	for( int i=0; i<n; i++)
	{
		sd(x[i]);
		sd(y[i]);
	}
	for( int i=1; i<(1<<n); i++)
	{
		dp[i] = 1000000;
	}
	dp[0] = 0;
	x[n] = a; y[n] = b;
//	cout<<dp[0]<<" "<<dp[1]<<endl;
	for( int mask=0; mask<pow(2,n); mask++)
	{
		for( int i=0; i<n; i++)
		{
			if(!(mask&(1<<i)))
			{
				for( int j=i; j<n; j++)
				{
					if(!(mask&(1<<j)))
					{
						if(dp[mask] + dist(i,n) + dist(i,j) + dist(j,n) < dp[mask|(1<<i)|(1<<j)])
						{
							dp[mask|(1<<i)|(1<<j)] = dp[mask] + dist(i,n) + dist(i,j) + dist(j,n);
							q[mask|(1<<i)|(1<<j)] = mask;
						}
					}
				}
				break;
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	int cur = (1<<n)-1;
	cout<<0<<" ";
	while(cur!=0)
	{
		int next = q[cur];
		for( int i=0; i<n; i++)
		{
			if(((1<<i) & next) == 0 && ((1<<i) & cur) !=0)
			{
				cout<<i+1<<" ";
			}
		}
		cout<<0<<" ";
		cur = next;
	}
}