
// Problem : C. Game with Strings
// Contest : Codeforces - Codeforces Round #275 (Div. 1)
// URL : https://codeforces.com/problemset/problem/482/C
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
//---------END-------//
const int N = 55;
int n,m;
char s[N][25];
ll dp[1 << 20],sum[N];
int main ()
{
	fio;
    cin >> n;
    for (int i = 0;i < n;i++) cin >> s[i],m = strlen(s[i]);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
        {
            if (i == j) continue;
            int fl = 0;
            for (int k = 0;k < m;k++) if (s[i][k] == s[j][k]) fl |= 1 << k;
            dp[fl] |= 1ll << i;
        }
    for (int i = (1 << m) - 1;i >= 0;--i)
        for (int j = 0;j < m;j++)
            if (i & (1 << j)) dp[i ^ (1 << j)] |= dp[i];
    for (int i = 0;i < (1 << m);i++)
    {
        int cc = __builtin_popcount(i) + 1;
        for (int j = 0;j < m;j++)
            if (!(i & (1 << j)))
                sum[cc] += __builtin_popcountll(dp[i] ^ dp[i | (1 << j)]);
    }
    double res = 0;
    for (int i = 1;i <= m;i++)
    {
        double cur = sum[i] * i;
        for (int j = 0;j < i - 1;j++) cur *= (i - 1 - j) * 1.0 / (m - j);
        res += cur / (m - (i - 1));
    }
    cout<<fixed<<setprecision(12)<<res/n<<endl;
}