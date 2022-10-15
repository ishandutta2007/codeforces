
// Problem : C. Knights
// Contest : Codeforces - Codeforces Round #518 (Div. 1) [Thanks, Mail.Ru!]
// URL : https://codeforces.com/contest/1067/problem/C
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
#define dx 2
#define dy 2
//---------END-------//

const int N = 2e5 + 5;
int n;
vector< pair<int , int> > e[N];
int X[N] , Y[N] , W[N] , S[N] , dep[N] , t[N];
 
ll tot[N];
set< pair<int , int> > H[N];
 
ll c[N];
void add(int x , int w) {
    for (int i = x ; i <= n ; i += i & -i) {
        c[i] += w;
    }
}
ll get(int x) {
    ll res = 0;
    while (x > 0) {
        res += c[x];
        x &= x - 1;
    }
    return res;
}
 
int ncnt , L[N] , R[N];
void dfs(int x) {
    L[x] = ++ ncnt;
    for (auto &it : e[x]) {
        int y = it.first;
        int z = it.second;
        dep[y] = dep[x] + 1;
        t[y] = z;
        dfs(y);
        tot[x] += tot[y];
        if (H[x].size() < H[y].size()) {
            H[x].swap(H[y]);
        }
        H[x].insert(H[y].begin() , H[y].end());
        set< pair<int , int> > T;
        T.swap(H[y]);
    }
    R[x] = ncnt;
 
 
    if (x == 1) return;
    while (tot[x] > S[t[x]]) {
        if (H[x].empty()) {
            puts("-1");
            exit(0);
        }
        auto it = *H[x].rbegin();
        H[x].erase(it); int y = it.second;
        int delta = min(tot[x] - S[t[x]] , min(W[t[y]] - 1ll , S[t[y]] - get(R[y]) + get(L[y])));
        if (delta == 0) continue;
        tot[x] -= delta;
        W[t[y]] -= delta;
        add(L[y] , -delta);
        S[t[y]] -= delta;
        if (W[t[y]] > 1) {
            H[x].insert({dep[y] , y});
        }
    }
    if (W[t[x]] > 1) {
        H[x].insert({dep[x] , x});
    }
    add(L[x] , W[t[x]]);
    tot[x] += W[t[x]];
}
 
int main() {
    fio;
    cin>>n;
    for (int i = 1 ; i < n ; ++ i) {
       cin>>X[i]>>Y[i]>>W[i]>>S[i];
        e[X[i]].push_back({Y[i] , i});
    }
    dfs(1);
    cout<<n<<endl;
    for (int i = 1 ; i < n ; ++ i) {
        cout<<X[i]<<' '<<Y[i]<<' '<<W[i]<<' '<<S[i]<<endl;
    }
}