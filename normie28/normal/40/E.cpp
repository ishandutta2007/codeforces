
// Problem : E. Number Table
// Contest : Codeforces - Codeforces Beta Round #39
// URL : https://codeforces.com/problemset/problem/40/E
// Memory Limit : 216 MB
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
typedef long long LL;
//---------END-------//
const int N = 1e6 + 50;
int n, m, p, k, num[N], now[N], dat;
bool flag;
int power(int x, LL y) {
    int z = 1;
    for (; y; y >>= 1, x = 1ll * x * x % p)
        if (y & 1)
            z = 1ll * z * x % p;
    return z;
}
int main() {
	fio;
	cin>>n>>m>>k;
    if (n < m)
        swap(n, m), flag = 1;
    if ((n + m) & 1)
        puts("0"), exit(0);
    for (int i = 1, x, y, z; i <= k; i++) {
        cin>>x>>y>>z;
        if (flag)
            swap(x, y);
        num[x]++;
        now[x] ^= z == -1;
    }
    cin>>p;
    flag = 0;
    for (int i = 1; i <= n; i++)
        if (num[i] == m && !now[i])
            flag = 1;
        else
            dat += min(num[i], m - 1);
    cout<< (flag ? 0 : power(2, 1ll * (n - 1) * (m - 1) - dat));
}