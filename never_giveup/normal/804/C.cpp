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

const ld EPS = 1e-9;

const int maxn = 5e5 + 100, inf = 1e9 + 100, sq = 300;

int n, m;

int col[maxn];

vector<int> q[maxn];

vector<int> e[maxn];

void dfs(int i, int par){
    vector<int> now;
    int cnt = 1;
    for (int j = 0; j < q[i].size(); j++)
        if (col[q[i][j]] > 0)
            now.push_back(col[q[i][j]]);
    sort(now.begin(), now.end());
    int it = 0;
    while (it < now.size()){
        if (now[it] < cnt)
            it++;
        else
        if (now[it] == cnt)
            it++, cnt++;
        else
            break;
    }
    for (int j = 0; j < q[i].size(); j++)
        if (col[q[i][j]] == 0){
            col[q[i][j]] = cnt;
            cnt++;
            while (it < now.size()){
                if (now[it] < cnt)
                    it++;
                else
                if (now[it] == cnt)
                    it++, cnt++;
                else
                    break;
            }
        }
    for (int kek = 0; kek < e[i].size(); kek++)
        if (e[i][kek] != par)
            dfs(e[i][kek], i);
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
    scanf("%d %d", &n, &m);
    int answer = 1;
    for (int i = 0; i < n; i++){
        int s;
        scanf("%d", &s);
        answer = max(answer, s);
        q[i].resize(s);
        for (int j = 0; j < s; j++){
            scanf("%d", &q[i][j]), q[i][j]--;
        }
    }
    for (int i = 1; i < n; i++){
        int v, u;
        scanf("%d %d", &v, &u);
        v--;
        u--;
        e[v].push_back(u);
        e[u].push_back(v);
    }
    dfs(0, -1);
    printf("%d\n", answer);
    for (int i = 0; i < m; i++)
        if (col[i] == 0)
            col[i] = 1;
    for (int i = 0; i < m; i++)
        printf("%d ", col[i]);
}