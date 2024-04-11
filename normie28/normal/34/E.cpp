
// Problem : E. Collisions
// Contest : Codeforces - Codeforces Beta Round #34 (Div. 2)
// URL : https://codeforces.com/problemset/problem/34/E
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
using namespace __gnu_cxx;
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
 
#define endl '\n'
 
typedef long double dbl;
 
const dbl oo = DBL_MAX;
const dbl EPS = 1E-9;
 
dbl getime(dbl x1, dbl v1, dbl x2, dbl v2)
{
    if(abs(v1 - v2) < EPS) return oo;
 
    return (x1 - x2) / (v2 - v1);
}
 
int main()
{
	fio;
    int n, t;
    cin >> n >> t;
 
    vector<dbl> x(n), v(n), m(n);
 
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> v[i] >> m[i];
 
    for(dbl tx = 0; tx+EPS < t; )
    {
        dbl tmp = t-tx;
 
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
            {
                dbl cur = getime(x[i], v[i], x[j], v[j]);
 
                if(cur < EPS) continue;
 
                tmp = min(tmp, cur);
            }
 
        for(int i = 0; i < n; ++i)
            x[i] = x[i] + v[i] * tmp;
 
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < i; ++j)
                if(abs(x[i] - x[j]) < EPS)
                {
                    dbl v1 = ((m[i] - m[j]) * v[i] + 2.0 * m[j] * v[j]) / (m[i] + m[j]);
                    dbl v2 = ((m[j] - m[i]) * v[j] + 2.0 * m[i] * v[i]) / (m[i] + m[j]);
                    v[i] = v1; v[j] = v2;
                }
 
        tx += tmp;
    }
 
    for(int i = 0; i < n; ++i)
        cout << fixed << setprecision(9) << x[i] << endl;
}