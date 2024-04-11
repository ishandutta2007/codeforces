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

int n, m;

int q[maxn];

vector<int> g[maxn];

int same[maxn];

vector<pair<int, int> > pos[maxn];

void no(){
    cout << "No";
    exit(0);
}

void go(int id, int val){
    if (q[id] != 0 && q[id] != val)
        no();
    if (q[id] != 0)
        return;
    q[id] = val;
    if (val == 1){
        for (int it = 0; it < pos[id].size(); it++){
            int x = pos[id][it].first, y = pos[id][it].second;
            for (int i = x - 1; i >= 0 && g[i].size() > y && same[i] >= y && q[g[i][y]] != 1; i--)
                if (q[g[i][y]] == 2)
                    no();
                else
                    go(g[i][y], 1);
        }
    }
    else{
        for (int it = pos[id].size() - 1; it >= 0; it--){
            int x = pos[id][it].first, y = pos[id][it].second;
            for (int i = x + 1; i < n && g[i].size() > y && same[i - 1] >= y && q[g[i][y]] != 2; i++)
                if (q[g[i][y]] == 1)
                    no();
                else
                    go(g[i][y], 2);
        }
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
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        int len;
        cin >> len;
        g[i].resize(len);
        for (int j = 0; j < len; j++){
            int x;
            cin >> x;
            g[i][j] = x - 1;
            pos[x - 1].push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < n - 1; i++){
        while (same[i] < min(g[i].size(), g[i + 1].size()) && g[i][same[i]] == g[i + 1][same[i]])
            same[i]++;
        if (g[i].size() > g[i + 1].size() && same[i] == g[i + 1].size())
            no();
    }
    for (int i = 0; i < n - 1; i++){
        if (same[i] < min(g[i].size(), g[i + 1].size()) && g[i + 1][same[i]] < g[i][same[i]])
            go(g[i + 1][same[i]], 2),
            go(g[i][same[i]], 1);
    }
    vector<int> answer;
    cout << "Yes\n";
    for (int i = 0; i < m; i++)
        if (q[i] == 1)
            answer.push_back(i + 1);
    cout << answer.size() << '\n';
    for (auto i : answer)
        cout << i << ' ';
}