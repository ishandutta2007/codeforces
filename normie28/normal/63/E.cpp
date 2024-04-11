
// Problem : E. Sweets Game
// Contest : Codeforces - Codeforces Beta Round #59 (Div. 2)
// URL : https://codeforces.com/problemset/problem/63/E
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define inf 1000000000
#define pi acos(-1.0)
#define eps 1e-8
#define seed 131
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
typedef unsigned long long ull;
typedef long long ll;
//---------END-------//
const int maxn=100005;
int dp[1<<20];
char ch;
int sz[15]={3,4,5,4,3,3,4,5,4,3,3,4,5,4,3};
int d[15][5]={
    {0,1,2},
    {3,4,5,6},
    {7,8,9,10,11},
    {12,13,14,15},
    {16,17,18},
    {0,3,7},
    {1,4,8,12},
    {2,5,9,13,16},
    {6,10,14,17},
    {11,15,18},
    {7,12,16},
    {3,8,13,17},
    {0,4,9,14,18},
    {1,5,10,15},
    {2,6,11},
};
int dfs(int m)
{
    if(dp[m]!=-1)
        return dp[m];
    for(int i=0;i<15;i++)
    {
        for(int j=0;j<sz[i];j++)
        {
            for(int k=j;k<sz[i];k++)
            {
                bool flag=true;
                int pm=m;
                for(int f=j;f<=k;f++)
                {
                    if(pm&(1<<d[i][f]))
                        pm-=(1<<d[i][f]);
                    else
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    if(dfs(pm)==0)
                        return dp[m]=1;
                }
            }
        }
    }
    return dp[m]=0;
}
int main()
{
	fio;
    int mark=0;
    for(int i=0;i<19;i++)
    {
        cin>>ch;
        if(ch=='O')
        {
            mark|=(1<<i);
        }
    }
    memset(dp,-1,sizeof(dp));
    if(dfs(mark))
        cout<<"Karlsson";
    else
        cout<<"Lillebror";
}