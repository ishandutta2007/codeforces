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

using namespace std;

typedef long long ll;

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

matrix def;

matrix bpow(matrix a, ll st){
    if (st == 0)
        return def;
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

const ll llinf = 2e18;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 1e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int q[2 * maxn], add[2 * maxn];

int ans[51][maxn];

void build(int id, int v, int l, int r){
    q[v] = 0;
    add[v] = 0;
    if (l == r){
        q[v] = ans[id][l];
        return;
    }
    int m = (l + r) / 2;
    build(id, 2 * v, l, m);
    build(id, 2 * v + 1, m + 1, r);
}

void push(int v, int l, int r){
    if (add[v] == 0)
        return;
    q[v] += add[v];
    if (l != r)
        add[2 * v] += add[v], add[2 * v + 1] += add[v];
    add[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r){
        add[v] += val;
        push(v, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    update(2 * v, tl, m, l, min(r, m), val);
    update(2 * v + 1, m + 1, tr, max(l, m + 1), r, val);
    q[v] = max(q[2 * v], q[2 * v + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    push(v, tl, tr);
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return q[v];
    int m = (tl + tr) / 2;
    return max(get(2 * v, tl, m, l, min(r, m)), get(2 * v + 1, m + 1, tr, max(l, m + 1), r));
}

int n, k;

int a[maxn];

int last[maxn];

int prv[maxn];

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
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        last[i] = -1;
    for (int i = 0; i < n; i++){
        cin >> a[i], a[i]--;
        prv[i] = last[a[i]];
        last[a[i]] = i;
    }
    for (int its = 0; its < k; its++){
        build(its, 1, 0, n);
        for (int i = 0; i < n; i++){
            update(1, 0, n, prv[i] + 1, i, 1);
            ans[its + 1][i + 1] = get(1, 0, n, 0, i);
        }
    }
    cout << ans[k][n];
}