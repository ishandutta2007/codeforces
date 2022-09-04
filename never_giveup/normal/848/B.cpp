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

const int maxn = 2e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7;

int n, W, H;

vector<int> g[maxn];

queue<int> w[maxn];

queue<int> def[maxn];

int answer[maxn];

pair<int, pair<int, int> > danc[maxn];

vector<pair<pair<int, int>, int> > q;

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
    cin >> n >> W >> H;
    for (int i = 0; i < n; i++){
        cin >> danc[i].first >> danc[i].second.first >> danc[i].second.second;
        if (danc[i].first == 1)
            q.push_back(make_pair(danc[i].second, i));
        else
            g[danc[i].second.second - danc[i].second.first + H].push_back(i);
        answer[i] = i;
    }
    for (int i = 0; i < maxn; i++)
    if (!g[i].empty()){
        vector<pair<int, int> > s(g[i].size());
        for (int j = 0; j < g[i].size(); j++)
            s[j] = make_pair(danc[g[i][j]].second.first, g[i][j]);
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        for (int j = 0; j < s.size(); j++)
            w[i].push(s[j].second), def[i].push(s[j].second);
    }
    sort(q.begin(), q.end());
    for (int i = 0; i < q.size(); i++){
        int id = q[i].first.second - q[i].first.first + H;
        if (id < 0 || g[id].empty())
            continue;
        answer[w[id].front()] = q[i].second;
        w[id].pop();
        w[id].push(q[i].second);
    }
    for (int i = 0; i < maxn; i++)
    if (!g[i].empty())
        for (int j = 0; j < g[i].size(); j++)
            answer[w[i].front()] = def[i].front(), def[i].pop(), w[i].pop();
    for (int i = 0; i < n; i++){
        int x = answer[i];
        if (danc[x].first == 1)
            cout << danc[x].second.first << ' ' << H << '\n';
        else
            cout << W << ' ' << danc[x].second.first << '\n';
    }
}