
// Problem : E. Magical Permutation
// Contest : Codeforces - Codeforces Round #558 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1163/E
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
const int N = 1000006;
int n, cntv, cnte, A[N], B[N];
bool M[N * 2], P[N * 2];
vector < int > U, Adj[N * 2];
void DFS(int v)
{
    M[v] = 1; cntv ++;
    cnte += Adj[v].size();
    for (int &u : Adj[v])
        if (!M[u]) DFS(u);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &A[i], &B[i]);
        U.push_back(A[i]);
        U.push_back(B[i]);
    }
    sort(U.begin(), U.end());
    U.resize(unique(U.begin(), U.end()) - U.begin());
    for (int i = 0; i < n; i++)
    {
        A[i] = lower_bound(U.begin(), U.end(), A[i]) - U.begin();
        B[i] = lower_bound(U.begin(), U.end(), B[i]) - U.begin();
        Adj[A[i]].push_back(B[i]);
        Adj[B[i]].push_back(A[i]);
    }
    for (int i = (int)U.size() - 1; ~i; i --)
        if (!M[i])
        {
            cntv = cnte = 0;
            DFS(i); cnte >>= 1;
            if (cnte > cntv)
                return !printf("-1");
            if (cnte < cntv)
                P[i] = 1;
        }
    int Mn = U.size() - 1;
    for (; P[Mn]; Mn --);
    return !printf("%d", U[Mn]);
}