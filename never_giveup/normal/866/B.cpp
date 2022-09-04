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
#define int long long
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

int n;

int S;

pair<int, int> q[maxn];

pair<int, int> g[maxn];

pair<pair<int, int>, int> srt[maxn];

pair<ll, ll> sas[maxn];

ll answer;

int piz;

ll fir, sec;

void check(int cnt){
    ll a = cnt * (ll)S, b = (piz - cnt) * (ll)S;
    for (int i = 0; i < n; i++)
        g[i] = q[i];
    ll ans = 0;
    for (int i = 0; i < n && q[i].first >= 0 && a > 0; i++){
        ll x = min(a, (ll)g[i].second);
        g[i].second -= x;
        a -= x;
        ans += sas[srt[i].second].first * (ll)x;
    }
    for (int i = n - 1; i >= 0 && q[i].first <= 0 && b > 0; i--){
        ll x = min(b, (ll)g[i].second);
        g[i].second -= x;
        b -= x;
        ans += sas[srt[i].second].second * (ll)x;
    }
    if (a > 0){
        for (int i = 0; i < n; i++)
            if (g[i].second > 0)
                ans += sas[srt[i].second].first * (ll)g[i].second;
    }
    else{
        for (int i = 0; i < n; i++)
            if (g[i].second > 0)
                ans += sas[srt[i].second].second * (ll)g[i].second;
    }
    answer = max(answer, ans);
}

main()
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
    cin >> n >> S;
    ll sum = 0;
    for (int i = 0; i < n; i++){
        int a, b, s;
        cin >> s >> a >> b;
        sas[i] = make_pair(a, b);
        sum += s;
        q[i] = make_pair(a - b, s);
        srt[i] = make_pair(q[i], i);
    }
    sort(srt, srt + n);
    reverse(srt, srt + n);
    for (int i = 0; i < n; i++)
        q[i] = srt[i].first;
    piz = (sum + S - 1) / S;
    for (int i = 0; i < n; i++)
        if (q[i].first > 0)
            fir += q[i].second;
    sec = sum - fir;
    check(fir / S);
    check(min((ll)piz, fir / S + 1));
    cout << answer;
}