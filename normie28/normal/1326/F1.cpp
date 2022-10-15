// Problem: C. Tournament
// Contest: Codeforces - Codeforces Round #443 (Div. 1)
// URL: https://codeforces.com/problemset/problem/878/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	Normie's Template v2.1
	Changes:
	Added vectorization optimizations.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}

template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;

//---------END-------//
typedef long long ll;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 20;
 
string a[N];
int d1[14][64], d2[14][64];
ll ans[10005];
int main() {
    fio;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) cin>>a[i];
    int m = n / 2, g = n - m;
    for (int s = (1 << m) - 1; s < 1 << n;) {
        vector<int> b, c;
        for (int i = 0; i < n; i++) {
            if (s >> i & 1)
                b.push_back(i);
            else
                c.push_back(i);
        }
        memset(d1, 0, sizeof d1);
        memset(d2, 0, sizeof d2);
        while (1) {
            int id = 0;
            for (int i = 0; i + 1 < b.size(); i++) {
                id *= 2;
                if (a[b[i]][b[i + 1]] == '1') id++;
            }
            d1[b.back()][id]++;
            if (!next_permutation(b.begin(), b.end())) break;
        }
        while (1) {
            int id = 0;
            for (int i = 0; i + 1 < c.size(); i++) {
                id *= 2;
                if (a[c[i]][c[i+ 1]] == '1') id++;
            }
            d2[c[0]][id]++;
            if (!next_permutation(c.begin(), c.end())) break;
        }
        for (auto t1 : b) {
            for (auto t2 : c) {
                for (int i = 0; i < 1 << m - 1; i++) {
                    for (int j = 0; j < 1 << g - 1; j++) {
                        int id = ((i * 2 + (a[t1][t2] == '1')) << (g - 1) )+ j;
                        ans[id] += (ll)d1[t1][i] * d2[t2][j];
                    }
                }
            }
        }
        int x = s & -s;
        int y = s + x;
        s = ((s & ~y) / x >> 1) | y;
    }
 
    for (int i = 0; i < 1 << n - 1; i++) {
        printf("%lld%c", ans[i], " \n"[i == (1 << n - 1) - 1]);
    }
}