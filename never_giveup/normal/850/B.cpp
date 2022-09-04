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

const int maxn = 5e5 + 100, maxw = 1e6 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 100;

ll answer = llinf;

int n;

ll X, Y;

int a[maxn];

int p[maxw];

vector<int> primes;

void precalc(){
    for (int i = 2; i < maxw; i++){
        if (p[i] == 0){
            p[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && primes[j] <= p[i] && i * primes[j] < maxw; j++)
            p[i * primes[j]] = primes[j];
    }
}

int app[maxw], app1[maxw];

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
    int xcpy, ycpy;
    scanf("%d %d %d", &n, &xcpy, &ycpy);
    X = xcpy;
    Y = ycpy;
    int maxval = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]), maxval = max(maxval, a[i]);
    if (maxval == 1){
        cout << min(X, Y) * n;
        return 0;
    }
    answer = min(X, Y) * n;
    precalc();
    for (int i = 0; i < n; i++){
        int x = a[i];
        while (x > 1){
            int v = p[x];
            app[v]++;
            while (p[x] == v)
                x /= v;
        }
        x = a[i] + 1;
        while (x > 1){
            int v = p[x];
            app1[v]++;
            while (p[x] == v)
                x /= v;
        }
    }
    if (X <= Y){
        for (int i = 2; i < maxw; i++)
            answer = min(answer, (n - app[i]) * X);
    }
    else
    if (X <= 2 * Y){
        for (int i = 2; i < maxw; i++)
            answer = min(answer, (n - app[i] - app1[i]) * X + app1[i] * Y);
    }
    for (int i = 2; i < maxw; i++)
    if (app[i] + app1[i] >= n / 2){
        ll ans = 0;
        for (int j = 0; j < n; j++){
            int r = a[j] % i;
            if (r > 0)
                ans += min(X, Y * (i - r));
        }
        answer = min(answer, ans);
    }
    cout << answer;
}