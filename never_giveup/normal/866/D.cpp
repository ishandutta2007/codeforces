/*

         o###########oo
      o##"          ""##o
    o#"                "##
  o#"                    "#o
 #"  ##              ##   "##
#"                          ##
#  ###################       #
#                            #
#                            #
#                            #
#                            #
#                            #
#                            #
#o                           #
"#o                         ##
 "#o                       ##
  "#o                    o#"
   "#o                  ##
     "#o              o#"
       "#ooo      ooo#######oo
        ###############   "######o
     o###""        "###o      # ###
   o###o     oooo    ###    oo####"
 o###**#     #**#   ############"
 ""##""""""""""###########    #
    # oooooooo#"#**     ##    #
    # #       # # **    ##    #
    #o#       #o#  *****###ooo#
                        ##
                        ##   o###o
                        ## o##***##
               o########## #***#**##o
             o##"   ""###  #***##***#
 o#######o  ###   oo####   ##**####*#
o##"  ""#############""     ##****###
##"         ##              ##*##*###
##          ###              ##### ##
##           ###              # ##  #
##            ##                 #
##             ##
##             ###
##              ###oo
###              ""###
 ###
  ###
*/
#include <bits/stdc++.h>
#define mkp make_pair
//#define f first
//#define s second

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef long double ld;

typedef vector<vector<ll> > matrix;

matrix mul(matrix a, matrix b){
    matrix c;
    c.resize(a.size());
    for (int i = 0; i < c.size(); i++)
        c[i].resize(b[0].size(), 0);
    for (int i = 0; i < c.size(); i++)
        for (int j = 0; j < c[i].size(); j++)
            for (int k = 0; k < b.size(); k++)
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
    return c;
}

matrix Def;

matrix bpow(matrix a, ll st){
    if (st == 0)
        return Def;
    if (st == 1)
        return a;
    matrix b = bpow(a, st >> 1);
    b = mul(b, b);
    if (st & 1)
        b = mul(a, b);
    return b;
}

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

ll sqr(ll x){
    return x * x;
}

const int mod = 1e9 + 7;

ll bpow(ll x, ll y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    ll ret = bpow(x, y >> 1);
    ret = (ret * ret) % mod;
    if (y & 1)
        ret = (ret * x) % mod;
    return ret;
}

const ll llinf = 2e18 + 100;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 3e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, sq = 6000, osq = 17;

int n;

int a[maxn];

pair<int, int> g[maxn];

ll answer;

struct tree{
    int u, v;
};

tree t[4 * maxn];

void push(int v, int l, int r){
    if (t[v].u == 0)
        return;
    t[v].v += t[v].u;
    if (l != r){
        t[2 * v].u += t[v].u;
        t[2 * v + 1].u += t[v].u;
    }
    t[v].u = 0;
}

void build(int v, int l, int r){
    t[v].u = 0;
    if (l == r){
        t[v].v = n - l;
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    t[v].v = min(t[2 * v].v, t[2 * v + 1].v);
}

void update(int v, int tl, int tr, int l, int r, int val){
    push(v, l, r);
    if (l > r)
        return;
    if (tl == l && tr == r){
        t[v].u += val;
        push(v, l, r);
        return;
    }
    int m = (tl + tr) / 2;
    update(2 * v, tl, m, l, min(r, m), val);
    update(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
    t[v].v = min(t[2 * v].v, t[2 * v + 1].v);
}

int get(int v, int tl, int tr, int l, int r){
    push(v, tl, tr);
    if (l > r)
        return inf;
    if (tl == l && tr == r)
        return t[v].v;
    int m = (tl + tr) / 2;
    return min(get(2 * v, tl, m, l, min(r, m)), get(2 * v + 1, m + 1, tr, max(l, m + 1), r));
}

bool vis[maxn];

int p[maxn];

int main()
{
    #ifdef ONPC
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        g[i] = make_pair(a[i], i);
    }
    sort(g, g + n);
    build(1, 0, n - 1);
    for (int i = 0; i < n; i++){
        int id = g[i].second;
        if (id == n - 1 || get(1, 0, n - 1, 0, id) < 2 || get(1, 0, n - 1, id + 1, id + 1) < 1){
            if (get(1, 0, n - 1, 0, id) > 0)
                update(1, 0, n - 1, 0, id, -1);
            continue;
        }
        update(1, 0, n - 1, 0, id, -2);
        update(1, 0, n - 1, id + 1, id + 1, -1);
        answer -= a[id];
        vis[id] = 1;
        p[id + 1] = 1;
    }
    multiset<int> q;
    for (int i = n - 1; i >= 0; i--){
        if (!vis[i])
            q.insert(-a[i]);
        if (p[i]){
            answer -= *q.begin();
            q.erase(q.begin());
        }
    }
    cout << answer;
}