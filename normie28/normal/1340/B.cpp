
// Problem : B. Nastya and Scoreboard
// Contest : Codeforces - Codeforces Round #637 (Div. 1) - Thanks, Ivan Belonogov!
// URL : https://codeforces.com/contest/1340/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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
int n,m,k,c[501],pos[100001],t,t1,i,j,dp[2001][2001][10],com[2001][2001];
const string dig[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
string cur[2001];
int need (string s, string t)
{
    int res=0;
    for (int i=0;i<=6;i++)
    if (s[i]>t[i]) return 1e9;
    else res+=t[i]-s[i];
    return res;
}
int main()
{
//  ofile;
    fio;
    cin>>n>>m;
    for (i=n-1;i>=0;i--) cin>>cur[i];
    for (i=0;i<n;i++) for (j=0;j<=m;j++) for (k=0;k<10;k++)
    {
//        cout<<cur[i]<<' '<<dig[k]<<' '<<need(cur[i],dig[k])<<endl;
        if (i==0)
        {
            if (need(cur[i],dig[k])==j) dp[i][j][k]=0;
            else dp[i][j][k]=-1; 
        }
        else
        {
            int ne=need(cur[i],dig[k]);
            if ((ne<=j)and(com[i-1][j-ne])) dp[i][j][k]=j-ne;
            else dp[i][j][k]=-1;
        }
        if (dp[i][j][k]>=0) com[i][j]=1;
    }
    j=m;
    for (int i=n-1;i>=0;i--)
    {
        int nxt=-1;
        for (int jj=0;jj<10;jj++) if (dp[i][j][jj]>=0) nxt=jj;
        if (nxt<0) {cout<<-1; return 0;}
        cout<<nxt;
        j=dp[i][j][nxt];
    }
}