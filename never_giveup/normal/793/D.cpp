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

void setmax(int &x, int y){
    x = max(x, y);
}

void setmin(int &x, int y){
    x = max(x, y);
}

void setmax(ll &x, ll y){
    x = max(x, y);
}

void setmin(ll &x, ll y){
    x = max(x, y);
}

ll AR = 19, BR = 13, CR = 23, XR = 228, YR = 322, MOD = 1e9 + 993;

const int mod = 1e9 + 7;

ll myrand(){
    ll ZR = (XR * AR + YR * BR + CR) % MOD;
    XR = YR;
    YR = ZR;
    return ZR;
}

string prm(string s){
    string t;
    for (int i = 1; i < s.length(); i++)
        t.push_back(s[i]);
    t.push_back(s[0]);
    return t;
}

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

int md(int x){
    if (x >= mod)
        x -= mod;
    if (x < 0)
        x += mod;
    return x;
}

ll MD(ll x){
    x %= MOD;
    if (x < 0)
        x += MOD;
    return x;
}

ll sqr(ll x){
    return x * x;
}

const ll llinf = 1e18;

const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 300;

int n, k, eds;

int q[100][100][100][2];

int d[100][100];

int main()
{
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    //freopen("trap.in", "r", stdin);
    //freopen("trap.out", "w", stdout);
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> k >> eds;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            d[i][j] = inf;
    for (int i = 0; i < eds; i++){
        int v, u, w;
        cin >> v >> u >> w;
        d[v - 1][u - 1] = min(d[v - 1][u - 1], w);
    }
    for (int s = 0; s <= k; s++)
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                q[s][i][j][0] = inf, q[s][i][j][1] = inf;
    for (int i = 0; i < n; i++){
        q[1][0][i + 1][1] = 0;
        q[1][i + 1][n + 1][0] = 0;
    }
    for (int s = 1; s < k; s++)
        for (int i = 0; i <= n; i++)
            for (int j = i + 1; j <= n + 1; j++)
                for (int t = 0; t < 2; t++)
                if (q[s][i][j][t] != inf){
                    int now;
                    if (t == 0)
                        now = i - 1;
                    else
                        now = j - 1;
                    for (int w = i; w < j - 1; w++)
                        if (d[now][w] != inf)
                            q[s + 1][i][w + 1][1] = min(q[s + 1][i][w + 1][1], q[s][i][j][t] + d[now][w]),
                            q[s + 1][w + 1][j][0] = min(q[s + 1][w + 1][j][0], q[s][i][j][t] + d[now][w]);
                }
    int answer = inf;
    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n + 1; j++)
            for (int t = 0; t < 2; t++)
                answer = min(answer, q[k][i][j][t]);
    if (answer == inf)
        answer = -1;
    cout << answer;
}