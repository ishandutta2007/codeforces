
// Problem : E. Garlands
// Contest : Codeforces - Codeforces Round #368 (Div. 2)
// URL : https://codeforces.com/problemset/problem/707/E
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
#define pb push_back
typedef double f80;
//---------END-------//
const int mod = 1e9 + 7;
 
int n, m, k;
const int N = 2001;
ll bit[N][N];
void update(int x,int y,int val){
    for(int i = x; i <= n; i += i & -i)
        for(int j = y; j <= m; j += j & -j)
            bit[i][j] += val;
}
ll sum(int x,int y){
    ll s = 0;
    for(int i = x; i > 0; i -= i & -i)
        for(int j = y; j > 0; j -= j & -j)
            s += bit[i][j];
    return s;
}
ll sum(int x1,int y1,int x2,int y2){
    x1--, y1--;
    ll s = sum(x2, y2) - sum(x2, y1) - sum(x1, y2) + sum(x1, y1);
    return s;
}
bitset<N> cur, q[N];
ll res[N];
pair<pii,pii> query[N];
vector<pair<pii,int>> garlands[N];
string t;
signed main(){
	fio;
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int len, x, y, w;
        cin >> len;
        while(len--){
            cin >> x >> y >> w;
            garlands[i].pb({{x, y}, w});
        }
    }
    int qq, c = 0;
    cin >> qq;
    cur.set();
    while(qq--){
        cin >> t;
        if(t[0] == 'S'){
            int idx;
            cin >> idx;
            cur[idx].flip();
        }
        else{
            q[++c] = cur;
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            query[c] = {{x1, y1}, {x2, y2}};
        }
    }
    for(int i = 1; i <= k; i++){
        for(auto it: garlands[i]){
            update(it.fi.fi, it.fi.se, it.se);
        }
        for(int j = 1; j <= c; j++){
            auto &it = query[j];
            if(q[j][i])
                res[j] += sum(it.fi.fi, it.fi.se, it.se.fi, it.se.se);
        }
        for(auto it: garlands[i]){
            update(it.fi.fi, it.fi.se, -it.se);
        }
    }
    for(int i = 1; i <= c; i++){
        cout << res[i] << endl;
    }
}