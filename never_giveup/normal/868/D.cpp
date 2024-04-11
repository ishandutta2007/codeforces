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
#define mkp make_pair
//#define f first
//#define s second

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

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

const ll llinf = 2e18 + 100;

const ld EPS = 1e-9;

const ld PI = atan2(0, -1);

const int maxn = 1e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, sq = 6000, osq = 17;

const int k = 9;

bitset<(1 << k)> q[200][k];

string pref[200], suf[200];

int ans[200];

int n, quer;

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
    cin >> n;
    for (int it = 0; it < n; it++){
        string s;
        cin >> s;
        for (int i = 0; i < min(k, (int)s.size()); i++)
            pref[it].push_back(s[i]);
        for (int i = 0; i < min(k, (int)s.size()); i++)
            suf[it].push_back(s[s.size() - 1 - i]);
        for (int len = 1; len <= min(k, (int)s.size()); len++){
            for (int j = 0; j + len <= s.size(); j++){
                int val = 0;
                for (int i = 0; i < len; i++)
                    val = val * 2 + s[j + i] - 48;
                q[it][len - 1][val] = 1;
            }
        }
        int l = 0, r = k + 1;
        while (r - l > 1){
            int m = (l + r) / 2;
            bool is = 1;
            for (int i = 0; i < (1 << m); i++)
                if (!q[it][m - 1][i]){
                    is = 0;
                    break;
                }
            if (is)
                l = m;
            else
                r = m;
        }
        ans[it] = l;
    }
    cin >> quer;
    for (int it = n; it < n + quer; it++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < (1 << (i + 1)); j++)
                q[it][i][j] = q[x][i][j] | q[y][i][j];
        ans[it] = max(ans[x], ans[y]);
        if (pref[x].size() == k)
            pref[it] = pref[x];
        else{
            pref[it] = pref[x];
            for (int i = 0; pref[it].size() < k && i < pref[y].size(); i++)
                pref[it].push_back(pref[y][i]);
        }
        if (suf[y].size() == k)
            suf[it] = suf[y];
        else{
            suf[it] = suf[y];
            for (int i = 0; suf[it].size() < k && i < suf[x].size(); i++)
                suf[it].push_back(suf[x][i]);
        }
        string w = suf[x], g = pref[y];
        reverse(w.begin(), w.end());
        for (int len = 1; len <= min(k, (int)(w.size() + g.size())); len++){
            for (int s = 1; s < min((int)w.size() + 1, len); s++)
            if (len - s <= g.size()){
                int val = 0;
                for (int i = w.size() - s; i < w.size(); i++)
                    val = val * 2 + w[i] - 48;
                for (int i = 0; i < len - s; i++)
                    val = val * 2 + g[i] - 48;
                q[it][len - 1][val] = 1;
            }
        }
        int l = ans[it], r = k + 1;
        while (r - l > 1){
            int m = (l + r) / 2;
            bool is = 1;
            for (int i = 0; i < (1 << m); i++)
                if (!q[it][m - 1][i]){
                    is = 0;
                    break;
                }
            if (is)
                l = m;
            else
                r = m;
        }
        ans[it] = l;
        cout << ans[it] << '\n';
    }
}