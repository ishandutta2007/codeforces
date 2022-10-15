
// Problem : F. Nearest Leaf
// Contest : Codeforces - Codeforces Global Round 1
// URL : https://codeforces.com/problemset/problem/1110/F
// Memory Limit : 512 MB
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
#pragma GCC optimize("Ofast,vectorize")
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

#define all(s) s.begin(),s.end()
#define sz(s) ll(s.size())
 
void solve() {
    ll n, m, t;
    cin >> n >> m >> t;
    vector<ll> a(n);
    for (ll& aa : a) { cin >> aa; }
    auto b = a;
    sort(all(b));
    ll left = -1, right = b.size();
    while (left != right - 1) {
        ll mid = (left + right) >> 1;
        ll t1 = 0, group = 0, cnt = 0, y = 0;
        for (ll i = 0; i < n; ++i) {
            if (a[i] > b[   mid]) {
                continue;
            }
            if (y == mid + 1) { continue; }
            if (cnt == m) {
                t1 += group;
                group = 0;
                cnt = 0;
            }
            ++y;
            group += a[i];
            cnt++;
            t1 += a[i];
        }
        if (t1 <= t) {
            left = mid;
        } else {
            right = mid;
        }
    }
    if (left == -1) {
        cout << "0 1\n";
    } else {
        cout << left + 1 << " " << b[left] << '\n';
    }
}
 
int main() {
    fio;
    ll t = 0;
    cin >> t;
    while (t--) {
        solve();
    }
}