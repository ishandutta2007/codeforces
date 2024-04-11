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
//#include "boxes.h"
//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;

typedef long long ll;

typedef long double ld;

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MODR = 1e9 + 993;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MODR;
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

const int maxn = 2e5 + 100, inf = 1e9 + 100, sq = 300;

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
    int n;
    cin >> n;
    int x = 0, y = 1023;
    for (int i = 0; i < n; i++){
        char c;
        int v;
        cin >> c >> v;
        if (c == '|'){
            x |= v;
            y |= v;
        }
        else
        if (c == '&')
            x &= v,
            y &= v;
        else
            x ^= v,
            y ^= v;
    }
    cout << 3 << '\n';
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < 10; i++){
        int w = (x & (1 << i)), h = (y & (1 << i));
        if (w)
            w = 1;
        if (h)
            h = 1;
        if (w == 0 && h == 0)
            continue;
        else
        if (w == 0 && h == 1)
            a += (1 << i);
        else
        if (w == 1 && h == 0)
            a += (1 << i), c += (1 << i);
        else
        if (w == 1 && h == 1)
            a += (1 << i), b += (1 << i);
    }
    cout << "& " << a << '\n' << "| " << b << '\n' << "^ " << c << '\n';
}