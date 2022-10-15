
// Problem : C. Remembering Strings
// Contest : Codeforces - Codeforces Round #302 (Div. 1)
// URL : https://codeforces.com/problemset/problem/543/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
const int maxn=25,inf=0x3f3f3f3f;
int n,m,i,j,k,dp[1<<22],cst[maxn][maxn],sme[maxn][maxn],a[maxn][maxn];
string s[maxn];
int main()
{
	fio;
	cin>>n>>m;
	for (i=1;i<=n;i++)
	{
		cin>>s[i];
		s[i]=' '+s[i];
	}
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>a[i][j];
	for (i=1;i<=n;i++) for (j=1;j<=m;j++)
		{
			sme[i][j]=0;
			int mx=a[i][j];
			for (k=1;k<=n;k++)
				if(s[k][j]==s[i][j])
				{
					mx=max(mx,a[k][j]);
					sme[i][j]|=1<<k-1;
					cst[i][j]+=a[k][j];
				}
			cst[i][j]-=mx;
		}
	memset(dp,inf,sizeof(dp));
	dp[0]=0;
	for(int i=0;i<(1<<n);i++)
		for(int j=1;j<=n;j++)
			if(((1<<j-1)&i)==0)
				for(int k=1;k<=m;k++)
				{
					dp[i|sme[j][k]]=min(dp[i|sme[j][k]],dp[i]+cst[j][k]);
					dp[i|(1<<j-1)]=min(dp[i|(1<<j-1)],dp[i]+a[j][k]);
				}
	cout<<dp[(1<<n)-1];
}