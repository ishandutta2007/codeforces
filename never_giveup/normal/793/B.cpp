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

const ll llinf = 1e18;

const int maxn = 1e3 + 10, inf = 1e9 + 100, sq = 300;

int n, m;

char c[maxn][maxn];

bool q[2][maxn];

int si, sj, fi, fj;

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
    for (int i = 0; i < n; i++){
        scanf("%s", c[i]);
        for (int j = 0; j < m; j++)
            if (c[i][j] == 'S')
                si = i, sj = j;
            else
            if (c[i][j] == 'T')
                fi = i, fj = j;
    }
    for (int i = si; i >= 0; i--)
        if (c[i][sj] == '*')
            break;
        else
            q[0][i] = 1;
    for (int i = si + 1; i < n; i++)
        if (c[i][sj] == '*')
            break;
        else
            q[0][i] = 1;
    for (int i = sj; i >= 0; i--)
        if (c[si][i] == '*')
            break;
        else
            q[1][i] = 1;
    for (int i = sj + 1; i < m; i++)
        if (c[si][i] == '*')
            break;
        else
            q[1][i] = 1;
    for (int i = fi; i >= 0; i--)
        if (c[i][fj] == '*')
            break;
        else
        if (q[0][i] == 1){
            bool ez = 1;
            for (int j = min(sj, fj); j <= max(sj, fj); j++)
            if (c[i][j] == '*'){
                ez = 0;
                break;
            }
            if (ez){
                printf("YES");
                return 0;
            }
        }
    for (int i = fi + 1; i < n; i++)
        if (c[i][fj] == '*')
            break;
        else
        if (q[0][i] == 1){
            bool ez = 1;
            for (int j = min(sj, fj); j <= max(sj, fj); j++)
            if (c[i][j] == '*'){
                ez = 0;
                break;
            }
            if (ez){
                printf("YES");
                return 0;
            }
        }
    for (int i = fj; i >= 0; i--)
        if (c[fi][i] == '*')
            break;
        else
        if (q[1][i]){
            bool ez = 1;
            for (int j = min(si, fi); j <= max(si, fi); j++)
            if (c[j][i] == '*'){
                ez = 0;
                break;
            }
            if (ez){
                printf("YES");
                return 0;
            }
        }
    for (int i = fj + 1; i < m; i++)
        if (c[fi][i] == '*')
            break;
        else
        if (q[1][i]){
            bool ez = 1;
            for (int j = min(si, fi); j <= max(si, fi); j++)
            if (c[j][i] == '*'){
                ez = 0;
                break;
            }
            if (ez){
                printf("YES");
                return 0;
            }
        }
    printf("NO");
}