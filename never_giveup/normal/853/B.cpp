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

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 100;

int n, m, k;

pair<int, pair<pair<int, int>, int> > q[maxn];

ll ans[maxw][2];

ll g[maxn];

int cnt;

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
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        cin >> q[i].first >> q[i].second.first.first >> q[i].second.first.second >> q[i].second.second;
    sort(q, q + m);
    int it;
    cnt = n;
    for (int i = 1; i <= n; i++)
        g[i] = inf;
    it = 0;
    ll now = inf * (ll)n;
    for (int i = 0; i < maxw; i++){
        while (it < m && q[it].first <= i){
            int v = q[it].second.first.first, u = q[it].second.first.second;
            ll w = q[it].second.second;
            if (u == 0){
                if (g[v] == inf)
                    cnt--;
                now -= g[v];
                g[v] = min(g[v], w);
                now += g[v];
            }
            it++;
        }
        if (cnt == 0)
            ans[i][0] = now;
        else
            ans[i][0] = -1;
    }
    cnt = n;
    for (int i = 1; i <= n; i++)
        g[i] = inf;
    it = m - 1;
    now = inf * (ll)n;
    for (int i = maxw - 1; i >= 0; i--){
        while (it >= 0 && q[it].first >= i){
            int v = q[it].second.first.first, u = q[it].second.first.second;
            ll w = q[it].second.second;
            if (v == 0){
                if (g[u] == inf)
                    cnt--;
                now -= g[u];
                g[u] = min(g[u], w);
                now += g[u];
            }
            it--;
        }
        if (cnt == 0)
            ans[i][1] = now;
        else
            ans[i][1] = -1;
    }
    ll answer = llinf;
    for (int i = 0; i + k + 1 < maxw; i++)
        if (ans[i][0] != -1 && ans[i + k + 1][1] != -1)
            answer = min(answer, ans[i][0] + ans[i + k + 1][1]);
    if (answer == llinf)
        cout << -1;
    else
        cout << answer;
}