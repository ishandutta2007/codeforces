
// Problem : D. Unambiguous Arithmetic Expression
// Contest : Codeforces - Codeforces Beta Round #87 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/115/D
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
int n, r;
vector<pair<int, int>> a, b;
int dp[100][60001];
int res = 0;
 
int main() {
    fio;
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        int r, c; cin >> r >> c;
        if (c >= 0) a.push_back({r, c});
        else b.push_back({r, c});
    }
 
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); ++i) {
        if (a[i].first > r) break;
        res++;
        r += a[i].second;
    }
 
    sort(b.begin(), b.end(), [](pair<int, int> &x, pair<int, int> &y) {
        return x.first + x.second < y.first + y.second;
    });
    for (int i = 0; i < b.size(); ++i) for (int j = 0; j <= r; ++j) {
        dp[i][j] = i > 0 ? dp[i-1][j] : 0;
        if (b[i].second + j >= 0 && b[i].first <= j)
            dp[i][j] = max(dp[i][j], (i > 0 ? dp[i-1][j+b[i].second] : 0) + 1);
    }
 
    cout << res + (b.size() == 0 ? 0 : dp[b.size()-1][r]) << "\n";
}