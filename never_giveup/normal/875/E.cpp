/*
----------------------------------------------
--------------------------------------------
----------------------------------------------
--------------------------------------------
----------------------------------------------

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
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;

typedef long long ll;

typedef long double ld;

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
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

ll bdiv(ll x, ll y){
    return (x * bpow(y, mod - 2)) % mod;
}

const ll llinf = 2e18 + 100;

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300;

pair<int, int> g[maxn];

int n;

int a[maxn];

int q[4 * maxn], u[4 * maxn];

void build(int v, int l, int r){
    q[v] = 0;
    u[v] = 0;
    if (l == r)
        return;
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
}

void push(int v, int l, int r){
    if (u[v] == 0)
        return;
    u[v] = 0;
    q[v] = 0;
    if (l == r)
        return;
    u[2 * v] = 1;
    u[2 * v + 1] = 1;
}

void update(int v, int l, int r, int id, int val){
    push(v, l, r);
    if (l == r){
        q[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (id <= m)
        update(2 * v, l, m, id, val);
    else
        update(2 * v + 1, m + 1, r, id, val);
    push(2 * v, l, m);
    push(2 * v + 1, m + 1, r);
    q[v] = q[2 * v] + q[2 * v + 1];
}

void updates(int v, int tl, int tr, int l, int r){
    push(v, tl, tr);
    if (l > r)
        return;
    if (tl == l && tr == r){
        u[v] = 1;
        push(v, tl, tr);
        return;
    }
    int m = (tl + tr) / 2;
    updates(2 * v, tl, m, l, min(r, m));
    updates(2 * v + 1, m + 1, tr, max(l, m + 1), r);
    q[v] = q[2 * v] + q[2 * v + 1];
}

int s1, s2;

int pos[maxn];

int o[maxn], z[maxn];

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
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s1 >> s2;
    n += 2;
    g[0] = make_pair(s1, 0);
    g[1] = make_pair(s2, 1);
    for (int i = 2; i < n; i++)
        cin >> a[i], g[i] = make_pair(a[i], i);
    sort(g, g + n);
    for (int i = 0; i < n; i++)
        pos[g[i].second] = i;
    int l = abs(s2 - s1) - 1, r = 1e9;
    while (r - l > 1){
        int k = (l + r) / 2;
        build(1, 0, n - 1);
        update(1, 0, n - 1, pos[0], 1);
        int last = 0;
        for (int i = 0; i < n; i++){
            while (g[i].first - g[last].first > k)
                last++;
            o[i] = last;
        }
        last = n - 1;
        for (int i = n - 1; i >= 0; i--){
            while (g[last].first - g[i].first > k)
                last--;
            z[i] = last;
        }
        for (int i = 2; i < n; i++){
            int ans = q[1];
            updates(1, 0, n - 1, 0, o[pos[i]] - 1);
            updates(1, 0, n - 1, z[pos[i]] + 1, n - 1);
            if (ans && abs(g[pos[i]].first - g[pos[i - 1]].first) <= k)
                update(1, 0, n - 1, pos[i - 1], 1);
        }
        if (q[1])
            r = k;
        else
            l = k;
    }
    cout << r;
}