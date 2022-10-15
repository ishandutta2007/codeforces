
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1166/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
const int N = 2e5 +10;
vector<pair<int, pair<int, int> > > g[N];
int edgev[N];
int s[N], remain[N];
bool bz[N];
int n, m;
void dfs(int x) {
    bz[x] = 1;
    remain[x] = s[x];
    for (auto u:g[x])
        if (!bz[u.first]) {
            dfs(u.first);
            edgev[u.second.first] += remain[u.first] * u.second.second;
            remain[x] += remain[u.first];
        }
}
int main() {
    scanf("%d", &n);
    int all = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &s[i]), all += s[i];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i ++ ){
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].push_back(make_pair(y, make_pair(i, 1)));
        g[y].push_back(make_pair(x, make_pair(i, -1)));
    }
    if (all) {
        printf("Impossible");
        return 0;
    }
    dfs(1);
    printf("Possible\n");
    for (int i = 1; i <= m; i ++)
        printf("%d\n", edgev[i]);
    return 0;
}