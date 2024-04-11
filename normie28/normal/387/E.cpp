
// Problem : E. George and Cards
// Contest : Codeforces - Codeforces Round #227 (Div. 2)
// URL : https://codeforces.com/problemset/problem/387/E
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
int n,m,k,c[501],t,t1,j;
const int maxn = 1e6 + 10, lg = 30;
struct fenwick {
    int data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) data[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += data[x]; return ret; }
} bit;
int a[maxn], b[maxn], pos[maxn];
bool v[maxn];
int main() {
	fio;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
    for (int i = 1; i <= k; ++i) cin >> b[i], v[b[i]] = true;
    vector<int> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(i);
    sort(vec.begin(), vec.end(), [&](const int &i, const int &j) { return a[i] < a[j]; });
    bit.init();
    for (int i = 1; i <= n; ++i) bit.add(i, 1);
    long long res = 0;
    set<int> prv;
    prv.insert(0); prv.insert(n + 1);
    for (int p : vec) {
        if (v[a[p]]) {
            prv.insert(p);
            continue;
        } 
        int l = *(--prv.lower_bound(p));
        int r = *prv.upper_bound(p) - 1;
        res += bit.qry(r) - bit.qry(l);
        bit.add(p, -1);
    }
    cout << res << endl;
}