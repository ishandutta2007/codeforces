
// Problem : C. Maxim and Matrix
// Contest : Codeforces - Codeforces Round #160 (Div. 1)
// URL : https://codeforces.com/problemset/problem/261/C
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
ll n,m,k,c[501],pos[100001],t,t1,i,j,dp[65][65][2],bt[64];
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    if (log2(k)==floor(log2(k)))
    {
    	m=log2(k)+1;
    	n++;
    	for (i=0;i<64;i++)
    	{
    	bt[i]=n%2;
    	n/=2;
    	}
    	for (i=0;i<2;i++) dp[0][0][i]=1;
    	for (i=1;i<=64;i++) for (j=0;j<=m;j++) for (k=0;k<2;k++)
    	{
    		if ((j)and((bt[i-1]==1)or(k)))
    		dp[i][j][k]+=dp[i-1][j-1][k];
    		if (bt[i-1]==0)
    		dp[i][j][k]+=dp[i-1][j][k];
    		else dp[i][j][k]+=dp[i-1][j][1];
    	}
    	if (m==1) cout<<dp[64][m][0]-1; else cout<<dp[64][m][0];
    }
    else cout<<0;
}
/*
000000001 ->0
000000010 ->1
000000101 ->2
000001000 ->3
000010100 ->4
000100010 ->5
001010101 ->6
010000000 ->7
*/