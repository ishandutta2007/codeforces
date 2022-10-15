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
#define FILE_IN "dragon.inp"
#define FILE_OUT "dragon.out"
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
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//-------------------//
struct cmp
{
	int operator()(piii a, piii b)
	{
		return (a.p1>b.p1);
	}
};
//---------END-------//
const int N = (int)2e5 + 50;
 
struct query {
    int r, id;
};
 
int n, q;
int p[N], l[N];
vector<query> qry[N];
ll res[N];
 
struct BIT {
    ll bit[N];
 
    void add(int x, ll val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }
 
    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }
} bit;
 
stack<int> S;
 
int main() {
    fio;
 
    cin >> n;
    for(int i = 0; i < n; i++) cin >> p[i] >> l[i];
    cin >> q;
    for(int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--, b--;
        qry[a].push_back({b, i});
    }
 
    for(int i = n - 1; i >= 0; i--) {
        while(!S.empty() && p[i] + l[i] >= p[S.top()] + l[S.top()]) {
            int v = S.top(); S.pop();
            if(!S.empty() && p[v] + l[v] < p[S.top()]) {
                bit.add(S.top(), -(p[S.top()] - p[v] - l[v]));
            }
        }
        if(!S.empty() && p[i] + l[i] < p[S.top()]) {
            bit.add(S.top(), p[S.top()] - p[i] - l[i]);
        }
        S.push(i);
        for(const auto &qr : qry[i]) {
            res[qr.id] = bit.get(qr.r);
        }
    }
    for(int i = 0; i < q; i++) {
        cout << res[i] << "\n";
    }
}