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

int parent[maxn];

int q[maxn];

int r[maxn];

int dsu_get(int x){
    return x == parent[x] ? x : parent[x] = dsu_get(parent[x]);
}

void dsu_unite(int x, int y){
    x = dsu_get(x);
    y = dsu_get(y);
    if (r[x] < r[y])
        swap(x, y);
    parent[y] = x;
    if (r[x] == r[y])
        r[x]++;
    q[x] += q[y];
    q[x]--;
}

pair<int, pair<int, int> > w[maxn];

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
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = i, q[i] = 1;
    for (int i = 0; i < m; i++){
        cin >> w[i].second.first >> w[i].second.second >> w[i].first;
        w[i].second.first--;
        w[i].second.second--;
    }
    sort(w, w + m);
    reverse(w, w + m);
    int answer = 0;
    for (int i = 0; i < m; i++){
        int x = w[i].second.first, y = w[i].second.second;
        x = dsu_get(x);
        y = dsu_get(y);
        if (q[x] > 0 || q[y] > 0){
            answer += w[i].first;
            if (x != y)
                dsu_unite(x, y);
            else
                q[x]--;
        }
    }
    cout << answer;
}