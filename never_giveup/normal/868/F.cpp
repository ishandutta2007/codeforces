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

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, sq = 6000, osq = 17;

int n, a[maxn];

ll d[maxn], newd[maxn];

ll value;

int mas[maxn];

void add(int x, int y){
    value -= mas[x] * (ll)(mas[x] - 1) / 2;
    mas[x] += y;
    value += mas[x] * (ll)(mas[x] - 1) / 2;
}

void fun(int l, int r, int optl, int optr){
    int m = (l + r) / 2;
    newd[m] = llinf;
    int optm;
    for (int i = optl; i <= min(optr, m - 1); i++){
        add(a[i], -1);
        if (d[i] + value < newd[m]){
            newd[m] = d[i] + value;
            optm = i;
        }
    }
    for (int i = optl; i <= min(optr, m - 1); i++)
        add(a[i], 1);
    int newm;
    if (l < m){
        newm = (l + m - 1) / 2;
        for (int i = newm + 1; i <= m; i++)
            add(a[i], -1);
        fun(l, m - 1, optl, optm);
        for (int i = newm + 1; i <= m; i++)
            add(a[i], 1);
    }
    if (m < r){
        newm = (m + 1 + r) / 2;
        for (int i = optl; i < optm; i++)
            add(a[i], -1);
        for (int i = m + 1; i <= newm; i++)
            add(a[i], 1);
        fun(m + 1, r, optm, optr);
        for (int i = optl; i < optm; i++)
            add(a[i], 1);
        for (int i = m + 1; i <= newm; i++)
            add(a[i], -1);

    }
}

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
    int k;
    /*n = 1e5;
    k = 20;
    cout << n << ' ' << k << '\n';
    for (int i = 0; i < n; i++)
        cout << 1 << ' ';
    return 0;
    */cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i]--, add(a[i], 1), d[i] = value;
    int m = (1 + n) / 2;
    for (int i = m + 1; i <= n; i++)
        add(a[i], -1);
    add(a[0], 1);
    for (int it = 1; it < k; it++){
        fun(1, n, 0, n);
        for (int i = 1; i <= n; i++)
            d[i] = newd[i];
    }
    cout << d[n];
}