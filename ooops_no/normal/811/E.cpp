#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>
#include<cassert>
#include <iomanip>

using namespace std;

#pragma GCC target("avx,avx2,sse3,ssse3,sse4.1,sse4.2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("O3")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")

#define pb push_back
#define ld long double

mt19937 rnd(51);

const int N = 2e5 + 10;
const int con = 20;

int n, m;
int a[11][N];
int par[N];
int mark[N];
int h[N];

struct node
{
    int ans = 0;
    vector<int> l, r, ll, rr;

    void make(int v)
    {
        l.resize(n), r.resize(n), rr.resize(n), ll.resize(n);
        ans = n;
        for (int i = 0; i < n; i++){
            l[i] = r[i] = a[i + 1][v];
        }
    };

    void makee()
    {
        ans = 0;
    };

}t[2 * N], kek, lol;

int find_set(int v){
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

void union_set(int a, int b, int &cnt){
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        par[a] = b;
        cnt--;
    }
}

node unionn(node x,node y)
{
    if (x.ans == 0) return y;
    if (y.ans == 0) return x;
    int xx, yy, i;
    kek.ans = x.ans + y.ans;
    for (i = 0; i < n; ++i){
        kek.l[i] = x.l[i];
        kek.r[i] = y.r[i];
    }
    for (i = 0; i < 41; ++i){
        par[i] = i;
        mark[i] = 0;
    }
    for (i = 0; i < n; ++i){
        if (x.r[i] == y.l[i]){
            union_set(x.rr[i], y.ll[i] + con, kek.ans);
        }
    }
    int cnt = 1;
    for (i = 0; i < n; ++i){
        xx = find_set(x.ll[i]), yy = find_set(y.rr[i] + con);
        if (!mark[xx]){
            mark[xx] = cnt++;
        }
        if (!mark[yy]){
            mark[yy] = cnt++;
        }
        kek.ll[i] = mark[xx];
        kek.rr[i] = mark[yy];
    }
    return kek;
}

void build(int v, int l, int r){
    int i;
    t[v].make(l);
    if (l == r){
        for (i = 0; i < 41; ++i) par[i] = i;
        for (i = 1; i < n; ++i) if (t[v].l[i] == t[v].l[i - 1]) union_set(i, i - 1, t[v].ans);
        for (i = 0; i < n; ++i){
            t[v].ll[i] = t[v].rr[i] = find_set(i);
        }
    }
    else{
        int m = (l + r) / 2;
        build(2 * v, l, m), build(2 * v + 1, m + 1, r);
        t[v] = unionn(t[v * 2], t[v * 2 + 1]);
    }
}

node get(int v,int tl,int tr,int l,int r)
{
    if (l > r){
        return lol;
    }
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return unionn(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q, i, j, l, r;
    cin >> n >> m >> q;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    kek.make(0);
    lol.make(0);
    lol.makee();
    build(1, 1, m);
    while(q--)
    {
        cin >> l >> r;
        cout << get(1, 1, m, l, r).ans << "\n";
    }
    return 0;
}