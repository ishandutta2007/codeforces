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

const ll llinf = 2e18;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 2e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 100;

int q[maxn][5];

int n;

bool check(int x, int v, int u){
    int ret = 0;
    for (int i = 0; i < 5; i++)
        ret += (q[v][i] - q[x][i]) * (q[u][i] - q[x][i]);
    return ret <= 0;
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
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 5; j++)
            cin >> q[i][j];
    }
    for (int i = 0; i < 5; i++)
        q[n][i] = q[0][i];
    for (int i = 0; i < 5; i++)
        q[n + 1][i] = q[1][i];
    if (n < 3){
        cout << n << '\n';
        for (int i = 0; i < n; i++)
            cout << i + 1 << ' ';
        return 0;
    }
    int good = 0;
    for (int i = 1; i < n; i += 2){
        int v = i, u = i + 1;
        int nw = good;
        if (check(v, u, good))
            nw = v;
        if (check(u, v, good))
            nw = u;
        good = nw;
    }
    if (good >= n)
        good -= n;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (i != good && j != good)
        if (!check(good, i, j)){
            good = -1;
            break;
        }
    if (good == -1)
        cout << 0;
    else
        cout << 1 << '\n' << good + 1;
}