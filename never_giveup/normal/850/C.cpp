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

const int maxn = 5e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 100;
/*
ll answer = llinf;

int n;

ll X, Y;

int a[maxn];

vector<int> primes;

bitset<1000001> primelist;

void precalc(){
    for (int i = 2; i < 1000001; i++)
    if (!primelist[i]){
        primes.push_back(i);
        for (int j = i; j < 1000001; j += i)
            primelist[j] = 1;
    }
}*/

int n;

unordered_map<int, vector<int> > g;

unordered_map<int, int> dp;

int calc(int x){
    if (dp.find(x) == dp.end()){
        dp[x] = 0;
        bitset<32> now;
        for (int i = 0; i < 32; i++)
            now[i] = 0;
        for (int i = 1; (1 << i) <= x; i++)
            now[calc((x & ((1 << i) - 1)) | (x >> i))] = 1;
        for (int i = 0; i < 32; i++)
        if (!now[i]){
            dp[x] = i;
            break;
        }
    }
    return dp[x];
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*int xcpy, ycpy;
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
    Y = min(X, Y);
    precalc();*/
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        unordered_map<int, int> w;
        for (int j = 2; j <= sqrt(x); j++)
        while (x % j == 0)
            x /= j, w[j]++;
        if (x > 1)
            w[x]++;
        for (auto j : w)
            g[j.first].push_back(j.second);
    }
    int ans = 0;
    for (auto i : g){
        vector<int> q = i.second;
        q.push_back(0);
        sort(q.begin(), q.end());
        int w = 0;
        for (int i = 0; i < q.size(); i++)
            if (i == 0 || q[i] != q[i - 1])
                w += (1 << q[i]);
        ans ^= calc(w);
    }
    if (ans != 0)
        cout << "Mojtaba";
    else
        cout << "Arpa";
}