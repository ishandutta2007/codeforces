
// Problem : C. Sergey's problem
// Contest : Codeforces - Codeforces Round #503 (by SIS, Div. 1)
// URL : https://codeforces.com/contest/1019/problem/C
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

int N, M, res, mod, val[50009];
vector < pair < int, bool > > v[2][100009];
 
bool Fin (int res)
{
    cout<<res;
    exit (0);
}
 
void add (int lin, int st, int dr, int val)
{
    if (st % 2 != lin) st ++;
    if (dr % 2 != lin) dr --;
    st /= 2, dr /= 2, st ++, dr ++;
    if (st > dr)
    {
        if (val) Fin (0);
        return ;
    }
    v[lin][st - 1].push_back (make_pair (dr, val));
    v[lin][dr].push_back (make_pair (st - 1, val));
}
 
void dfs (int lin, int nod, int x)
{
    if (val[nod] == -1) val[nod] = x;
    else
    {
        if (val[nod] != x) Fin (0);
        return ;
    }
    for (auto it = v[lin][nod].begin (); it != v[lin][nod].end (); it ++)
        dfs (lin, it->first, x ^ it->second);
}
 
void Solve (int rest)
{
    for (int i=0; (i - 1) * 2 + rest < N; i++)
        val[i] = -1;
    for (int i=0; (i - 1) * 2 + rest < N; i++)
        if (val[i] == -1)
        {
            dfs (rest, i, 1);
            if (i > 0) res += res;
            if (res >= mod) res -= mod;
        }
}
 
int main ()
{
 
cin>>N>>M, mod = 1e9 + 7, res = 1;
 
while (M --)
{
    char c;
    int i, j, st = 0, dr = N - 1;
    cin>>i>>j>>c, i --, j --;
    if (c == 'o') c = 1;
    else c = 0;
    dr = min (i + j, 2 * (N - 1) - i - j), st = max (i - j, j - i);
    add ((i + j) & 1, st, dr, c);
}
Solve (0), Solve (1);
cout<<res;
}