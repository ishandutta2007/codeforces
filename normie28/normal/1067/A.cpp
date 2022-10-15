
// Problem : A. Array Without Local Maximums
// Contest : Codeforces - Codeforces Round #518 (Div. 1) [Thanks, Mail.Ru!]
// URL : https://codeforces.com/contest/1067/problem/A
// Memory Limit : 512 MB
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
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
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
#define MOD (ll(998244353))
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
int n,m,k,c[501],arr[100001],t,t1,i,j;
int dp[100001][201][2]; int presum[100001][201][2];
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<=n;i++) cin>>arr[i];
    for (i=n;i>=1;i--) for (j=1;j<=200;j++) for (k=0;k<2;k++)
    {
    	if ((arr[i]!=-1)and(arr[i]!=j)) dp[i][j][k]=0;
    	else
    	if (i==n)
    	{
    		if (k) dp[i][j][k]=1;
    		else dp[i][j][k]=0;
    	}
    	else
    	{
    		if (k) dp[i][j][k]=(presum[i+1][200][0]-presum[i+1][j][0]+presum[i+1][j][1]+MOD)%MOD;
    		else dp[i][j][k]=(presum[i+1][200][0]-presum[i+1][j][0]+dp[i+1][j][1]+MOD)%MOD;
    	}
    	presum[i][j][k]=(presum[i][j-1][k]+dp[i][j][k])%MOD;
    }
    cout<<presum[1][200][0];
}