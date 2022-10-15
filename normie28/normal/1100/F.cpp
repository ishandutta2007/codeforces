
// Problem : F. Ivan and Burgers
// Contest : Codeforces - Codeforces Round #532 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1100/F
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
const int N = 5e5 + 10;
int xxj[N][30], n, m, a[N], pre[N][30];
void add(int x, int n) {
    int net = n;
    for(int i = 0; i < 30; i++)
        xxj[n][i] = xxj[n - 1][i], pre[n][i] = pre[n - 1][i];
    for(int i = 29; i >= 0; i--) {
        if(x & (1 << i)) {
            if(!xxj[n][i]) {
                xxj[n][i] = x;
                pre[n][i] = net;
                return;
            }
            if(net > pre[n][i]) {
                swap(pre[n][i], net);
                swap(xxj[n][i], x);
            }
            x ^= xxj[n][i];
        }
    }
}
int main() {
	fio;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i], add(a[i], i);
    cin >> m;
    while(m--) {
        int l, r;
        cin >> l >> r;
        int res = 0;
        for(int i = 29; i >= 0; i--)
            if(pre[r][i] >= l)
                if(res < (res ^ xxj[r][i]))
                    res ^= xxj[r][i];
        cout << res << endl;
    }
}