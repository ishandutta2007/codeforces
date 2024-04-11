
// Problem : F. Extending Set of Points
// Contest : Codeforces - Educational Codeforces Round 62 (Rated for Div. 2)
// URL : https://codeforces.com/problemset/problem/1140/F
// Memory Limit : 1024 MB
// Time Limit : 3500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
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
const int Q = 3e5 + 5;
 
vector<pair<int, int>> tree[4 * Q];
long long res[Q], ans = 0;
int cur = 0, par[2 * Q], sizeX[2 * Q], sizeY[2 * Q], val[50 * Q];
int* where[50 * Q];
 
void update(int idx, int b, int e, int l, int r, pair<int, int> p) {
    if (b == l && r == e) {
        tree[idx].push_back(p);
        return;
    }
    int m = (b + e) / 2;
    if (l < m)
        update(idx * 2 + 1, b, m, l, min(m, r), p);
    if (r > m)
        update(idx * 2 + 2, m, e, max(m, l), r, p);
}
 
void change(int& a, int b) {
    where[cur] = &a;
    val[cur] = a;
    a = b;
    ++cur;
}
 
int find(int u) {
    return u == par[u] ? u : find(par[u]);
}
 
void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
        return;
    ans -= 1LL * sizeX[u] * sizeY[u];
    ans -= 1LL * sizeX[v] * sizeY[v];
    if (sizeX[u] + sizeY[u] < sizeX[v] + sizeY[v])
        swap(u, v);
    change(par[v], u);
    change(sizeX[u], sizeX[u] + sizeX[v]);
    change(sizeY[u], sizeY[u] + sizeY[v]);
    ans += 1LL * sizeX[u] * sizeY[u];
}
 
void rollback() {
    --cur;
    *where[cur] = val[cur];
}
 
void dfs(int idx, int b, int e) {
    long long lastAns = ans;
    int state = cur;
    for (auto [x, y] : tree[idx])
        unite(x * 2, y * 2 + 1);
    if (b + 1 == e) {
        res[b] = ans;
    } else {
        int m = (b + e) / 2;
        dfs(idx * 2 + 1, b, m);
        dfs(idx * 2 + 2, m, e);
    }
    while (cur != state)
        rollback();
    ans = lastAns;
}
 
int main() {
	fio;
    int q;
    cin >> q;
    map<pair<int, int>, int> last;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (last.count({x, y})) {
            update(0, 0, q, last[{x, y}], i, {x, y});
            last.erase({x, y});
        } else {
            last[{x, y}] = i;
        }
    }
    for (auto [p, i] : last) {
        update(0, 0, q, i, q, p);
    }
    for (int i = 0; i < 2 * Q; ++i) {
        par[i] = i;
        if (i & 1)
            sizeY[i] = 1;
        else
            sizeX[i] = 1;
    }
    dfs(0, 0, q);
    for (int i = 0; i < q; ++i)
        cout << res[i] << ' ';
}