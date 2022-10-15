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
#define MOD (ll(1000000007))
#define MAXN 1000001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,decltype(cmp),rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
 
int N, len, at ;
int dp[MAXN][4], pt ;
char ss[MAXN] ;
 
void Dfs(int now)
{
    int i, j, ls, rs ;
    char tmp ;    
    switch(ss[at])
    {
        case '0': dp[now][0] = 1; return; break ;
        case '1': dp[now][3] = 1; return; break ;
        case '?': dp[now][1] = dp[now][2] = 1; return; break ;
        default: break ;
    }
    if(ss[at] == '(')
    {
        at ++, Dfs(ls = ++pt) ;
        at ++, tmp = ss[at] ;
        at ++, Dfs(rs = ++pt), at ++ ;
        if(tmp == '^')
        for(i = 0; i <= 3; i ++)
            for(j = 0; j <= 3; j ++)
                    dp[now][i^j] |= (dp[ls][i]&dp[rs][j]) ;
        else if(tmp == '|')
        for(i = 0; i <= 3; i ++)
            for(j = 0; j <= 3; j ++)
                    dp[now][i|j] |= (dp[ls][i]&dp[rs][j]) ;
        else if(tmp == '&')
            for(i = 0; i <= 3; i ++)
                for(j = 0; j <= 3; j ++)
                    dp[now][i&j] |= (dp[ls][i]&dp[rs][j]) ;    
    }
}
 
int main()
{
    fio;
    int i, j ; 
    cin>>N>>ss;
    pt = 1, Dfs(1) ;
    cout<<((dp[1][1]|dp[1][2])?"YES":"NO");
}