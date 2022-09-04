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

const int maxn = 2e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 100;

int n, zap;

int a[maxn];

int b[maxn];

ll answer[maxn];

vector<int> q[maxn], p[maxn];

int fen[maxn];

pair<pair<int, int>, pair<int, int> > quer[maxn];

int all;

void inc(int i, int v){
    for (; i < n; i = (i | (i + 1)))
        fen[i] += v;
    all += v;
}

int sum(int i){
    int v = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        v += fen[i];
    return v;
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
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%d%d", &n, &zap);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), a[i]--;
    for (int i = 0; i < zap; i++){
        scanf("%d%d%d%d", &quer[i].first.first, &quer[i].first.second, &quer[i].second.first, &quer[i].second.second);
        quer[i].first.first--;
        quer[i].first.second--;
        quer[i].second.first--;
        quer[i].second.second--;
        answer[i] = n * (ll)(n - 1) / 2 - quer[i].first.first * (ll)(quer[i].first.first - 1) / 2 - quer[i].first.second * (ll)(quer[i].first.second - 1) / 2 -
        (n - quer[i].second.first - 1) * (ll)(n - quer[i].second.first - 2) / 2 - (n - quer[i].second.second - 1) * (ll)(n - quer[i].second.second - 2) / 2;
        q[quer[i].first.first].push_back(i);
        p[quer[i].second.first].push_back(i);
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < q[i].size(); j++){
            int id = q[i][j];
            ll val = sum(quer[id].first.second - 1);
            answer[id] += val * (val - 1) / 2;
            val = all - sum(quer[id].second.second);
            answer[id] += val * (val - 1) / 2;
        }
        inc(a[i], 1);
    }
    for (int i = 0; i < n; i++)
        fen[i] = 0;
    all = 0;
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < p[i].size(); j++){
            int id = p[i][j];
            ll val = sum(quer[id].first.second - 1);
            answer[id] += val * (val - 1) / 2;
            val = all - sum(quer[id].second.second);
            answer[id] += val * (val - 1) / 2;
        }
        inc(a[i], 1);
    }
    for (int i = 0; i < zap; i++)
        printf("%I64d\n", answer[i]);
}