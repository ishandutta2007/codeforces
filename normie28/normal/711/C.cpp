// Thanks to robs77 for this template
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <iomanip>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
/***********MACROS***************/
//#define int long long
//#define inf 100000000000000000 
#define ll  long long 
#define LL long long
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define mxsz 1000000007
#define mxval 1e9 + 7
#define grt [](auto x,auto y){return x>y;}
#define pii pair<int,int>
#define fi first 
#define se second 
#define for1(i, n) for(ll i=1; i<=n; ++i)
#define for0(i, n) for(ll i=0; i<n; ++i)
//#define mod 1000000007
/*********VARIABLE****************/
using namespace std;
typedef pair<int,int> ii;
/******************************/
const ll inf=1e11;
ll dp[111][111][111];
ll ans,a[111][111],c[111],l[111],r[111];
int n,m,k;
/*********FUNCTIONS**************/
/***********MAIN**************/

signed main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int x=0;x<=k;x++)
				dp[i][j][x]=inf;
	for(int i=1;i<=n;i++)
	{
		if(c[i])
		{
			l[i]=r[i]=c[i];
			a[i][c[i]]=0;
		}
		else
		{
			l[i]=1;
			r[i]=m;
		}
	}
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=l[i];j<=r[i];j++)
			for(int x=1;x<=k&&x<=i;x++)
				for(int y=l[i-1];y<=r[i-1];y++)
					dp[i][j][x]=min(dp[i][j][x],dp[i-1][y][x-(j!=y)]+a[i][j]);
	ans=inf;
	for(int i=1;i<=m;i++)
		ans=min(ans,dp[n][i][k]);
	if(ans==inf)
	ans=-1;
	cout<<ans;
}