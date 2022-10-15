
// Problem : F. Sonya and Bitwise OR
// Contest : Codeforces - Codeforces Round #495 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1004/F
// Memory Limit : 512 MB
// Time Limit : 4000 ms
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
#define tree treee
//---------END-------//
const int MAXN = 100005;
const int MAXT = 4 * MAXN;
 
static int N, M, X, A[MAXN];
static struct tNode
{
    long long sum;
    vector<pair<int, int>> pre, suf;
} tree[MAXT];
 
#define lson (n << 1)
#define rson (lson | 1)
#define lm ((l + r) >> 1)
#define rm (lm + 1)
 
inline tNode update(const tNode &x, const tNode &y)
{
    if (!x.pre.size())
        return y;
    if (!y.pre.size())
        return x;
    tNode res = {x.sum + y.sum, x.pre, y.suf};
    for (auto &i : x.suf)
        for (auto &j : y.pre)
            if ((i.first | j.first) >= X)
                res.sum += 1ll * i.second * j.second;
    int l = x.pre.back().first, r = y.suf.back().first;
    for (auto &i : y.pre)
    {
        if ((i.first | l) == res.pre.back().first)
            res.pre.back().second += i.second;
        else
            res.pre.emplace_back(pair<int, int>{i.first | l, i.second});
    }
    for (auto &i : x.suf)
    {
        if ((i.first | r) == res.suf.back().first)
            res.suf.back().second += i.second;
        else
            res.suf.emplace_back(pair<int, int>{i.first | r, i.second});
    }
    return res;
}
 
void build(int n, int l, int r)
{
    tNode &tr = tree[n];
    if (l == r)
    {
        tr.sum = A[l] >= X;
        tr.pre.emplace_back(pair<int, int>{A[l], 1});
        tr.suf.emplace_back(pair<int, int>{A[l], 1});
        return ;
    }
    build(lson, l, lm);
    build(rson, rm, r);
    tr = update(tree[lson], tree[rson]);
}
 
void modify(int n, int l, int r, int p, int v)
{
    tNode &tr = tree[n];
    if (l == r)
    {
        tr.sum = v >= X;
        tr.pre.clear();
        tr.suf.clear();
        tr.pre.emplace_back(pair<int, int>{v, 1});
        tr.suf.emplace_back(pair<int, int>{v, 1});
        return ;
    }
    if (p <= lm)
        modify(lson, l, lm, p, v);
    else
        modify(rson, rm, r, p, v);
    tr = update(tree[lson], tree[rson]);
}
 
tNode query(int n, int l, int r, int fl, int fr)
{
    tNode &tr = tree[n];
    if (fl <= l && r <= fr)
        return tr;
    tNode res = {0, decltype(res.pre)(), decltype(res.suf)()};
    if (fl <= lm)
        res = update(res, query(lson, l, lm, fl, fr));
    if (fr >= rm)
        res = update(res, query(rson, rm, r, fl, fr));
    return res;
}
 
int main()
{
	fio;
	cin>>N>>M>>X;
    for (int i = 1; i <= N; i++) cin>>A[i];
    build(1, 1, N);
    while (M--)
    {
        int op, x, y;
        cin>>op>>x>>y;
        if (op == 1)
            modify(1, 1, N, x, y);
        else
            cout<<query(1, 1, N, x, y).sum<<endl;
    }
}