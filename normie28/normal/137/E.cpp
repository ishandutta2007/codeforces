
// Problem : E. Last Chance
// Contest : Codeforces - Codeforces Beta Round #98 (Div. 2)
// URL : https://codeforces.com/problemset/problem/137/E
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
#define lsb(x) ((x) & -(x))
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
int aib[2000010];
int NMAX = 2000000;
 
void update(int x, int poz) {
    while (x <= NMAX) {
        aib[x] = min(aib[x], poz);
        x += lsb(x);
    }
}
int query(int x) {
    int ans(1e9);
    while (x) {
        ans = min(ans, aib[x]);
        x -= lsb(x);
    }
    return ans;
}
 
int main()
{
	fio;
    string s;
    cin >> s;
 
    memset(aib, 0x3333, sizeof aib);
    int lmax(-1), nr(-1);
    int sp(0), act(1);
 
    update(NMAX / 2, 0);
 
    for (auto i : s) {
        if (strchr("aeiouAEIOU", i) == 0)
            sp += 2;
        else
            sp--;
        int q = query(sp + NMAX / 2);
        if (q < act) {
            if (act - q == lmax)
                nr++;
            else if (act - q > lmax)
                lmax = act - q, nr = 1;
        }
 
        update(sp + NMAX / 2, act);
        act++;
    }
 
    if (lmax == -1)
        cout << "No solution\n";
    else
        cout << lmax << ' ' << nr << endl;
}