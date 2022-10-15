
// Problem : B. Game with modulo
// Contest : Codeforces - Codeforces Round #534 (Div. 1)
// URL : https://codeforces.com/contest/1103/problem/B
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
#define bi BigInt
typedef long long ll;
//---------END-------//
struct Range {
    int l, r, h, id;
    Range() {}
    Range(int x, int y, int z, int i) {
        l = x, r = y, h = z, id = i;
    }
    bool operator < (const Range &R) const {
        return l < R.l;
    }
};
 
const int inf = 1e9;
 
int main() {
    fio;
 
    int n, t;
    cin >> n >> t;
    vector<Range> v(n+1);
    v[0] = Range(-inf,inf,0,0);
    for(int i = 1; i <= n; i++) cin >> v[i].h >> v[i].l >> v[i].r;
    v.push_back(Range(-inf,inf,t,n+1));
    sort(v.begin(), v.end(), [&](Range a, Range b) { return a.h < b.h;});
    for(int i = 0; i < v.size(); i++) v[i].id = i;
    set<Range> visible;
    visible.insert(v[0]);
    vector<int> res(n+2);
    res[0] = 2*inf;
    for(int i = 1; i < v.size(); i++) {
        auto it = visible.upper_bound(v[i]);
        if(it != visible.begin()) it--;
        vector<Range> Erase, Add = {v[i]};
        while(it != visible.end()) {
            Range down = *it;
            if(down.l >= v[i].r) break;
            Erase.push_back(down);
            if(down.l <= v[i].l && down.r >= v[i].r) {
                Range R1 = Range(down.l, v[i].l, down.h, down.id);
                Range R2 = Range(v[i].r, down.r, down.h, down.id);
                Add.push_back(R1);
                Add.push_back(R2);
            }
            else if(down.l <= v[i].l) {
                Range R1 = Range(down.l, v[i].l, down.h, down.id);
                Add.push_back(R1);
            }
            else if(down.r >= v[i].l) {
                Range R1 = Range(v[i].r, down.r, down.h, down.id);
                Add.push_back(R1);
            }
            int id = down.id;
            int ll = max(v[i].l, v[id].l), rr = min(v[i].r, v[id].r);
            if(ll >= down.l && rr <= down.r) {
                res[i] = max(res[i], min(res[id], (rr-ll)));
            }
            it++;
        }
        for(auto tt : Erase) visible.erase(tt);
        for(auto tt : Add) {
            if(tt.l < tt.r) visible.insert(tt);
        }
    }
    cout << res[n+1] << endl;
    return 0;
}