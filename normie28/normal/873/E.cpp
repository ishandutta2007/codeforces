
// Problem : E. Awards For Contestants
// Contest : Codeforces - Educational Codeforces Round 30
// URL : https://codeforces.com/problemset/problem/873/E
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
//---------END-------//
int n;
pii a[3002];
int c[3002];
pii tr[12009];
 
void upd(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        tr[v] = {val, pos};
        return;
    }
    int t = (l + r) / 2;
    if (pos <= t)
        upd(v + v, l, t, pos, val);
    else
        upd(v + v + 1, t + 1, r, pos, val);
    tr[v] = max(tr[v + v], tr[v + v + 1]);
}
 
pair<int, int> get(int v, int l, int r, int ql, int qr)
{
    if (qr < ql) return {-1, -1};
    if (ql == l && qr == r)
        return tr[v];
    int t = (l + r) / 2;
    auto g1 = get(v + v, l, t, ql, min(qr, t));
    auto g2 = get(v + v + 1, t + 1, r, max(t + 1, ql), qr);
    return max(g1, g2);
}
 
int get(int l, int r)
{
    r = min(r, n - 1);
    return l <= r ? get(1, 0, n - 1, l, r).se : -1;
}
 
int main()
{
	cin>>n;
    for (int i = 0; i < n; ++i)
    {
    	cin>>a[i].fi;
        a[i].se = i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; ++i)
        upd(1, 0, n - 1, i, i < n - 1 ? a[i].fi - a[i + 1].fi : a[i].fi);
    array<int, 3> sol = {{-1, -1, -1}};
    int x = 0, y = 0, z = 0;
    for (int i = 0; i < n; ++i)
    {
        int k1 = i + 1;
        for (int j = max(i + 1, i + (k1 + 1) / 2); j < n && j <= i + k1 * 2; ++j)
        {
            int k2 = j - i;
//            for (int k = max(j + 1, j + (max(k1, k2) + 1) / 2); k < n && k < j + min(k1, k2) * 2; ++k)
            int k = get(max(j + 1, j + (max(k1, k2) + 1) / 2), j + min(k1, k2) * 2);
            if (k == -1) continue;
            {
                array<int, 3> cur = {{a[i].fi - a[i + 1].fi, a[j].fi - a[j + 1].fi, k < n - 1 ? a[k].fi - a[k + 1].fi : a[k].fi}};
                if (cur > sol)
                {
                    sol = cur;
                    x = i, y = j, z = k;
                }
            }
        }
    }
    for (int i = 0; i <= x; ++i)
        c[a[i].se] = 1;
    for (int i = x + 1; i <= y; ++i)
        c[a[i].se] = 2;
    for (int i = y + 1; i <= z; ++i)
        c[a[i].se] = 3;
    for (int i = z + 1; i < n; ++i)
        c[a[i].se] = -1;
    for (int i = 0; i < n; ++i)
    cout<<c[i]<<' ';
}