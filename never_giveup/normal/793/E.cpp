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

const ll llinf = 2e18;

const ld EPS = 1e-6;

const int maxn = 5e3 + 100, inf = 1e9 + 100, sq = 300;

int n;

vector<int> e[maxn];

vector<int> q[maxn];

int a, b, c, d;

int sz[maxn];

int rt[maxn];

bitset<maxn> g[2];

int dfs(int v){
    if (e[v].empty())
        sz[v] = 1;
    if (v == a){
        rt[v] = 1;
        return 1;
    }
    if (v == b){
        rt[v] = 2;
        return 2;
    }
    if (v == c){
        rt[v] = 3;
        return 3;
    }
    if (v == d){
        rt[v] = 4;
        return 4;
    }
    int ret = 0;
    for (int i = 0; i < e[v].size(); i++)
        q[v][i] = dfs(e[v][i]), sz[v] += sz[e[v][i]], ret = max(ret, q[v][i]);
    rt[v] = ret;
    if (v == 0)
        return ret;
    if (ret == 1){
        for (int i = 0; i < q[v].size(); i++)
            if (q[v][i] == 0)
                g[0] |= g[0] << sz[e[v][i]];
    }
    if (ret == 3){
        for (int i = 0; i < q[v].size(); i++)
            if (q[v][i] == 0)
                g[0] |= g[0] << sz[e[v][i]];
    }
    if (ret == 2){
        for (int i = 0; i < q[v].size(); i++)
            if (q[v][i] == 0)
                g[1] |= g[1] << sz[e[v][i]];
    }
    if (ret == 4){
        for (int i = 0; i < q[v].size(); i++)
            if (q[v][i] == 0)
                g[1] |= g[1] << sz[e[v][i]];
    }
    return ret;
}

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
    g[0][0] = 1;
    g[1][0] = 1;
    cin >> n >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        e[x - 1].push_back(i);
    }
    for (int i = 0; i < n; i++)
        q[i].resize(e[i].size());
    dfs(0);
    int szb, szc;
    for (int i = 0; i < e[0].size(); i++)
        if (rt[e[0][i]] == 0)
            g[0] |= g[0] << sz[e[0][i]], g[1] |= g[1] << sz[e[0][i]];
        else
        if (rt[e[0][i]] == 2)
            szb = sz[e[0][i]];
        else
        if (rt[e[0][i]] == 3)
            szc = sz[e[0][i]];
    if (sz[0] % 2 == 1){
        cout << "NO";
        return 0;
    }
    if ((sz[0] - 2) / 2 >= max(szb, szc) && g[0][(sz[0] - 2) / 2 - szb] && g[1][(sz[0] - 2) / 2 - szc])
        cout << "YES";
    else
        cout << "NO";
}