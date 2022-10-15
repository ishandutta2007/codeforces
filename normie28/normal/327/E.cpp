
// Problem : E. Axis Walking
// Contest : Codeforces - Codeforces Round #191 (Div. 2)
// URL : https://codeforces.com/problemset/problem/327/E
// Memory Limit : 512 MB
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
#pragma GCC optimize(3)
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD ((1000000007))
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
const int maxn = 24, P = 1e9 + 7;
int n, m, flg[3], f[1 << maxn], dis[1 << maxn];
 
int main() {
	fio;
	cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>dis[1 << i];
    }
    cin>>m;
    for (int i = 1; i <= m; i++) {
        cin>>flg[i];
    }
    f[0] = 1;
    for (int S = 1; S < 1 << n; S++) {
        dis[S] = dis[S ^ (S & -S)] + dis[S & -S];
        if (dis[S] == flg[1] || dis[S] == flg[2]) continue;
        for (int sub = S; sub; sub &= sub - 1) {
            (f[S] += f[S ^ (sub & -sub)]) >= P && (f[S] -= P);
        }
    }
    cout<<f[(1 << n) - 1];
}