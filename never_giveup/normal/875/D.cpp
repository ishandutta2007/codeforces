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

const int maxn = 2e5 + 100, inf = 1e9 + 100, sq = 300;

int n;

int a[maxn];

int pos[30];

pair<int, int> q[maxn];

pair<int, int> p[maxn];

void prec(){
    for (int i = 0; i < 30; i++)
        pos[i] = -1;
    for (int i = 0; i < n; i++){
        q[i].first = -1;
        for (int j = 0; j < 30; j++)
            if ((a[i] & (1 << j)) == 0)
                q[i].first = max(q[i].first, pos[j]);
            else
                pos[j] = i;
    }
    for (int i = 0; i < 30; i++)
        pos[i] = n;
    for (int i = n - 1; i >= 0; i--){
        q[i].second = n;
        for (int j = 0; j < 30; j++)
            if ((a[i] & (1 << j)) == 0)
                q[i].second = min(q[i].second, pos[j]);
            else
                pos[j] = i;
    }
    stack<int> g;
    for (int i = 0; i < n; i++){
        while (!g.empty() && a[g.top()] < a[i])
            g.pop();
        if (g.empty())
            p[i].first = -1;
        else
            p[i].first = g.top();
        g.push(i);
    }
    while (!g.empty())
        g.pop();
    for (int i = n - 1; i >= 0; i--){
        while (!g.empty() && a[g.top()] <= a[i])
            g.pop();
        if (g.empty())
            p[i].second = n;
        else
            p[i].second = g.top();
        g.push(i);
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
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    prec();
    ll answer = 0;
    for (int i = 0; i < n; i++){
        int L = p[i].first + 1, R = p[i].second - 1;
        int l = q[i].first, r = q[i].second;
        answer += max(0, l - L + 1) * (ll)(R - i + 1) + max(0, R - r + 1) * (ll)(i - L + 1) - max(0, l - L + 1) * (ll)max(0, R - r + 1);
    }
    cout << answer;
}